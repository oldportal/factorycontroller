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
#ifndef H_18546d14d29b0edd1f8fb866778581cc_H
#define H_18546d14d29b0edd1f8fb866778581cc_H



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
namespace welding 
{

class WeldingPowerSourceMode
{
// constructors:


// members:

public:
bool _ac_mode;
public:
bool _default_polarity;
public:
bool _impulse_mode;
public:
float _ac_rate;
/**
Continuous electric current or peak current for impulse mode.
*/
public:
float _current;
public:
float _impulse_rate;
public:
static const char* const  _CLASSNAME_FULL;
public:
std::string _description;
public:
std::string _name;


//methods:


//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware
}// namespace welding


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_18546d14d29b0edd1f8fb866778581cc_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_18546d14d29b0edd1f8fb866778581cc_INLINES_H
#define H_18546d14d29b0edd1f8fb866778581cc_INLINES_H

#endif // H_18546d14d29b0edd1f8fb866778581cc_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES