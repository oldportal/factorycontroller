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


const char* const  oldportal::fc::hardware::mechatronics::data::StepMotorDriverData::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::data::StepMotorDriverData";


oldportal::fc::hardware::mechatronics::data::StepMotorDriverData::StepMotorDriverData()

{//BEGIN_1b0d5364452fcec90afd9e98db980d6f
    // set structure sizeof
    _modbus_registers_sizeof = 15;

    // default values
    _1_mode = DRIVER_SERVO_IDLE;
    _2_hardware_error_code = DRIVER_HARDWARE_NO_ERRORS;
    _3_flags = 0;

    _4_rotor_angle_start_speed = 0;
    _5_rotor_angle_start_speed_time = 0;
    _6_rotor_angle_acceleration_speed = 0;
    _7_rotor_angle_end_continuous_speed = 0;
    _8_rotor_angle_stop_position = 0;
    _9_rotor_angle_force = 0;
    _10_rotor_angle_direct_step = 0;
    _14_motor_step_scale = 1; // fullstep mode

    _11_motor_maximum_allowed_temperature = DEFAULT_MAXIMUM_ALLOWED_MOTOR_TEMPERATURE;
    _12_motor_maximum_allowed_current = DEFAULT_MAXIMUM_ALLOWED_MOTOR_CURRENT;
    _13_motor_maximum_allowed_angle_speed = DEFAULT_MAXIMUM_ALLOWED_ANGLE_SPEED;
}//END_1b0d5364452fcec90afd9e98db980d6f


void oldportal::fc::hardware::mechatronics::data::StepMotorDriverData::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_0013680b70d615bd9baefe892282ecc8
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_0013680b70d615bd9baefe892282ecc8

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverData::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_27e4e31bcfc47687cb5d2dda8818bf44
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_mode = registers[0];
    _2_hardware_error_code = registers[1];
    _3_flags = registers[2];
    _4_rotor_angle_start_speed = registers_i16[3];

    int32_t *rotor_angle_start_speed_time_register = (int32_t *)(registers+4);
    _5_rotor_angle_start_speed_time = *rotor_angle_start_speed_time_register;

    _6_rotor_angle_acceleration_speed = registers_i16[6];
    _7_rotor_angle_end_continuous_speed = registers_i16[7];

    int32_t *rotor_angle_stop_position_register = (int32_t *)(registers+8);
    _8_rotor_angle_stop_position = *rotor_angle_stop_position_register;

    _9_rotor_angle_force = registers_i16[10];
    _10_rotor_angle_direct_step = registers_i16[11];
    _11_motor_maximum_allowed_temperature = registers_i16[12];
    _12_motor_maximum_allowed_current = registers_i16[13];
    _13_motor_maximum_allowed_angle_speed = registers_i16[14];
}//END_27e4e31bcfc47687cb5d2dda8818bf44

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverData::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_09d9c46ccee7665b42224733ad68a470
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_09d9c46ccee7665b42224733ad68a470

void oldportal::fc::hardware::mechatronics::data::StepMotorDriverData::saveToRegisterArray(uint16_t* registers)
{//BEGIN_0181dfe1529c3e950d36a42336b2e2ed
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_mode;
    registers[1] = _2_hardware_error_code;
    registers[2] = _3_flags;
    registers_i16[3] = _4_rotor_angle_start_speed;

    int32_t *rotor_angle_start_speed_time_register = (int32_t *)(registers+4);
    *rotor_angle_start_speed_time_register = _5_rotor_angle_start_speed_time;

    registers_i16[6] = _6_rotor_angle_acceleration_speed;
    registers_i16[7] = _7_rotor_angle_end_continuous_speed;

    int32_t *rotor_angle_stop_position_register = (int32_t *)(registers+8);
    *rotor_angle_stop_position_register = _8_rotor_angle_stop_position;

    registers_i16[10] = _9_rotor_angle_force;
    registers_i16[11] = _10_rotor_angle_direct_step;
    registers_i16[12] = _11_motor_maximum_allowed_temperature;
    registers_i16[13] = _12_motor_maximum_allowed_current;
    registers_i16[14] = _13_motor_maximum_allowed_angle_speed;
}//END_0181dfe1529c3e950d36a42336b2e2ed


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE