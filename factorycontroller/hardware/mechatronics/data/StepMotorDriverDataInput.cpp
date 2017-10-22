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


oldportal::fc::hardware::mechatronics::data::StepMotorDriverDataInput::StepMotorDriverDataInput()

{//BEGIN_a96c013cd30a34acd6f07b397fbec2d3
    // set structure sizeof
    _modbus_registers_sizeof = 7;

    // default values
    _1_rotor_angle_speed = 0;
    _2_rotor_angle_acceleration = 0;
    _3_rotor_absolute_angle_position = 0;
    _4_rotor_planned_angle_speed = 0;
    _5_rotor_planned_angle_torque = 0;
    _6_motor_temperature = DEFAULT_MOTOR_TEMPERATURE;
}//END_a96c013cd30a34acd6f07b397fbec2d3


void oldportal::fc::hardware::mechatronics::data::StepMotorDriverDataInput::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_96943c7718d9be57e33ccbd0b6b7001c
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_96943c7718d9be57e33ccbd0b6b7001c

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverDataInput::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_3f26b34d93a7af0a9583d073d71bd52c
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_rotor_angle_speed = registers_i16[0];
    _2_rotor_angle_acceleration = registers_i16[1];

    int32_t *rotor_absolute_angle_position_register = (int32_t *)(registers+2);
    _3_rotor_absolute_angle_position = *rotor_absolute_angle_position_register;

    _4_rotor_planned_angle_speed = registers_i16[4];
    _5_rotor_planned_angle_torque = registers_i16[5];
    _6_motor_temperature = registers_i16[6];
}//END_3f26b34d93a7af0a9583d073d71bd52c

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverDataInput::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_dd2f46375fb7721632411d03e07536cd
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_dd2f46375fb7721632411d03e07536cd

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverDataInput::saveToRegisterArray(uint16_t* registers)
{//BEGIN_f6cfcfd835a2ab2c7074bf040bf093b3
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers_i16[0] = _1_rotor_angle_speed;
    registers_i16[1] = _2_rotor_angle_acceleration;

    int32_t *rotor_absolute_angle_position_register = (int32_t *)(registers+2);
    *rotor_absolute_angle_position_register = _3_rotor_absolute_angle_position;

    registers_i16[4] = _4_rotor_planned_angle_speed;
    registers_i16[5] = _5_rotor_planned_angle_torque;
    registers_i16[6] = _6_motor_temperature;
}//END_f6cfcfd835a2ab2c7074bf040bf093b3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
