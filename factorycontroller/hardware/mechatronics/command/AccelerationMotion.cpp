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


oldportal::fc::hardware::mechatronics::command::AccelerationMotion::AccelerationMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_016062428c634fa59a004f10eb887bfc

}//END_016062428c634fa59a004f10eb887bfc



oldportal::fc::hardware::mechatronics::command::AccelerationMotion::~AccelerationMotion()
{//BEGIN_1556f3b4bc618a35a8010806093d10fb

}//END_1556f3b4bc618a35a8010806093d10fb


void oldportal::fc::hardware::mechatronics::command::AccelerationMotion::onProcessed()
{//BEGIN_3c65a1ca33d640743741bee56673b454
    // empty
}//END_3c65a1ca33d640743741bee56673b454

void oldportal::fc::hardware::mechatronics::command::AccelerationMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_3cf4c714d2918c3ad2d6767fdb99c855
    assert(controller);
    assert(_device);
    assert(_device_process);

    auto motorDevice = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motorDevice);

    //TODO:
}//END_3cf4c714d2918c3ad2d6767fdb99c855


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE