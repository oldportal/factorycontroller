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
#ifndef H_f39aab528265329710d1dd7649973a95_H
#define H_f39aab528265329710d1dd7649973a95_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
EDM power source settings preset.
- Impulse frequency.
- Pause time.
- Impulse current, in amperes.
- Impulse current form.
- Impulse polarity.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace edm 
{

class EDMWorkMode
{
// constructors:


// members:

public:
bool _default_polarity;
public:
bool _double_impulse_mode;
/**
Double impulse mode peak current (short impulse peak current over long base impulse).
*/
public:
float _double_impulse_current;
/**
Impulse frequency, in Hz.
*/
public:
float _frequency;
/**
Peak current for simple square impulse mode.

Low (base) current for double impulse mode (short impulse peaks over long base impulse).
*/
public:
float _impulse_current;
/**
Impulse length in seconds. 
Base (long) impulse length for double impulse mode.
*/
public:
float _impulse_length;
/**
Second (short) impulse length in double impulse mode, in seconds.

*/
public:
float _second_impulse_length;
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
}// namespace edm


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_f39aab528265329710d1dd7649973a95_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_f39aab528265329710d1dd7649973a95_INLINES_H
#define H_f39aab528265329710d1dd7649973a95_INLINES_H

#endif // H_f39aab528265329710d1dd7649973a95_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES