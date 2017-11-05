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


const char* const  oldportal::fc::hardware::metallurgy::command::StopHeating::_CLASSNAME_FULL = "oldportal::fc::hardware::metallurgy::command::StopHeating";


oldportal::fc::hardware::metallurgy::command::StopHeating::StopHeating(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_fa631fcdc220746cebeb12036e972588

}//END_fa631fcdc220746cebeb12036e972588



oldportal::fc::hardware::metallurgy::command::StopHeating::~StopHeating()
{//BEGIN_8553501b2510aec3315af7e4bc4273ec

}//END_8553501b2510aec3315af7e4bc4273ec


void oldportal::fc::hardware::metallurgy::command::StopHeating::onProcessed()
{//BEGIN_f776c9e54ede773c6b6d86f2226970ce
    // empty
}//END_f776c9e54ede773c6b6d86f2226970ce

void oldportal::fc::hardware::metallurgy::command::StopHeating::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_58b1933eb0c5f5159ffff30e0ffa2991
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_58b1933eb0c5f5159ffff30e0ffa2991


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE