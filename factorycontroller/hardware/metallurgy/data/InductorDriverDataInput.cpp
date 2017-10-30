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


oldportal::fc::hardware::metallurgy::data::InductorDriverDataInput::InductorDriverDataInput()

{//BEGIN_35af6aa2d90df53a5acb7619467faa5d
    // set structure sizeof
    _modbus_registers_sizeof = 2;

    // default values
    _1_current = 0;
    _2_voltage = 0;
}//END_35af6aa2d90df53a5acb7619467faa5d


void oldportal::fc::hardware::metallurgy::data::InductorDriverDataInput::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_204e4b6796102423cfd1949bcff0a558
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_204e4b6796102423cfd1949bcff0a558

void oldportal::fc::hardware::metallurgy::data::InductorDriverDataInput::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_d106033235c7bf2d51600776657391d3
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_current = registers[0];
    _2_voltage = registers[1];
}//END_d106033235c7bf2d51600776657391d3

void oldportal::fc::hardware::metallurgy::data::InductorDriverDataInput::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_06e60ee718e4898be6233366484dd173
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_06e60ee718e4898be6233366484dd173

void oldportal::fc::hardware::metallurgy::data::InductorDriverDataInput::saveToRegisterArray(uint16_t* registers)
{//BEGIN_24da09e3a6ff0ac5766f0940a1e96be1
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_current;
    registers[1] = _2_voltage;
}//END_24da09e3a6ff0ac5766f0940a1e96be1


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE