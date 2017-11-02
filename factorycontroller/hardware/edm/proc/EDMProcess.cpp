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


oldportal::fc::hardware::edm::proc::EDMProcess::EDMProcess()

{//BEGIN_dbfc1d2d01ecf65f29c4ca7a2983d589

}//END_dbfc1d2d01ecf65f29c4ca7a2983d589



oldportal::fc::hardware::edm::proc::EDMProcess::~EDMProcess()
{//BEGIN_3c2ade6eb8653d9a68e6fe780c8b171f

}//END_3c2ade6eb8653d9a68e6fe780c8b171f


void oldportal::fc::hardware::edm::proc::EDMProcess::forceStop()
{//BEGIN_aabac4dfa8ca3c4484fe1c1687c83513
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
}//END_aabac4dfa8ca3c4484fe1c1687c83513

void oldportal::fc::hardware::edm::proc::EDMProcess::onProcessed()
{//BEGIN_f07b30396b1adb27c635a9e6f593b37f
    // empty
}//END_f07b30396b1adb27c635a9e6f593b37f

void oldportal::fc::hardware::edm::proc::EDMProcess::start()
{//BEGIN_f7b40599a51c2d60b2f7830fd52fc6ea
    oldportal::fc::hardware::HardwareDeviceProcess::start();

    LOG4CXX_DEBUG(logger, "Process EDM start() call");
}//END_f7b40599a51c2d60b2f7830fd52fc6ea


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE