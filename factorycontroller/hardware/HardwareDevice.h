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
#ifndef H_6ce6d74f4936484fb21dcbc9f2b2d596_H
#define H_6ce6d74f4936484fb21dcbc9f2b2d596_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION
// Controller related constants

#define CONTROLLER_LOG_SIZE 10

#define CONTROLLER_TERMPERATURE_CONTROL_ENABLED
#define DEFAULT_MAXIMUM_RADIATOR_TEMPERATURE 100
#define DEFAULT_RADIATOR_TEMPERATURE 0


// motor type
//#define ENABLE_AC_INDUCTION_SERVO
#define ENABLE_AC_INDUCTION_SIMPLE
//#define ENABLE_AC_SYNCHRONOUS_SERVO
//#define ENABLE_STEP_SERVO

//#define STEP_MOTOR_MODE - obsolete
//#define SERVO_MOTOR_MODE - obsolete

// Common motor settings

// Current in milliamperes per ADC unit of measurement
#define MOTOR_PHASE_CURRENT_PER_ADC_UNIT 50

#define ENABLE_CONTROLLER_TERMOSENSOR
#define ENABLE_MOTOR_TERMOSENSOR

/** Maximum allowed motor temperature (in Celsius) */
#define DEFAULT_MAXIMUM_ALLOWED_MOTOR_TEMPERATURE 80
/** Maximum allowed motor total current in milliamperes */
#define DEFAULT_MAXIMUM_ALLOWED_MOTOR_CURRENT 500
/** Maximum allowed rotor angle speed in steps per second */
#define DEFAULT_MAXIMUM_ALLOWED_ANGLE_SPEED 5000

#define DEFAULT_MOTOR_TEMPERATURE 0

// Induction motor related settings

#define INDUCTION_MOTOR_PHASE_COUNT 1

// Step motor related settings

// default work phase current in milliamperes
#define STEP_MOTOR_DEFAULT_PHASE_CURRENT 2000

// keep position phase current in milliamperes
#define STEP_MOTOR_KEEP_POSITION_PHASE_CURRENT 500

// PWM frequency settings, 8 = 25 KHz
#define STEP_MOTOR_PWM_PRESCALER 8

#define STEP_MOTOR_DEFAULT_FULL_LOAD_PWM_DURATION 2

#define STEP_MOTOR_DEFAULT_KEEP_POSITION_PWM_DURATION 1

// overload time while full step start in system ticks
#define STEP_MOTOR_MAX_STEP_ACCELERATION_OVERLOAD_TIME 8
//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
 Maximum allowed motor temperature (in Celsius) 
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{

class HardwareDevice
:  public oldportal::fc::network::modbus::ModbusDevice
{
// constructors:
public:
HardwareDevice();


public:
virtual ~HardwareDevice();

// members:

public:
bool _controllerTemperatureSupported;
public:
bool _deviceTemperatureSupported;
/**
Controller temperature in Celsius.
*/
public:
float _controllerTemperature;
/**
Device temperature in Celsius.
*/
public:
float _deviceTemperature;
public:
static const char* const  _CLASSNAME_FULL;
/**
Current device mode and logic controller.
*/
public:
std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > _currentProcess;


//methods:

/**
Update state.
Logic processes step.
*/
public:
virtual void step();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_6ce6d74f4936484fb21dcbc9f2b2d596_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_6ce6d74f4936484fb21dcbc9f2b2d596_INLINES_H
#define H_6ce6d74f4936484fb21dcbc9f2b2d596_INLINES_H

#endif // H_6ce6d74f4936484fb21dcbc9f2b2d596_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES