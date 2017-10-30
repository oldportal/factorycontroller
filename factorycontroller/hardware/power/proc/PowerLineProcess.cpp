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


oldportal::fc::hardware::power::proc::PowerLineProcess::PowerLineProcess()

{//BEGIN_41ede663115a95af76102ba194646135

}//END_41ede663115a95af76102ba194646135



oldportal::fc::hardware::power::proc::PowerLineProcess::~PowerLineProcess()
{//BEGIN_ff1305f8db20ab31edbb763bd2538336

}//END_ff1305f8db20ab31edbb763bd2538336


void oldportal::fc::hardware::power::proc::PowerLineProcess::forceStop()
{//BEGIN_80e0b2fb3b5cb6926e40e090f295f4ba
    // stop any mechanical motion on devices
    for (uint32_t i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired() && "unvalid pointer to device");
        auto device = _hardware_devices[i].lock();
        // stop device
        std::shared_ptr<oldportal::fc::hardware::HardwareDeviceProcess> process = shared_from_this();
        auto command = std::make_shared<oldportal::fc::hardware::welding::command::StopWelding>(device, process);
        device->_network.lock()->_controller.lock()->pushCommand(command);
    }
    // the process is canceled by software call
    _process_state = PROCESS_STATE::CANCELED;
}//END_80e0b2fb3b5cb6926e40e090f295f4ba

void oldportal::fc::hardware::power::proc::PowerLineProcess::onProcessed()
{//BEGIN_ea53218352412d16ecf36b4b77edd2ae
    // empty
}//END_ea53218352412d16ecf36b4b77edd2ae

void oldportal::fc::hardware::power::proc::PowerLineProcess::start()
{//BEGIN_064ada679a7beaed22351e305ddfe943
    oldportal::fc::hardware::HardwareDeviceProcess::start();

    LOG4CXX_DEBUG(logger, "Process Welding start() call");
}//END_064ada679a7beaed22351e305ddfe943


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE