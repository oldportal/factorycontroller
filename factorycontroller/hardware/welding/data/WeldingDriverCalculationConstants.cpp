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


oldportal::fc::hardware::welding::data::WeldingDriverCalculationConstants::WeldingDriverCalculationConstants()

{//BEGIN_49b04b04e818dc8cace3dfa5a5a5f3e2
    // set structure sizeof
    _modbus_registers_sizeof = 0;

    // default values
}//END_49b04b04e818dc8cace3dfa5a5a5f3e2


void oldportal::fc::hardware::welding::data::WeldingDriverCalculationConstants::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_9536f252d246c0176b53b75438c6cb65
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_9536f252d246c0176b53b75438c6cb65

void oldportal::fc::hardware::welding::data::WeldingDriverCalculationConstants::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_955b6fe8d9605b51d6a9705a5274acd7
    assert(registers);

    // variables
    /*_1_steps_per_revolution = registers[0];
    _2_rotor_intertia = registers[1];
    _3_moment_elasticity = registers[2];
    _4_default_s_in_angle_steps = registers[3];*/
}//END_955b6fe8d9605b51d6a9705a5274acd7

void oldportal::fc::hardware::welding::data::WeldingDriverCalculationConstants::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_fadf7e19bf13185bb134ad26d4aeb698
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_fadf7e19bf13185bb134ad26d4aeb698

void oldportal::fc::hardware::welding::data::WeldingDriverCalculationConstants::saveToRegisterArray(uint16_t* registers)
{//BEGIN_13dd11d74cce977c42e0141fe5d0fd94
    assert(registers);

    // variables
    /*registers[0] = _1_steps_per_revolution;
    registers[1] = _2_rotor_intertia;
    registers[2] = _3_moment_elasticity;
    registers[3] = _4_default_s_in_angle_steps;*/
}//END_13dd11d74cce977c42e0141fe5d0fd94


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE