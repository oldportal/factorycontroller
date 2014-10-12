/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*    
*    factorycontroller is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusTCPIPNetworkController::ModbusTCPIPNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::modbus::ModbusNetworkController(network)
{//BEGIN_da7390f47b64c6919e1ad8426b698765
    assert(network && "ModbusNetworkController cannot be initialized with empty Network");

    _run_thread_cycle_flag = false;
    _close_interrupted_flag = false;
    _network = network;

    _modbus_ctx = nullptr;
    _last_time_synchronization = std::chrono::high_resolution_clock::time_point::min();
}//END_da7390f47b64c6919e1ad8426b698765



oldportal::fc::network::modbus::ModbusTCPIPNetworkController::~ModbusTCPIPNetworkController()
{//BEGIN_c14b688eeb561dc50dd75338cfd271b1

}//END_c14b688eeb561dc50dd75338cfd271b1


void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::close()
{//BEGIN_65a8663699173cdad93ef707f8be35f1
    // close() : empty
}//END_65a8663699173cdad93ef707f8be35f1

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::closeModbusContext()
{//BEGIN_8c5d012dfd029193fb817d2a6854046b
    if (_modbus_ctx != nullptr)
    {
        modbus_close(_modbus_ctx);
        modbus_free(_modbus_ctx);

        _modbus_ctx = nullptr;
    }
}//END_8c5d012dfd029193fb817d2a6854046b

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::initHardware()
{//BEGIN_f919d3d7379153553fbea5b0aa2a6cd5
    assert(_modbus_ctx == nullptr && "TestNetworkController must be closed with close() before new initHardware() call");

    // init network time
    _network_time.init();

    std::string address = oldportal::fc::system::util::utf16_to_utf8(_address_settings._ip_address);

    _modbus_ctx = modbus_new_tcp(address.c_str(), _address_settings._port_number);

    if (_modbus_ctx == nullptr)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::initHardware() TCPIP port open error");
        oldportal::fc::system::logger::error(modbus_strerror(errno));
        closeModbusContext();
        return;
    }

    if (modbus_connect(_modbus_ctx) != 0)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::initHardware() TCPIP connect error");
        oldportal::fc::system::logger::error(modbus_strerror(errno));
        closeModbusContext();
        return;
    }

    struct timeval new_response_timeout;
    new_response_timeout.tv_sec = 0;
    new_response_timeout.tv_usec = _network_settings._response_timeout_usec;
    modbus_set_response_timeout(_modbus_ctx, &new_response_timeout);

    struct timeval new_byte_timeout;
    new_byte_timeout.tv_sec = 0;
    new_byte_timeout.tv_usec = _network_settings._byte_timeout_usec;
    modbus_set_byte_timeout(_modbus_ctx, &new_byte_timeout);

    oldportal::fc::system::logger::log(u8"oldportal::fc::network::test::TestNetworkController::initHardware() TCPIP port opened");

    // start soft realtime thread
    _run_thread_cycle_flag = true;
    _close_interrupted_flag = false;
    _realtime_thread = std::make_shared<std::thread>(oldportal::fc::network::modbus::ModbusTCPIPNetworkController::realtime_run, this);

    // set realtime thread priority
#ifdef WIN32
    // WIN API
    // HIGH_PRIORITY_CLASS->REALTIME_PRIORITY_CLASS
    if (!SetPriorityClass(_realtime_thread->native_handle(), HIGH_PRIORITY_CLASS))
    // THREAD_PRIORITY_NORMAL->THREAD_PRIORITY_HIGHEST->THREAD_PRIORITY_TIME_CRITICAL
    if (!SetThreadPriority(_realtime_thread->native_handle(), THREAD_PRIORITY_TIME_CRITICAL))
    {
        DWORD dwError = GetLastError();
        std::cout << "cannot set modbus thread priority, error: " << dwError;
    }
#else // POSIX thread
    // pthread library
    int policy;
    struct sched_param param;

    pthread_getschedparam(_realtime_thread->native_handle(), &policy, &param);
    // you would use policies SCHED_FIFO, SCHED_RR where you can specify HIGH priority of thread
    policy = SCHED_RR;
    param.sched_priority = sched_get_priority_max(policy);
    pthread_setschedparam(_realtime_thread->native_handle(), policy, &param);
#endif
}//END_f919d3d7379153553fbea5b0aa2a6cd5

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::pingDevicesStep()
{//BEGIN_a146e249b08301984a9e69b7b3b29d0a
    // ping unused actively devices (update devices state)

    auto now_time_point = std::chrono::high_resolution_clock::now();

    for (auto& device : _network->_devices )
    {
        auto last_response = device->getLastResponse();
        auto last_ping = device->getLastPing();

        if (last_response + std::chrono::milliseconds(_network_settings._device_update_state_interval_msec) > now_time_point)
            if (last_ping + std::chrono::milliseconds(_network_settings._device_update_state_interval_msec) > now_time_point)
            {
                device->updateLastPing();

                // insert update state (=ping) command
                auto hardware_device = std::dynamic_pointer_cast<oldportal::fc::hardware::HardwareDevice>(device);

                if (!hardware_device)
                    continue;// ping commands only for hardware device instances

                auto command = std::make_shared<oldportal::fc::network::command::DeviceStateReport>(hardware_device);
                pushCommand(command);

                // maximum 1 device per step, if device timepout passed (keep network low-loaded)
                return;
            }
    }
}//END_a146e249b08301984a9e69b7b3b29d0a

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::processDeviceCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_20af3dcabca3af7b1a1b62955a6d0161
    // runtime check for modbus command
    std::shared_ptr<oldportal::fc::network::modbus::ModbusDeviceCommand> modbus_command = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusDeviceCommand>(command);
    assert(modbus_command);

    if (!modbus_command)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::processDeviceCommand(command) - RTTI error, object bust inherit ModbusDeviceCommand");

        return;
    }

    modbus_command->_modbus_ctx = getModbusContext();

    try
    {
        // process request->response
        modbus_command->process();

        // update device last response time
        if (modbus_command->_device)
        {
            modbus_command->_device->updateLastResponse();
        }
    }
    catch (std::exception& ex)
    {
        oldportal::fc::system::logger::error_hardware("MODBUS command process exception", ex.what());
        // add error to statistics
    }

    // clear command context
    modbus_command->_modbus_ctx = nullptr;
}//END_20af3dcabca3af7b1a1b62955a6d0161

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_da7db483ed044ae2805cd25e338de658
    // runtime check for modbus command
    std::shared_ptr<oldportal::fc::network::modbus::ModbusDeviceCommand> modbus_command = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusDeviceCommand>(command);
    assert(modbus_command && "pushCommand() - must be oldportal::fc::network::modbus::ModbusDeviceCommand instance");
    if (!modbus_command)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::pushCommand(command) - command must inherit ModbusDeviceCommand");
        // dynamic error process
        throw std::invalid_argument("pushCommand() - must be oldportal::fc::network::modbus::ModbusDeviceCommand instance");
    }

    // check pointer to this controller
    if (modbus_command->_controller)
    {
        std::shared_ptr<oldportal::fc::network::modbus::ModbusTCPIPNetworkController> modbus_controller = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusTCPIPNetworkController>(modbus_command->_controller);
        assert(modbus_controller && "command->_controller must inherit ModbusNetworkController");
        if (!modbus_controller)
        {
            oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::pushCommand(command) - command->_controller must inherit TestNetworkController");
            // dynamic error process
            throw std::invalid_argument("pushCommand() - command->_controller must be oldportal::fc::network::test::TestNetworkController instance");
        }

        assert(modbus_controller.get() == this && "pushCommand(command) - command->_controller not set to this TestNetworkController");
        if (modbus_controller.get() != this)
        {
            oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::pushCommand(command) - command->_controller not set to this TestNetworkController");
            // dynamic error process
            throw std::invalid_argument("pushCommand(command) - command->_controller not set to this TestNetworkController");
        }
    }

    // parent class function call
    oldportal::fc::network::NetworkController::pushCommand(command);
}//END_da7db483ed044ae2805cd25e338de658

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::realtime_run(oldportal::fc::network::modbus::ModbusTCPIPNetworkController* controller)
{//BEGIN_f1d3cfab80749d628578926e1da0ff27
    assert(controller);

    if (controller->_modbus_ctx == nullptr)
    {
        //TODO: report error as error status
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::test::TestNetworkController::realtime_run() ERROR - serial port is not opened, thread stopping...");

        return;
    }

    oldportal::fc::system::logger::log(u8"oldportal::fc::network::test::TestNetworkController::realtime_run() realtime thread started");

    while (controller->_run_thread_cycle_flag)
    {
        // main work, process messages
        while (!controller->_command_queue.empty())
        {
            std::shared_ptr<oldportal::fc::network::DeviceCommand> command;

            {
                // pop command with mutex lock
                std::lock_guard<std::recursive_mutex> lock(controller->_command_queue_lock);
                command = controller->_command_queue.front();
                controller->_command_queue.pop();
            }

            // process command real-time part:
            controller->processDeviceCommand(command);

            {
                // push command to back queue with mutex lock
                std::lock_guard<std::recursive_mutex> lock(controller->_command_queue_lock);
                controller->_command_back_queue.push(command);
            }
        }

        // check for interruption and closing
        if (controller->_close_interrupted_flag)
        {
            // default thread exit
            oldportal::fc::system::logger::log(u8"oldportal::fc::network::test::TestNetworkController::realtime_run() thread stopping...");
            controller->_run_thread_cycle_flag = false;
            controller->closeModbusContext();
            oldportal::fc::system::logger::log(u8"oldportal::fc::network::test::TestNetworkController::realtime_run() thread stopped");
            return;
        }

        // sleep with chrono
        std::chrono::milliseconds sleep_duration( 1 );
        std::this_thread::sleep_for( sleep_duration );
    }

    // unexpected exit, the threas should exit with controller->_close_interrupted_flag = true
    controller->closeModbusContext();
    oldportal::fc::system::logger::log(u8"oldportal::fc::network::test::TestNetworkController::realtime_run() thread stopped");
}//END_f1d3cfab80749d628578926e1da0ff27

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::step()
{//BEGIN_0dfe25b988906585ef99118c290f55f7
    oldportal::fc::network::NetworkController::step();
}//END_0dfe25b988906585ef99118c290f55f7

void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::timeSynchronizationStep()
{//BEGIN_1be996297f3c0eae8a801d1ff1648a82
    // check for last system time synchronization deadline
    if (_last_time_synchronization + std::chrono::milliseconds(_network_settings._network_time_sync_interval_msec) > std::chrono::high_resolution_clock::now())
    {
        _last_time_synchronization = std::chrono::high_resolution_clock::now();

        // insert synchronization command
        auto command = std::make_shared<oldportal::fc::network::command::NetworkTimeSynchronization>();
        pushCommand(command);
    }
}//END_1be996297f3c0eae8a801d1ff1648a82


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
