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


const char* const  oldportal::fc::hardware::welding::proc::WeldingProcess::_CLASSNAME_FULL = "oldportal::fc::hardware::welding::proc::WeldingProcess";


oldportal::fc::hardware::welding::proc::WeldingProcess::WeldingProcess()

{//BEGIN_ba61c4d20e9c0d938f1ac1009132204c

}//END_ba61c4d20e9c0d938f1ac1009132204c



oldportal::fc::hardware::welding::proc::WeldingProcess::~WeldingProcess()
{//BEGIN_c86663b5c02d59030aac3f15b72bd576

}//END_c86663b5c02d59030aac3f15b72bd576


void oldportal::fc::hardware::welding::proc::WeldingProcess::forceStop()
{//BEGIN_61f9ee7f43b074a018f7a1f977dff326
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
}//END_61f9ee7f43b074a018f7a1f977dff326

void oldportal::fc::hardware::welding::proc::WeldingProcess::onProcessed()
{//BEGIN_4acda518ce57a86a1ca08bf53f3dd618
    // empty
}//END_4acda518ce57a86a1ca08bf53f3dd618

void oldportal::fc::hardware::welding::proc::WeldingProcess::start()
{//BEGIN_b4e5a2d48871a9fa7852ec188e614273
    oldportal::fc::hardware::HardwareDeviceProcess::start();

    LOG4CXX_DEBUG(logger, "Process Welding start() call");
}//END_b4e5a2d48871a9fa7852ec188e614273


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE