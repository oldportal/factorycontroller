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


oldportal::fc::hardware::power::data::PowerLineDriverData::PowerLineDriverData()

{//BEGIN_7dcfa82446fe057ffca39cbeefb0feed
    // set structure sizeof
    _modbus_registers_sizeof = 3;

    // default values
    _1_mode = FC_DRIVER_WELDING_IDLE;
    _2_hardware_error_code = DRIVER_HARDWARE_NO_ERRORS;
    _3_flags = 0;
}//END_7dcfa82446fe057ffca39cbeefb0feed


void oldportal::fc::hardware::power::data::PowerLineDriverData::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_49e51264d7e2949aaa1f36ab45fa6b42
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_49e51264d7e2949aaa1f36ab45fa6b42

void oldportal::fc::hardware::power::data::PowerLineDriverData::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_0d18024b0d63c48bf08fde029c4ba294
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_mode = registers[0];
    _2_hardware_error_code = registers[1];
    _3_flags = registers[2];
}//END_0d18024b0d63c48bf08fde029c4ba294

void oldportal::fc::hardware::power::data::PowerLineDriverData::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_11bcf24c123cb35f78d9bc9149e39beb
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_11bcf24c123cb35f78d9bc9149e39beb

void oldportal::fc::hardware::power::data::PowerLineDriverData::saveToRegisterArray(uint16_t* registers)
{//BEGIN_07edecf9aef5da622b6e28a688bcad67
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_mode;
    registers[1] = _2_hardware_error_code;
    registers[2] = _3_flags;
}//END_07edecf9aef5da622b6e28a688bcad67


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE