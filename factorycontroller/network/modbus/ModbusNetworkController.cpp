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


oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController()

{//BEGIN_1540738fb4e875afede8ad1c3eb3677c
    _run_thread_cycle_flag = false;
    _close_interrupted_flag = false;
}//END_1540738fb4e875afede8ad1c3eb3677c

oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::NetworkController(network)
{//BEGIN_17140ab021ca3f2bd11e039871242a38
    assert(network && "ModbusNetworkController cannot be initialized with empty Network");

    _run_thread_cycle_flag = false;
    _close_interrupted_flag = false;
    _network = network;

    _modbus_ctx = nullptr;
}//END_17140ab021ca3f2bd11e039871242a38



oldportal::fc::network::modbus::ModbusNetworkController::~ModbusNetworkController()
{//BEGIN_10f48711bd06cd04d26eed80dc27d4e2
    _run_thread_cycle_flag = false;
    _close_interrupted_flag = true;

    closeModbusContext();
}//END_10f48711bd06cd04d26eed80dc27d4e2


void oldportal::fc::network::modbus::ModbusNetworkController::close()
{//BEGIN_167ba3f506ed978ecd007619040b2c88
    _close_interrupted_flag = true;
    closeModbusContext();

    oldportal::fc::network::NetworkController::close();
}//END_167ba3f506ed978ecd007619040b2c88

void oldportal::fc::network::modbus::ModbusNetworkController::closeModbusContext()
{//BEGIN_8cc827bd3b715fdc5ddd2337eb7bb9b7
    if (_modbus_ctx != nullptr)
    {
        modbus_close(_modbus_ctx);
        modbus_free(_modbus_ctx);

        _modbus_ctx = nullptr;
    }
}//END_8cc827bd3b715fdc5ddd2337eb7bb9b7

modbus_t* oldportal::fc::network::modbus::ModbusNetworkController::getModbusContext()
{//BEGIN_1a64478473d63071e22cd7199aff31ff
    return _modbus_ctx;
}//END_1a64478473d63071e22cd7199aff31ff

void oldportal::fc::network::modbus::ModbusNetworkController::initHardware()
{//BEGIN_803ad91ba2984c5f99212c75897a3c72
    assert(_modbus_ctx == nullptr && "ModbusNetworkController must be closed with close() before new initHardware() call");

    // init network time
    _network_time.init();

    // settings example
    /*Set up arrays with the different possibilities for communications parameters */
    // port_name "/dev/ttyAMA0", "/dev/ttyUSB0"
    //int baud_rates[12] = {110, 300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400};
    //char parity[3] = {'N', 'E', 'O'};
    //int databits[2] ={7, 8};
    //int stopbits[2] = {1, 2};

    // set serial port name and settings
    _modbus_ctx = modbus_new_rtu(_port_settings._port_name.c_str(), _port_settings._baud_rate, _port_settings._parity, _port_settings._databits, _port_settings._stopbits);

    if (_modbus_ctx == NULL)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::initHardware() serial port create context error");
    }

    //Enable debugging for tests
    // modbus_set_debug(mb,TRUE);

    modbus_rtu_set_serial_mode(_modbus_ctx, MODBUS_RTU_RS485);
    // set to send request state
    //modbus_rtu_set_rts(_modbus_ctx, MODBUS_RTU_RTS_UP);

    if (modbus_connect(_modbus_ctx) != 0)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::initHardware() serial port open error");
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

    // set destination address
    if (modbus_set_slave(_modbus_ctx, MODBUS_BROADCAST_ADDRESS) != 0)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::initHardware() serial port set device address error");
        oldportal::fc::system::logger::error(modbus_strerror(errno));
        closeModbusContext();
        return;
    }

    oldportal::fc::system::logger::log(u8"oldportal::fc::network::modbus::ModbusNetworkController::initHardware() serial port opened");

    // start soft realtime thread
    _run_thread_cycle_flag = true;
    _close_interrupted_flag = false;
    _realtime_thread = std::make_shared<std::thread>(oldportal::fc::network::modbus::ModbusNetworkController::realtime_run, this);

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
}//END_803ad91ba2984c5f99212c75897a3c72

bool oldportal::fc::network::modbus::ModbusNetworkController::isOpened()
{//BEGIN_ce9e0665a989f6bbf012e31384526717
    return _modbus_ctx != nullptr && _realtime_thread;
}//END_ce9e0665a989f6bbf012e31384526717

void oldportal::fc::network::modbus::ModbusNetworkController::processDeviceCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_079bd15ede78f816935638b9f4abdb08
    // runtime check for modbus command
    std::shared_ptr<oldportal::fc::network::modbus::ModbusDeviceCommand> modbus_command = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusDeviceCommand>(command);
    assert(modbus_command);
    if (!modbus_command) {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::processDeviceCommand(command) - RTTI error, object bust inherit ModbusDeviceCommand");

        return;
    }

    modbus_command->_modbus_ctx = getModbusContext();

    // process request->response
    modbus_command->process();

    // clear command context
    modbus_command->_modbus_ctx = nullptr;

}//END_079bd15ede78f816935638b9f4abdb08

void oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_ffdc0eba50937a0a0c606b1972bc444e
    // runtime check for modbus command
    std::shared_ptr<oldportal::fc::network::modbus::ModbusDeviceCommand> modbus_command = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusDeviceCommand>(command);
    assert(modbus_command);
    if (!modbus_command)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(command) - RTTI error, command must inherit ModbusDeviceCommand");
        //TODO: dynamic error process
        return;
    }

    std::shared_ptr<oldportal::fc::network::modbus::ModbusNetworkController> modbus_controller = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusNetworkController>(modbus_command->_controller);
    assert(modbus_controller);
    if (!modbus_controller)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(command) - RTTI error, command->_controller must inherit ModbusNetworkController");
        //TODO: dynamic error process
        return;
    }

    assert(modbus_controller.get() == this);
    if (modbus_controller.get() != this)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(command) - command->_controller set not to this ModbusNetworkController");
        //TODO: dynamic error process
        return;
    }

    // parent class function call
    oldportal::fc::network::NetworkController::pushCommand(command);
}//END_ffdc0eba50937a0a0c606b1972bc444e

void oldportal::fc::network::modbus::ModbusNetworkController::realtime_run(oldportal::fc::network::modbus::ModbusNetworkController* controller)
{//BEGIN_de81e20cb5afc7c60970dd4c25f3f0ac
    assert(controller);

    if (controller->_modbus_ctx == nullptr)
    {
        //TODO: report error as error status
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() ERROR - serial port is not opened, thread stopping...");

        return;
    }

    oldportal::fc::system::logger::log(u8"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() realtime thread started");

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
            oldportal::fc::system::logger::log(u8"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() thread stopping...");
            controller->_run_thread_cycle_flag = false;
            controller->closeModbusContext();
            oldportal::fc::system::logger::log(u8"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() thread stopped");
            return;
        }

        // sleep with chrono
        std::chrono::milliseconds sleep_duration( 1 );
        std::this_thread::sleep_for( sleep_duration );
    }

    // unexpected exit, the threas should exit with controller->_close_interrupted_flag = true
    controller->closeModbusContext();
    oldportal::fc::system::logger::log(u8"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() thread stopped");
}//END_de81e20cb5afc7c60970dd4c25f3f0ac

void oldportal::fc::network::modbus::ModbusNetworkController::step()
{//BEGIN_342546856c9e2b6aaccaec98c99c43a9
    // parent class call
    oldportal::fc::network::NetworkController::step();

    // TODO: check for last system time update deadline

    // TODO: ping unused actively devices (update devices state)
}//END_342546856c9e2b6aaccaec98c99c43a9


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
