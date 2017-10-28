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


oldportal::fc::hardware::welding::data::WeldingDriverDataInput::WeldingDriverDataInput()

{//BEGIN_933ad7e5ce1bfe7a96fba87c94d7fd8a
    // set structure sizeof
    _modbus_registers_sizeof = 2;

    // default values
    _1_current = 0;
    _2_voltage = 0;
}//END_933ad7e5ce1bfe7a96fba87c94d7fd8a


void oldportal::fc::hardware::welding::data::WeldingDriverDataInput::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_d2fc4ef0383b1fae15e2798a4523e866
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_d2fc4ef0383b1fae15e2798a4523e866

void oldportal::fc::hardware::welding::data::WeldingDriverDataInput::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_f496f656a4ff4a898bf23f4a0e975def
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_current = registers[0];
    _2_voltage = registers[1];
}//END_f496f656a4ff4a898bf23f4a0e975def

void oldportal::fc::hardware::welding::data::WeldingDriverDataInput::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_dedcf9bddbc7033241d1b31b9f597c2a
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_dedcf9bddbc7033241d1b31b9f597c2a

void oldportal::fc::hardware::welding::data::WeldingDriverDataInput::saveToRegisterArray(uint16_t* registers)
{//BEGIN_93b0e0ea5842687915cbeb179de23556
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_current;
    registers[1] = _2_voltage;
}//END_93b0e0ea5842687915cbeb179de23556


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE