/*
*    This file is part of factory-hardware-emulator program and part of FactoryController project.
*    
*    factory-hardware-emulator is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    factory-hardware-emulator is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factory-hardware-emulator; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2014-2016
*    dmogn@mail.ru
*/
#ifndef H_77feb5a37936fae508e72d629c5698b8_H
#define H_77feb5a37936fae508e72d629c5698b8_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
General motor emulation.
*/
namespace oldportal 
{
namespace fhe 
{
namespace hardware 
{
namespace mechatronics 
{

class Motor
:  public virtual oldportal::fhe::hardware::HardwareDevice
{
// constructors:
public:
Motor();


public:
virtual ~Motor();

// members:

protected:
std::chrono::high_resolution_clock::time_point _currentStepStartTime;
public:
long _current_position;
public:
oldportal::fhe::hardware::mechatronics::MotorModbus _modbus;
public:
oldportal::fhe::hardware::mechatronics::MotorSettings _settings;


//methods:

/**
Process Modbus request.
If message is not BROADCAST then send response.
*/
public:
void process_request(const uint8_t* request, const uint16_t request_length, const uint8_t slave_address, const uint8_t modbus_function, modbus_t* modbus_ctx);

public:
void servoCalculatePositionAndSpeed();

public:
void servoCalculateSpeedAndTorque();

public:
virtual void step();

protected:
void stepMotorSetNextStep(int8_t direction);

public:
virtual void stopAllDeviceActivity();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fhe
}// namespace hardware
}// namespace mechatronics


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_77feb5a37936fae508e72d629c5698b8_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_77feb5a37936fae508e72d629c5698b8_INLINES_H
#define H_77feb5a37936fae508e72d629c5698b8_INLINES_H

#endif // H_77feb5a37936fae508e72d629c5698b8_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES