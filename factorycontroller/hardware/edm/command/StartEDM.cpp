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


oldportal::fc::hardware::edm::command::StartEDM::StartEDM(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_15e8d58286129a0200cfe2d1d28fc789

}//END_15e8d58286129a0200cfe2d1d28fc789



oldportal::fc::hardware::edm::command::StartEDM::~StartEDM()
{//BEGIN_72d8a75119b7ee4b028cd2ad9073df2e

}//END_72d8a75119b7ee4b028cd2ad9073df2e


void oldportal::fc::hardware::edm::command::StartEDM::onProcessed()
{//BEGIN_d8eebf2292623c9c32eb9c721e457ae5
    // empty
}//END_d8eebf2292623c9c32eb9c721e457ae5

void oldportal::fc::hardware::edm::command::StartEDM::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_dc1d96790b77a279ab61a088f94bdb3b
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_dc1d96790b77a279ab61a088f94bdb3b


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE