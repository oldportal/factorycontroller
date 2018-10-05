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


const char* const  oldportal::fc::hardware::edm::command::StopEDM::_CLASSNAME_FULL = "oldportal::fc::hardware::edm::command::StopEDM";


oldportal::fc::hardware::edm::command::StopEDM::StopEDM(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_d0c8998911fdc99fc952fc516402cf34

}//END_d0c8998911fdc99fc952fc516402cf34



oldportal::fc::hardware::edm::command::StopEDM::~StopEDM()
{//BEGIN_3fbe35d132326314ec4b2e26eb5dfa6b

}//END_3fbe35d132326314ec4b2e26eb5dfa6b


void oldportal::fc::hardware::edm::command::StopEDM::onProcessed()
{//BEGIN_4d144d546bb597618ec87b52c5cb7d64
    // empty
}//END_4d144d546bb597618ec87b52c5cb7d64

void oldportal::fc::hardware::edm::command::StopEDM::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_277de97e0eba405b5748b0e8917d5016
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_277de97e0eba405b5748b0e8917d5016


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE