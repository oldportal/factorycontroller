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


oldportal::fc::hardware::edm::command::GetEDMState::GetEDMState(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_b6de32d87b91565e42ed4452ad8b70b0

}//END_b6de32d87b91565e42ed4452ad8b70b0



oldportal::fc::hardware::edm::command::GetEDMState::~GetEDMState()
{//BEGIN_1c775cd270162b94aa0db8974e6d13d7

}//END_1c775cd270162b94aa0db8974e6d13d7


void oldportal::fc::hardware::edm::command::GetEDMState::onProcessed()
{//BEGIN_ad00d77bcc3cda7ed3e805504b665622
    // empty
}//END_ad00d77bcc3cda7ed3e805504b665622

void oldportal::fc::hardware::edm::command::GetEDMState::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_5ff049adf4247e5e80f0b1330a9a5fcc
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_5ff049adf4247e5e80f0b1330a9a5fcc


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE