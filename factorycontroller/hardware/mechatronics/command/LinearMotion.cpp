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


oldportal::fc::hardware::mechatronics::command::LinearMotion::LinearMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process, float speed)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_f1e42a2902ff79a631b19822cf0c87bb
    _speed = speed;
}//END_f1e42a2902ff79a631b19822cf0c87bb



oldportal::fc::hardware::mechatronics::command::LinearMotion::~LinearMotion()
{//BEGIN_3ae7cbc70058cbc03bebf6e27865f011

}//END_3ae7cbc70058cbc03bebf6e27865f011


void oldportal::fc::hardware::mechatronics::command::LinearMotion::onProcessed()
{//BEGIN_25255f50ef0019f639443262727c6347
    // empty
}//END_25255f50ef0019f639443262727c6347

void oldportal::fc::hardware::mechatronics::command::LinearMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_5a4ca282f77a69d1fdd39facedaec3a6
    assert(controller);
    assert(_device);
    assert(_device_process);

    auto motorDevice = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motorDevice);

    if (!modbus_set_slave(controller))
        return;// hardware error


    //TODO: controller operations
}//END_5a4ca282f77a69d1fdd39facedaec3a6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
