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


const char* const  oldportal::fc::hardware::metallurgy::data::InductorDriverData::_CLASSNAME_FULL = "oldportal::fc::hardware::metallurgy::data::InductorDriverData";


oldportal::fc::hardware::metallurgy::data::InductorDriverData::InductorDriverData()

{//BEGIN_02c2be8d5e6662a953478baf7ba136f9
    // set structure sizeof
    _modbus_registers_sizeof = 3;

    // default values
    _1_mode = FC_DRIVER_WELDING_IDLE;
    _2_hardware_error_code = DRIVER_HARDWARE_NO_ERRORS;
    _3_flags = 0;
}//END_02c2be8d5e6662a953478baf7ba136f9


void oldportal::fc::hardware::metallurgy::data::InductorDriverData::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_a686678bd70dbd35de71d5d0d6e61fba
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_a686678bd70dbd35de71d5d0d6e61fba

void oldportal::fc::hardware::metallurgy::data::InductorDriverData::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_5ae3669ee899a41d2b9135c7a052758b
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_mode = registers[0];
    _2_hardware_error_code = registers[1];
    _3_flags = registers[2];
}//END_5ae3669ee899a41d2b9135c7a052758b

void oldportal::fc::hardware::metallurgy::data::InductorDriverData::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_0a86c6f3090ca15072321a89b568499c
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_0a86c6f3090ca15072321a89b568499c

void oldportal::fc::hardware::metallurgy::data::InductorDriverData::saveToRegisterArray(uint16_t* registers)
{//BEGIN_00352e13072fa40f1bff3a49f1ee877f
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_mode;
    registers[1] = _2_hardware_error_code;
    registers[2] = _3_flags;
}//END_00352e13072fa40f1bff3a49f1ee877f


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE