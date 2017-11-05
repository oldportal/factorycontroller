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


const char* const  oldportal::fc::hardware::edm::data::EDMDriverData::_CLASSNAME_FULL = "oldportal::fc::hardware::edm::data::EDMDriverData";


oldportal::fc::hardware::edm::data::EDMDriverData::EDMDriverData()

{//BEGIN_66e52460dda57fb7cfdd1de2b2541ad3
    // set structure sizeof
    _modbus_registers_sizeof = 3;

    // default values
    _1_mode = FC_DRIVER_WELDING_IDLE;
    _2_hardware_error_code = DRIVER_HARDWARE_NO_ERRORS;
    _3_flags = 0;
}//END_66e52460dda57fb7cfdd1de2b2541ad3


void oldportal::fc::hardware::edm::data::EDMDriverData::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_5b5fdf24d881e72a455422e3bd3372be
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_5b5fdf24d881e72a455422e3bd3372be

void oldportal::fc::hardware::edm::data::EDMDriverData::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_51ffaa88cee2c38ca8e4b95542d554f0
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_mode = registers[0];
    _2_hardware_error_code = registers[1];
    _3_flags = registers[2];
}//END_51ffaa88cee2c38ca8e4b95542d554f0

void oldportal::fc::hardware::edm::data::EDMDriverData::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_e5e07ec811717a54fb26f2b7db226dd8
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_e5e07ec811717a54fb26f2b7db226dd8

void oldportal::fc::hardware::edm::data::EDMDriverData::saveToRegisterArray(uint16_t* registers)
{//BEGIN_f1d6826decade5dde8fa4d713b1551de
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_mode;
    registers[1] = _2_hardware_error_code;
    registers[2] = _3_flags;
}//END_f1d6826decade5dde8fa4d713b1551de


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE