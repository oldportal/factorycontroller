/*
*    This file is part of FactoryController project.
*    
*    FactoryController is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    FactoryController is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2016
*    dmogn@mail.ru
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::fc::hardware::mechatronics::proc::LinearMotion::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::proc::LinearMotion";


oldportal::fc::hardware::mechatronics::proc::LinearMotion::LinearMotion()

{//BEGIN_88c48fa45a4810f1275e31c51d5281d3

}//END_88c48fa45a4810f1275e31c51d5281d3


void oldportal::fc::hardware::mechatronics::proc::LinearMotion::onProcessed()
{//BEGIN_97e29e5b2637a120da1ee1492336e9c4
    // empty
}//END_97e29e5b2637a120da1ee1492336e9c4

void oldportal::fc::hardware::mechatronics::proc::LinearMotion::start()
{//BEGIN_84d3ab554b9e52aefa0b7f598c73162f
    oldportal::fc::hardware::mechatronics::proc::Motion::start();

    LOG4CXX_DEBUG(logger, "Process LinearMotion start() call, speed: " << _speed);

    _process_state = PROCESS_STATE::START;
    // nothing

    _process_state = PROCESS_STATE::INITIALIZATION;

    for (uint32_t i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired() && "unvalid pointer to device");
        auto device = _hardware_devices[i].lock();
        // check - is device active?
        auto lastResponse = device->getLastResponse();
        // TODO: check interval for timeout

        // update device state
        auto pingCommand = std::make_shared<oldportal::fc::network::command::DeviceStateReport>(device);
        device->_network.lock()->_controller.lock()->pushCommand(pingCommand);
    }
    _process_state = PROCESS_STATE::INITIALIZED;

    for (uint32_t i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired() && "unvalid pointer to device");
        auto device = _hardware_devices[i].lock();
        // init device
        std::shared_ptr<oldportal::fc::hardware::HardwareDeviceProcess> process = shared_from_this();
        auto command = std::make_shared<oldportal::fc::hardware::mechatronics::command::LinearMotion>(device, process, _speed);
        device->_network.lock()->_controller.lock()->pushCommand(command);
    }

    _hardware_initialized = true;
}//END_84d3ab554b9e52aefa0b7f598c73162f

void oldportal::fc::hardware::mechatronics::proc::LinearMotion::step()
{//BEGIN_9f3fb12afa693ca925a2a5dab2ad5102
    oldportal::fc::hardware::HardwareDeviceProcess::step();

    // state-machine phase actions:
    switch (_process_state)
    {
        case PROCESS_STATE::START:
            // nothing
            break;
        case PROCESS_STATE::INITIALIZATION:
            break;
        case PROCESS_STATE::INITIALIZED:
            break;
        case PROCESS_STATE::PROCESS:
            break;
        case PROCESS_STATE::PROCESSED:
            // nothing
            return;
            break;
        case PROCESS_STATE::CANCELED:
            // nothing
            return;
            break;
        case PROCESS_STATE::FAILURED:
            // nothing
            return;
            break;
        default:
        LOG4CXX_ERROR(logger, "unknown process state");
    }

    // is hardware initialized?
    if (!is_hardware_initialized())
    {
        // error: hardware should be initialized with start() call first.
        LOG4CXX_ERROR(logger, "hardware should be initialized with start() call first");
    }

    //TODO: is hardware switched to command mode?

    //TODO: estimate next hardware check
    //TODO: check and correct harware
    for (uint32_t i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired() && "unvalid pointer to device");
        auto device = _hardware_devices[i].lock();
        //auto getMotionCommand = std::make_shared<oldportal::fc::hardware::mechatronics::command::GetMotionState>(device);
        //device->_network.lock()->_controller.lock()->pushCommand(getMotionCommand);
    }

    //TODO: detect & process process end
    //TODO: callback task for detect & process task end
}//END_9f3fb12afa693ca925a2a5dab2ad5102


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE