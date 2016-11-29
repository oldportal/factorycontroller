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


oldportal::fc::network::modbus::data::SystemLogReport::SystemLogReport()

{//BEGIN_c133229c8e8ebd04c74bc07e81e7fedd
    // set structure sizeof
    _modbus_registers_sizeof = 5;

    // default values
    _1_error_code = CTRLR_NO_ERRORS;
    _2_count = 0;
    _3_last_time = 0;
    _4_last_parameter = 0;
}//END_c133229c8e8ebd04c74bc07e81e7fedd


void oldportal::fc::network::modbus::data::SystemLogReport::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_008e2d3da8906929567066bce5aa1804
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    // variables
    _1_error_code = registers[0];
    _2_count = registers[1];

    uint32_t *time_register = (uint32_t *)(registers+2);
    _3_last_time = *time_register;
    _4_last_parameter = registers[4];
}//END_008e2d3da8906929567066bce5aa1804

void oldportal::fc::network::modbus::data::SystemLogReport::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_2036dbc9a7533c45765fbe038c60cfe4
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    // variables
    registers[0] = _1_error_code;
    registers[1] = _2_count;
    uint32_t *time_register = (uint32_t *)(registers+2);
    *time_register = _3_last_time;
    registers[4] = _4_last_parameter;
}//END_2036dbc9a7533c45765fbe038c60cfe4


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE