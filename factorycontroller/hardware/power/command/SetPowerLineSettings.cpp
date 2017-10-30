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


oldportal::fc::hardware::power::command::SetPowerLineSettings::SetPowerLineSettings(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_1009cc56ecdc930da7027bfb78b34122

}//END_1009cc56ecdc930da7027bfb78b34122



oldportal::fc::hardware::power::command::SetPowerLineSettings::~SetPowerLineSettings()
{//BEGIN_27009d457df7aa32495d32356accbc87

}//END_27009d457df7aa32495d32356accbc87


void oldportal::fc::hardware::power::command::SetPowerLineSettings::onProcessed()
{//BEGIN_ad48add38ad420a4200c10229e11dc67
    // empty
}//END_ad48add38ad420a4200c10229e11dc67

void oldportal::fc::hardware::power::command::SetPowerLineSettings::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_00c87421c7e99ca51fe6e56b3399fca0
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_00c87421c7e99ca51fe6e56b3399fca0


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE