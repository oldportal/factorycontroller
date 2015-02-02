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
#ifndef H_57408c1b814796bff57529ad5ebaa1c3_H
#define H_57408c1b814796bff57529ad5ebaa1c3_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace mechatronics 
{

class MotorSettings
{
// constructors:
public:
MotorSettings();


// members:

/**
Maximum motor peak current (per phase).
*/
public:
float _max_peak_current;
public:
float _max_peak_current_enabled;
/**
Maximum motor speed. In RPMs.
*/
public:
float _max_speed;
/**
Maximum motor speed control. Disabled by default.
*/
public:
float _max_speed_enabled;
/**
Maximum motor temperature in celsuis degrees.
*/
public:
float _max_temperature;
/**
Maximum motor temperature in celsuis degrees.
Disabled by default.
*/
public:
float _max_temperature_enabled;
/**
Maximum motor angular torgue.
*/
public:
float _max_torque;
/**
Maximum motor angular torgue.
Disabled by default.
*/
public:
float _max_torque_enabled;
/**
temperature in celsius degrees
*/
public:
float _min_temperature;
/**
Disabled by default.
*/
public:
float _min_temperature_enabled;


//methods:


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


#endif // H_57408c1b814796bff57529ad5ebaa1c3_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_57408c1b814796bff57529ad5ebaa1c3_INLINES_H
#define H_57408c1b814796bff57529ad5ebaa1c3_INLINES_H

#endif // H_57408c1b814796bff57529ad5ebaa1c3_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES