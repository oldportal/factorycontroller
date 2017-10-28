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


oldportal::fc::hardware::welding::command::GetWeldingState::GetWeldingState(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_05af076cfbe093d89acbc92c27fbb1f9

}//END_05af076cfbe093d89acbc92c27fbb1f9



oldportal::fc::hardware::welding::command::GetWeldingState::~GetWeldingState()
{//BEGIN_396cfe52a6d280f9e71d0ecd49f0ca8f

}//END_396cfe52a6d280f9e71d0ecd49f0ca8f


void oldportal::fc::hardware::welding::command::GetWeldingState::onProcessed()
{//BEGIN_8d52b44d8307fbfa4105c07be4447eff
    // empty
}//END_8d52b44d8307fbfa4105c07be4447eff

void oldportal::fc::hardware::welding::command::GetWeldingState::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_75dbc04960db8cc2c5d0529999dd37fe
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::welding::WeldingPowerSource> welding_device = std::dynamic_pointer_cast<oldportal::fc::hardware::welding::WeldingPowerSource>(_device);
    assert (welding_device);

    //TODO:
}//END_75dbc04960db8cc2c5d0529999dd37fe


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE