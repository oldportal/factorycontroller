/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*    
*    factorycontroller is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::command::DeviceStateReport::DeviceStateReport(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device)

{//BEGIN_7beba502117e9095cf401c036398cc43
    assert(device);
    _device = device;
    _controller = std::dynamic_pointer_cast<oldportal::fc::network::modbus::ModbusNetworkController>(device->_network.lock()->_controller.lock());
}//END_7beba502117e9095cf401c036398cc43



oldportal::fc::network::command::DeviceStateReport::~DeviceStateReport()
{//BEGIN_d1555c3373090cf5a5b01ddf233ffacc

}//END_d1555c3373090cf5a5b01ddf233ffacc


void oldportal::fc::network::command::DeviceStateReport::process()
{//BEGIN_b9522da80d4b05e42e2b9d9a702ae52d
    assert(_controller);

    //TODO: ping device
}//END_b9522da80d4b05e42e2b9d9a702ae52d


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
