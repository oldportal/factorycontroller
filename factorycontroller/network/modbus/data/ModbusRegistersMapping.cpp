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


const char* const  oldportal::fc::network::modbus::data::ModbusRegistersMapping::_CLASSNAME_FULL = "oldportal::fc::network::modbus::data::ModbusRegistersMapping";


oldportal::fc::network::modbus::data::ModbusRegistersMapping::ModbusRegistersMapping()

{//BEGIN_c186af3669cca7f31601eafd1339835b
    _modbus_registers_start_index = 0;
    _modbus_registers_sizeof = 0;
}//END_c186af3669cca7f31601eafd1339835b


uint8_t oldportal::fc::network::modbus::data::ModbusRegistersMapping::getModbusRegistersSizeof()
{//BEGIN_de82e428624296d3c8a4628f3ebe3cf3
    return _modbus_registers_sizeof;
}//END_de82e428624296d3c8a4628f3ebe3cf3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE