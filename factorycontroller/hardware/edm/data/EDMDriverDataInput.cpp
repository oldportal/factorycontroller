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


const char* const  oldportal::fc::hardware::edm::data::EDMDriverDataInput::_CLASSNAME_FULL = "oldportal::fc::hardware::edm::data::EDMDriverDataInput";


oldportal::fc::hardware::edm::data::EDMDriverDataInput::EDMDriverDataInput()

{//BEGIN_51ed7e0971aa368870db890660740131
    // set structure sizeof
    _modbus_registers_sizeof = 2;

    // default values
    _1_current = 0;
    _2_voltage = 0;
}//END_51ed7e0971aa368870db890660740131


void oldportal::fc::hardware::edm::data::EDMDriverDataInput::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_a3253f2bb21edb9a51ec84e706349873
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_a3253f2bb21edb9a51ec84e706349873

void oldportal::fc::hardware::edm::data::EDMDriverDataInput::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_7a51312ce0242b75d143c8afc33b1db2
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_current = registers[0];
    _2_voltage = registers[1];
}//END_7a51312ce0242b75d143c8afc33b1db2

void oldportal::fc::hardware::edm::data::EDMDriverDataInput::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_fa8c0c1cf83a7539b8bc3d719a170083
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_fa8c0c1cf83a7539b8bc3d719a170083

void oldportal::fc::hardware::edm::data::EDMDriverDataInput::saveToRegisterArray(uint16_t* registers)
{//BEGIN_0a328c6655ef99cafd6ede4bce090c4b
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_current;
    registers[1] = _2_voltage;
}//END_0a328c6655ef99cafd6ede4bce090c4b


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE