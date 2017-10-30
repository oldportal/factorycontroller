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


oldportal::fc::hardware::power::command::GetPowerLineState::GetPowerLineState(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_b693127e09d64115c45bb8fa8326c426

}//END_b693127e09d64115c45bb8fa8326c426



oldportal::fc::hardware::power::command::GetPowerLineState::~GetPowerLineState()
{//BEGIN_f1b11fa3d3d45074bade495d6d52490a

}//END_f1b11fa3d3d45074bade495d6d52490a


void oldportal::fc::hardware::power::command::GetPowerLineState::onProcessed()
{//BEGIN_fab8b3330522a747fcc8412e6125beab
    // empty
}//END_fab8b3330522a747fcc8412e6125beab

void oldportal::fc::hardware::power::command::GetPowerLineState::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_9b39252ba656bc05a229ee3291cb1f39
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_9b39252ba656bc05a229ee3291cb1f39


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE