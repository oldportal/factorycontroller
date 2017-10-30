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


oldportal::fc::hardware::metallurgy::data::InductorDriverCalculationConstants::InductorDriverCalculationConstants()

{//BEGIN_b7eefdb783eb8e43c0461015a7afe1b2
    // set structure sizeof
    _modbus_registers_sizeof = 0;

    // default values
}//END_b7eefdb783eb8e43c0461015a7afe1b2


void oldportal::fc::hardware::metallurgy::data::InductorDriverCalculationConstants::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_db1146c872639a3f9abf049f2c5ef2b0
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_db1146c872639a3f9abf049f2c5ef2b0

void oldportal::fc::hardware::metallurgy::data::InductorDriverCalculationConstants::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_c09aca0362eb7bc2f7b4a573dcc97eec
    assert(registers);

    // variables
    /*_1_steps_per_revolution = registers[0];
    _2_rotor_intertia = registers[1];
    _3_moment_elasticity = registers[2];
    _4_default_s_in_angle_steps = registers[3];*/
}//END_c09aca0362eb7bc2f7b4a573dcc97eec

void oldportal::fc::hardware::metallurgy::data::InductorDriverCalculationConstants::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_bd4e996c3fccc1c43a62cda13f72ff54
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_bd4e996c3fccc1c43a62cda13f72ff54

void oldportal::fc::hardware::metallurgy::data::InductorDriverCalculationConstants::saveToRegisterArray(uint16_t* registers)
{//BEGIN_9fce7f49292a443f0752dc8bf8402d56
    assert(registers);

    // variables
    /*registers[0] = _1_steps_per_revolution;
    registers[1] = _2_rotor_intertia;
    registers[2] = _3_moment_elasticity;
    registers[3] = _4_default_s_in_angle_steps;*/
}//END_9fce7f49292a443f0752dc8bf8402d56


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE