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
#ifndef H_06a888ceb159a82535d1cdadd2767b5f_H
#define H_06a888ceb159a82535d1cdadd2767b5f_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fhe 
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

public:
bool _end_stoppers_enabled;
public:
bool _logic_limits_enabled;
public:
long _default_start_position;
public:
long _max_end_stopper_position;
public:
long _max_logic_position;
public:
long _min_end_stopper_position;
public:
long _min_logic_position;


//methods:


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


#endif // H_06a888ceb159a82535d1cdadd2767b5f_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_06a888ceb159a82535d1cdadd2767b5f_INLINES_H
#define H_06a888ceb159a82535d1cdadd2767b5f_INLINES_H

#endif // H_06a888ceb159a82535d1cdadd2767b5f_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES