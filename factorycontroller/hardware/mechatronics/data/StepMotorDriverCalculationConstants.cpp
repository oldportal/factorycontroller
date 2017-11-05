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


const char* const  oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants";


oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants::StepMotorDriverCalculationConstants()

{//BEGIN_e8da8280446dc69792ff6acbb957b006
    // set structure sizeof
    _modbus_registers_sizeof = 4;

    // default values
    _1_steps_per_revolution = 200;
    _2_rotor_intertia = 100;
    _3_moment_elasticity = 1000;
    _4_default_s_in_angle_steps = 0;
}//END_e8da8280446dc69792ff6acbb957b006


void oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_ec7a03b29e424da0f3fc780a4c3776b1
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_ec7a03b29e424da0f3fc780a4c3776b1

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_8b125a9f1b97c6c5938c2488fc354246
    assert(registers);

    // variables
    _1_steps_per_revolution = registers[0];
    _2_rotor_intertia = registers[1];
    _3_moment_elasticity = registers[2];
    _4_default_s_in_angle_steps = registers[3];
}//END_8b125a9f1b97c6c5938c2488fc354246

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_1fc4d20ac5a07623d4227d6ca5b45c3c
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_1fc4d20ac5a07623d4227d6ca5b45c3c

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverCalculationConstants::saveToRegisterArray(uint16_t* registers)
{//BEGIN_c74461846d9e7bf3679377c467b23ff4
    assert(registers);

    // variables
    registers[0] = _1_steps_per_revolution;
    registers[1] = _2_rotor_intertia;
    registers[2] = _3_moment_elasticity;
    registers[3] = _4_default_s_in_angle_steps;
}//END_c74461846d9e7bf3679377c467b23ff4


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE