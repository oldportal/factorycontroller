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


const char* const  oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants::_CLASSNAME_FULL = "oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants";


oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants::EDMDriverCalculationConstants()

{//BEGIN_8bfea0fd3de910be25a8d931757b00aa
    // set structure sizeof
    _modbus_registers_sizeof = 0;

    // default values
}//END_8bfea0fd3de910be25a8d931757b00aa


void oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_fb5fd6b6354a0f01ec05054520fac83b
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_fb5fd6b6354a0f01ec05054520fac83b

void oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_44926f60be8b3b920a803acf98625b0f
    assert(registers);

    // variables
    /*_1_steps_per_revolution = registers[0];
    _2_rotor_intertia = registers[1];
    _3_moment_elasticity = registers[2];
    _4_default_s_in_angle_steps = registers[3];*/
}//END_44926f60be8b3b920a803acf98625b0f

void oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_612ca36953a551b40b9bbcdd99467f6e
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_612ca36953a551b40b9bbcdd99467f6e

void oldportal::fc::hardware::edm::data::EDMDriverCalculationConstants::saveToRegisterArray(uint16_t* registers)
{//BEGIN_1a365be1c15b467fccbeb965cc2daf80
    assert(registers);

    // variables
    /*registers[0] = _1_steps_per_revolution;
    registers[1] = _2_rotor_intertia;
    registers[2] = _3_moment_elasticity;
    registers[3] = _4_default_s_in_angle_steps;*/
}//END_1a365be1c15b467fccbeb965cc2daf80


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE