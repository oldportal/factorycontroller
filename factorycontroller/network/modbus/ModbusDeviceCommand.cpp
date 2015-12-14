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


oldportal::fc::network::modbus::ModbusDeviceCommand::ModbusDeviceCommand()

{//BEGIN_5a51e40c38c53eade4f9750574d15715
    _modbus_ctx = nullptr;
}//END_5a51e40c38c53eade4f9750574d15715

oldportal::fc::network::modbus::ModbusDeviceCommand::ModbusDeviceCommand(modbus_t* modbus_ctx)

{//BEGIN_f9f11e3926f4b2cc2d7a8949e4efe11e
    _modbus_ctx = nullptr;
}//END_f9f11e3926f4b2cc2d7a8949e4efe11e



oldportal::fc::network::modbus::ModbusDeviceCommand::~ModbusDeviceCommand()
{//BEGIN_e06e6ffe43623a9d85f2171b34d077af

}//END_e06e6ffe43623a9d85f2171b34d077af


void oldportal::fc::network::modbus::ModbusDeviceCommand::onProcessed()
{//BEGIN_f7fd91d01e45d3af0b5b6cd1f6ef68ba
    // empty
}//END_f7fd91d01e45d3af0b5b6cd1f6ef68ba


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE