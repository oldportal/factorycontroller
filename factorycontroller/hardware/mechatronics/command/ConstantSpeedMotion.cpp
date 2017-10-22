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


oldportal::fc::hardware::mechatronics::command::ConstantSpeedMotion::ConstantSpeedMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process, float speed)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_e1393b704f46e159fc1bc9f2d46e7b3d
    _speed = speed;
}//END_e1393b704f46e159fc1bc9f2d46e7b3d



oldportal::fc::hardware::mechatronics::command::ConstantSpeedMotion::~ConstantSpeedMotion()
{//BEGIN_fa62beef2df6510eed0a4cff81e94d23

}//END_fa62beef2df6510eed0a4cff81e94d23


void oldportal::fc::hardware::mechatronics::command::ConstantSpeedMotion::onProcessed()
{//BEGIN_17128dbebbc9abb12f32aa27066139b3
    // empty
}//END_17128dbebbc9abb12f32aa27066139b3

void oldportal::fc::hardware::mechatronics::command::ConstantSpeedMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_6ba632926a4f56dbcfbb09ec0b514ef0
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    //TODO:
}//END_6ba632926a4f56dbcfbb09ec0b514ef0


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
