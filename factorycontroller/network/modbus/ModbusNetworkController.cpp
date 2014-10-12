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

{//BEGIN_cd00ac92443e7f306587c174a17982c5
    _run_thread_cycle_flag = false;
    _close_interrupted_flag = false;

    _modbus_ctx = nullptr;
    _last_time_synchronization = std::chrono::high_resolution_clock::time_point::min();
}//END_cd00ac92443e7f306587c174a17982c5

oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::NetworkController(network)
{//BEGIN_395dabaf1dd0f55f10296bd3b44a1eff
    assert(network && "ModbusNetworkController cannot be initialized with empty Network");

    _run_thread_cycle_flag = false;
    _close_interrupted_flag = false;
    _network = network;

    _modbus_ctx = nullptr;
    _last_time_synchronization = std::chrono::high_resolution_clock::time_point::min();
}//END_395dabaf1dd0f55f10296bd3b44a1eff



oldportal::fc::network::modbus::ModbusNetworkController::~ModbusNetworkController()
{//BEGIN_3c4678448d8da5178c82745c442437c5
    _run_thread_cycle_flag = false;
    _close_interrupted_flag = true;

    closeModbusContext();
}//END_3c4678448d8da5178c82745c442437c5


void oldportal::fc::network::modbus::ModbusNetworkController::close()
{//BEGIN_0b68cbaba9eab80fc79d1462a1740f71
    _close_interrupted_flag = true;
    closeModbusContext();

    oldportal::fc::network::NetworkController::close();
}//END_0b68cbaba9eab80fc79d1462a1740f71

void oldportal::fc::network::modbus::ModbusNetworkController::closeModbusContext()
{//BEGIN_ed62e985906ed4e86994909533a6a0ae
    if (_modbus_ctx != nullptr)
    {
        modbus_close(_modbus_ctx);
        modbus_free(_modbus_ctx);

        _modbus_ctx = nullptr;
    }
}//END_ed62e985906ed4e86994909533a6a0ae

modbus_t* oldportal::fc::network::modbus::ModbusNetworkController::getModbusContext()
{//BEGIN_da23bdb87d3f2a0a04861da4574a4bb7
    return _modbus_ctx;
}//END_da23bdb87d3f2a0a04861da4574a4bb7


bool oldportal::fc::network::modbus::ModbusNetworkController::isOpened()
{//BEGIN_be54a7540bed925c6d6f274a683353e8
    return _modbus_ctx != nullptr && _realtime_thread;
}//END_be54a7540bed925c6d6f274a683353e8

void oldportal::fc::network::modbus::ModbusNetworkController::pingDevicesStep()
{//BEGIN_49445c0a1f2dc10fff596fc5d2a31eec
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
}//END_49445c0a1f2dc10fff596fc5d2a31eec

void oldportal::fc::network::modbus::ModbusNetworkController::processDeviceCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_cb8fd5b980bc7603de060be0feb37eed
    // runtime check for modbus command
    std::shared_ptr<oldportal::fc::network::modbus::ModbusDeviceCommand> modbus_command = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusDeviceCommand>(command);
    assert(modbus_command);

    if (!modbus_command)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::processDeviceCommand(command) - RTTI error, object bust inherit ModbusDeviceCommand");

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
}//END_cb8fd5b980bc7603de060be0feb37eed

void oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_3663c08fced66ad2a61a9dbc07f868ae
    // runtime check for modbus command
    std::shared_ptr<oldportal::fc::network::modbus::ModbusDeviceCommand> modbus_command = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusDeviceCommand>(command);
    assert(modbus_command && "pushCommand() - must be oldportal::fc::network::modbus::ModbusDeviceCommand instance");
    if (!modbus_command)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(command) - command must inherit ModbusDeviceCommand");
        // dynamic error process
        throw std::invalid_argument("pushCommand() - must be oldportal::fc::network::modbus::ModbusDeviceCommand instance");
    }

    // check pointer to this controller
    if (modbus_command->_controller)
    {
        std::shared_ptr<oldportal::fc::network::modbus::ModbusNetworkController> modbus_controller = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusNetworkController>(modbus_command->_controller);
        assert(modbus_controller && "command->_controller must inherit ModbusNetworkController");
        if (!modbus_controller)
        {
            oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(command) - command->_controller must inherit ModbusNetworkController");
            // dynamic error process
            throw std::invalid_argument("pushCommand() - command->_controller must be oldportal::fc::network::modbus::ModbusNetworkController instance");
        }

        assert(modbus_controller.get() == this && "pushCommand(command) - command->_controller not set to this ModbusNetworkController");
        if (modbus_controller.get() != this)
        {
            oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusNetworkController::pushCommand(command) - command->_controller not set to this ModbusNetworkController");
            // dynamic error process
            throw std::invalid_argument("pushCommand(command) - command->_controller not set to this ModbusNetworkController");
        }
    }

    // parent class function call
    oldportal::fc::network::NetworkController::pushCommand(command);
}//END_3663c08fced66ad2a61a9dbc07f868ae

void oldportal::fc::network::modbus::ModbusNetworkController::realtime_run(oldportal::fc::network::modbus::ModbusNetworkController* controller)
{//BEGIN_92de8593a2dab2b10e17272d29b47493
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
}//END_92de8593a2dab2b10e17272d29b47493

void oldportal::fc::network::modbus::ModbusNetworkController::step()
{//BEGIN_098807b48ba62b9baf8eaed28095384e
    // parent class call
    oldportal::fc::network::NetworkController::step();

    // check for last system time synchronization deadline
    timeSynchronizationStep();

    // ping unused actively devices (update devices state)
    pingDevicesStep();
}//END_098807b48ba62b9baf8eaed28095384e

void oldportal::fc::network::modbus::ModbusNetworkController::timeSynchronizationStep()
{//BEGIN_982c99b2d25d29e138dc4a91edb623c5
    // check for last system time synchronization deadline
    if (_last_time_synchronization + std::chrono::milliseconds(_network_settings._network_time_sync_interval_msec) > std::chrono::high_resolution_clock::now())
    {
        _last_time_synchronization = std::chrono::high_resolution_clock::now();

        // insert synchronization command
        auto command = std::make_shared<oldportal::fc::network::command::NetworkTimeSynchronization>();
        pushCommand(command);
    }
}//END_982c99b2d25d29e138dc4a91edb623c5


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE