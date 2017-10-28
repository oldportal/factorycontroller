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


oldportal::fc::hardware::welding::command::StartWelding::StartWelding(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_e71dc40c0b52d716156bc9fa17b5ed01

}//END_e71dc40c0b52d716156bc9fa17b5ed01



oldportal::fc::hardware::welding::command::StartWelding::~StartWelding()
{//BEGIN_513e42e25ecf4ec60ebaae1c70bb6c6c

}//END_513e42e25ecf4ec60ebaae1c70bb6c6c


void oldportal::fc::hardware::welding::command::StartWelding::onProcessed()
{//BEGIN_85cedb9b4d28abfdfeeb625d9320fa5e
    // empty
}//END_85cedb9b4d28abfdfeeb625d9320fa5e

void oldportal::fc::hardware::welding::command::StartWelding::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_7c2ce6d343a5b6abeefb8d4b27148d18
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_7c2ce6d343a5b6abeefb8d4b27148d18


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE