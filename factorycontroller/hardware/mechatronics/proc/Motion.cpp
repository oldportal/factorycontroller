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


oldportal::fc::hardware::mechatronics::proc::Motion::Motion()

{//BEGIN_302962d168708f339e919889010e639e

}//END_302962d168708f339e919889010e639e



oldportal::fc::hardware::mechatronics::proc::Motion::~Motion()
{//BEGIN_986c1c1c2cba4b6e55600094ee0e76f5

}//END_986c1c1c2cba4b6e55600094ee0e76f5


void oldportal::fc::hardware::mechatronics::proc::Motion::forceStop()
{//BEGIN_37593e8ee68671d0b80f833a9a360e98
    // stop any mechanical motion on devices
    for (uint32_t i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired() && "unvalid pointer to device");
        auto device = _hardware_devices[i].lock();
        // stop device
        std::shared_ptr<oldportal::fc::hardware::HardwareDeviceProcess> process = shared_from_this();
        auto command = std::make_shared<oldportal::fc::hardware::mechatronics::command::StopMotion>(device, process);
        device->_network.lock()->_controller.lock()->pushCommand(command);
    }
    // the process is canceled by software call
    _process_state = PROCESS_STATE::CANCELED;
}//END_37593e8ee68671d0b80f833a9a360e98

void oldportal::fc::hardware::mechatronics::proc::Motion::onProcessed()
{//BEGIN_830a5b07fab3e79d3bc11703e3ec23b8
    // empty
}//END_830a5b07fab3e79d3bc11703e3ec23b8

void oldportal::fc::hardware::mechatronics::proc::Motion::start()
{//BEGIN_93a5e4b99ae59243f42dd56ed406a586
    oldportal::fc::hardware::HardwareDeviceProcess::start();

    LOG4CXX_DEBUG(logger, "Process Motion start() call");
}//END_93a5e4b99ae59243f42dd56ed406a586


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
