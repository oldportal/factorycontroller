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
#ifndef H_2cf22df411c2eb537e1f75b49deac4d0_H
#define H_2cf22df411c2eb537e1f75b49deac4d0_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION
typedef enum
{
	DRIVER_SERVO_IDLE = 0,
	DRIVER_SERVO_KEEP_POSITION,
	DRIVER_SERVO_CONTINUOUS_SPEED,
	DRIVER_SERVO_SPEED_AND_ACCELERATION,
	DRIVER_SERVO_SPEED_AND_ACCELERATION_TO_END_SPEED,
	DRIVER_SERVO_SPEED_TO_END_POSITION,
	DRIVER_SERVO_CONTINUOUS_FORCE,
	DRIVER_STEP_DIRECT
} driverMode;

typedef enum
{
	DRIVER_HARDWARE_NO_ERRORS = 100,
	DRIVER_HARDWARE_MOTOR_TEMPERATURE_OVERHEAT,
	DRIVER_HARDWARE_POWER_LINE_OVERCURRENCY,
	DRIVER_HARDWARE_ANGLE_OVERSPEED,
	DRIVER_HARDWARE_ROTOR_BREAKED,
	/** Plan angle speed overspeed maximum motor speed */ 
	DRIVER_SOFRWARE_COMMAND_ANGLE_OVERSPEED,
	DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED
} driverHardwareErrorType;

/* Register offsets in MODBUS registers count (2 bytes) */
#define STEPMRDRV_DATA_REGISTER_OFFSET_1_mode 0
#define STEPMRDRV_DATA_REGISTER_OFFSET_2_hardware_error_code 1
#define STEPMRDRV_DATA_REGISTER_OFFSET_3_flags 2
#define STEPMRDRV_DATA_REGISTER_OFFSET_4_rotor_angle_start_speed 3
#define STEPMRDRV_DATA_REGISTER_OFFSET_5_rotor_angle_start_speed_time 4
#define STEPMRDRV_DATA_REGISTER_OFFSET_6_rotor_angle_acceleration_speed 6
#define STEPMRDRV_DATA_REGISTER_OFFSET_7_rotor_angle_end_continuous_speed 7
#define STEPMRDRV_DATA_REGISTER_OFFSET_8_rotor_angle_stop_position 8
#define STEPMRDRV_DATA_REGISTER_OFFSET_9_rotor_angle_force 10
#define STEPMRDRV_DATA_REGISTER_OFFSET_10_rotor_angle_direct_step 11
#define STEPMRDRV_DATA_REGISTER_OFFSET_11_motor_maximum_allowed_temperature 12
#define STEPMRDRV_DATA_REGISTER_OFFSET_12_motor_maximum_allowed_current 13
#define STEPMRDRV_DATA_REGISTER_OFFSET_13_motor_maximum_allowed_angle_speed 14

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
 Plan angle speed overspeed maximum motor speed
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace mechatronics 
{
namespace data 
{

struct StepMotorDriverData
:  public virtual oldportal::fc::network::modbus::data::ModbusRegistersMapping
{
// constructors:
public:
StepMotorDriverData();


// members:

/**
Make direct step (if value = +1 or -1) and set value to 0
*/
public:
int16_t _10_rotor_angle_direct_step;
/**
Maximum allowed motor temperature (in Celsius)
*/
public:
int16_t _11_motor_maximum_allowed_temperature;
/**
Maximum allowed motor total current in milliamperes
*/
public:
int16_t _12_motor_maximum_allowed_current;
/**
Maximum allowed rotor angle speed in steps per second
*/
public:
int16_t _13_motor_maximum_allowed_angle_speed;
public:
int16_t _4_rotor_angle_start_speed;
public:
int16_t _6_rotor_angle_acceleration_speed;
/**
End continuous speed in acceleration mode and continuous speed in continuous speed mode in steps per second
*/
public:
int16_t _7_rotor_angle_end_continuous_speed;
public:
int16_t _9_rotor_angle_force;
/**
acceleration start time (System Time)
*/
public:
int32_t _5_rotor_angle_start_speed_time;
/**
Absolute angle stop position
*/
public:
int32_t _8_rotor_angle_stop_position;
/**
Step motor microstep scaler, 1 = full step, 2 = halfstep, 4 = 1/4 step
*/
public:
uint16_t _14_motor_step_scale;
/**
Motor control driver mode
*/
public:
uint16_t _1_mode;
/**
Hardware error code
*/
public:
uint16_t _2_hardware_error_code;
/**
Binary flags, also called "coils"
*/
public:
uint16_t _3_flags;


//methods:

public:
virtual void loadFromRegisterArray(const modbus_mapping_t* modbus_mapping);

public:
virtual void saveToRegisterArray(const modbus_mapping_t* modbus_mapping);



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware
}// namespace mechatronics
}// namespace data


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_2cf22df411c2eb537e1f75b49deac4d0_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_2cf22df411c2eb537e1f75b49deac4d0_INLINES_H
#define H_2cf22df411c2eb537e1f75b49deac4d0_INLINES_H

#endif // H_2cf22df411c2eb537e1f75b49deac4d0_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES