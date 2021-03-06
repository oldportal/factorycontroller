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


const char* const  oldportal::fc::hardware::power::data::PowerLineDriverDataInput::_CLASSNAME_FULL = "oldportal::fc::hardware::power::data::PowerLineDriverDataInput";


oldportal::fc::hardware::power::data::PowerLineDriverDataInput::PowerLineDriverDataInput()

{//BEGIN_48bb3b59efe0d289d94114c0ee8b4870
    // set structure sizeof
    _modbus_registers_sizeof = 2;

    // default values
    _1_current = 0;
    _2_voltage = 0;
}//END_48bb3b59efe0d289d94114c0ee8b4870


void oldportal::fc::hardware::power::data::PowerLineDriverDataInput::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_6ae0999bf93e07ffcd8da2b863fd671d
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_6ae0999bf93e07ffcd8da2b863fd671d

void oldportal::fc::hardware::power::data::PowerLineDriverDataInput::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_068b1313f671b6b9c921cb172ee06d46
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_current = registers[0];
    _2_voltage = registers[1];
}//END_068b1313f671b6b9c921cb172ee06d46

void oldportal::fc::hardware::power::data::PowerLineDriverDataInput::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_5d7e48ff87833e0d04d95797a9524296
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_5d7e48ff87833e0d04d95797a9524296

void oldportal::fc::hardware::power::data::PowerLineDriverDataInput::saveToRegisterArray(uint16_t* registers)
{//BEGIN_fec3cdf5131ebe79e194a610e68c7759
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_current;
    registers[1] = _2_voltage;
}//END_fec3cdf5131ebe79e194a610e68c7759


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE