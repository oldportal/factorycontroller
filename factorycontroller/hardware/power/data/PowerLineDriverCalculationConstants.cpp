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


oldportal::fc::hardware::power::data::PowerLineDriverCalculationConstants::PowerLineDriverCalculationConstants()

{//BEGIN_ac666a527d60439beeb087eaa7b90a8f
    // set structure sizeof
    _modbus_registers_sizeof = 0;

    // default values
}//END_ac666a527d60439beeb087eaa7b90a8f


void oldportal::fc::hardware::power::data::PowerLineDriverCalculationConstants::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_750b6d1614f9247ba91738ab8575b5ae
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_750b6d1614f9247ba91738ab8575b5ae

void oldportal::fc::hardware::power::data::PowerLineDriverCalculationConstants::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_42fd59aec001a1d279ac88d75687a9b5
    assert(registers);

    // variables
    /*_1_steps_per_revolution = registers[0];
    _2_rotor_intertia = registers[1];
    _3_moment_elasticity = registers[2];
    _4_default_s_in_angle_steps = registers[3];*/
}//END_42fd59aec001a1d279ac88d75687a9b5

void oldportal::fc::hardware::power::data::PowerLineDriverCalculationConstants::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_48a8665b140221a051f6d87650e83ef5
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_48a8665b140221a051f6d87650e83ef5

void oldportal::fc::hardware::power::data::PowerLineDriverCalculationConstants::saveToRegisterArray(uint16_t* registers)
{//BEGIN_cf9aac0a93cae3e942b47adaa68adecf
    assert(registers);

    // variables
    /*registers[0] = _1_steps_per_revolution;
    registers[1] = _2_rotor_intertia;
    registers[2] = _3_moment_elasticity;
    registers[3] = _4_default_s_in_angle_steps;*/
}//END_cf9aac0a93cae3e942b47adaa68adecf


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE