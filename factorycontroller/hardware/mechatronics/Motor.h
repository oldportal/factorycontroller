/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*    
*    factorycontroller is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/
#ifndef H_b807739561474292e1b13d5f4f6a2523_H
#define H_b807739561474292e1b13d5f4f6a2523_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Axis rotation electric motor with smart controller.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace mechatronics 
{

class Motor
:  public virtual oldportal::fc::hardware::HardwareDevice
{
// constructors:
public:
Motor();


public:
virtual ~Motor();

// members:

public:
float _acceleration;
/**
Motor speed (motor must keep this speed). In RPMs.
*/
public:
float _speed;
/**
Motor torque (The motor must keep this torque value).
*/
public:
float _torque;
public:
oldportal::fc::hardware::mechatronics::MotorProperties _properties;
public:
oldportal::fc::hardware::mechatronics::MotorSettings _settings;


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
}// namespace mechatronics


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_b807739561474292e1b13d5f4f6a2523_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_b807739561474292e1b13d5f4f6a2523_INLINES_H
#define H_b807739561474292e1b13d5f4f6a2523_INLINES_H

#endif // H_b807739561474292e1b13d5f4f6a2523_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES