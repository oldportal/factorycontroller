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


oldportal::fc::hardware::power::command::StopPowerLine::StopPowerLine(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_2119c9ba603633fe48fd88371026aa1e

}//END_2119c9ba603633fe48fd88371026aa1e



oldportal::fc::hardware::power::command::StopPowerLine::~StopPowerLine()
{//BEGIN_91fa409d6e94f6b2d5929edd41167858

}//END_91fa409d6e94f6b2d5929edd41167858


void oldportal::fc::hardware::power::command::StopPowerLine::onProcessed()
{//BEGIN_11629d643e3bc969aefc4c4d66a27ef3
    // empty
}//END_11629d643e3bc969aefc4c4d66a27ef3

void oldportal::fc::hardware::power::command::StopPowerLine::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_10439bc952b9333242e3c0b63418d34f
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_10439bc952b9333242e3c0b63418d34f


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE