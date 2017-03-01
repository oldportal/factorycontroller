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
#ifndef H_54cba4ce6e69d3b01260142da44601a1_H
#define H_54cba4ce6e69d3b01260142da44601a1_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Generic motor properties.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace mechatronics 
{

struct MotorProperties
{
// constructors:
public:
MotorProperties();


// members:

/**
Average system (supply) angular intertion.
*/
public:
float _average_system_inertion;
/**
The motor rotor angular intertion.
*/
public:
float _rotor_inertion;


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


#endif // H_54cba4ce6e69d3b01260142da44601a1_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_54cba4ce6e69d3b01260142da44601a1_INLINES_H
#define H_54cba4ce6e69d3b01260142da44601a1_INLINES_H

#endif // H_54cba4ce6e69d3b01260142da44601a1_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES