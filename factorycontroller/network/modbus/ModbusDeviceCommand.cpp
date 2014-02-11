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
*    Copyright (C) Dmitry Ognyannikov, 2012
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusDeviceCommand::ModbusDeviceCommand()

{//BEGIN_f9f11e3926f4b2cc2d7a8949e4efe11e
    _modbus_ctx = nullptr;
}//END_f9f11e3926f4b2cc2d7a8949e4efe11e


void oldportal::fc::network::modbus::ModbusDeviceCommand::onProcessed()
{//BEGIN_f7fd91d01e45d3af0b5b6cd1f6ef68ba
    // empty
}//END_f7fd91d01e45d3af0b5b6cd1f6ef68ba

void oldportal::fc::network::modbus::ModbusDeviceCommand::process()
{//BEGIN_1ff74e62ebfce954857fac5f039c3234
    assert(_modbus_ctx);
}//END_1ff74e62ebfce954857fac5f039c3234


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE