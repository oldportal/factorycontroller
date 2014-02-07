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


oldportal::fc::network::modbus::ModbusMessageWrapper::ModbusMessageWrapper(oldportal::fc::network::modbus::ModbusMessagePair* pair)

{//BEGIN_b3ff4a7c3f3e9310541352e219295968
    assert(pair);

    _pair = pair;
    _function_code = 0;
    _response_minimum_length = 0;
}//END_b3ff4a7c3f3e9310541352e219295968


uint8_t oldportal::fc::network::modbus::ModbusMessageWrapper::get_function_code()
{//BEGIN_923b0eb724f5e02392a4fafbde4ae0c2
    return _function_code;
}//END_923b0eb724f5e02392a4fafbde4ae0c2

uint8_t oldportal::fc::network::modbus::ModbusMessageWrapper::get_response_minimum_length()
{//BEGIN_bf7cc0309f716e96f4b3746972307c83
    return _response_minimum_length;
}//END_bf7cc0309f716e96f4b3746972307c83


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE