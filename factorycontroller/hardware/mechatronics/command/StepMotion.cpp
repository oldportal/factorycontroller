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


oldportal::fc::hardware::mechatronics::command::StepMotion::StepMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_ac3725385c54bbe125b8c2a5b1b020fb

}//END_ac3725385c54bbe125b8c2a5b1b020fb



oldportal::fc::hardware::mechatronics::command::StepMotion::~StepMotion()
{//BEGIN_14479bc6cabf11039aad4199e79fc4f3

}//END_14479bc6cabf11039aad4199e79fc4f3


void oldportal::fc::hardware::mechatronics::command::StepMotion::onProcessed()
{//BEGIN_672e70a7205f5de2d78edda67ad10174
    // empty
}//END_672e70a7205f5de2d78edda67ad10174

void oldportal::fc::hardware::mechatronics::command::StepMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_ce66d4c0b634215137cdb5fe36caf9ce
    assert(controller);
    assert(_device);
    assert(_device_process);

    auto motorDevice = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motorDevice);

    if (!modbus_set_slave())
        return;// hardware error

    //TODO:
}//END_ce66d4c0b634215137cdb5fe36caf9ce


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
