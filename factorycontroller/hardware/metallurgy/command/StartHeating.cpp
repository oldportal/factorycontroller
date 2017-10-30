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


oldportal::fc::hardware::metallurgy::command::StartHeating::StartHeating(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_e684215f88488b6ec9a0f3d38d25efd2

}//END_e684215f88488b6ec9a0f3d38d25efd2



oldportal::fc::hardware::metallurgy::command::StartHeating::~StartHeating()
{//BEGIN_ea51b3450b705423a2ad58c4930cda55

}//END_ea51b3450b705423a2ad58c4930cda55


void oldportal::fc::hardware::metallurgy::command::StartHeating::onProcessed()
{//BEGIN_9305ca4caf9307d671b7f14b92654fe6
    // empty
}//END_9305ca4caf9307d671b7f14b92654fe6

void oldportal::fc::hardware::metallurgy::command::StartHeating::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_94173837a476c0dade4ff066e2988a20
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_94173837a476c0dade4ff066e2988a20


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE