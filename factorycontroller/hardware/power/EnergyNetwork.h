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
#ifndef H_6cd52159e3e2d4fd9e286cf9f6db7cbd_H
#define H_6cd52159e3e2d4fd9e286cf9f6db7cbd_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Internal energy network. 

Could unite different energy sources, power buses and energy accumulators.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace power 
{

class EnergyNetwork
:  public virtual oldportal::fc::hardware::HardwareDevice
{
// constructors:
public:
EnergyNetwork();


public:
virtual ~EnergyNetwork();

// members:


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
}// namespace power


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_6cd52159e3e2d4fd9e286cf9f6db7cbd_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_6cd52159e3e2d4fd9e286cf9f6db7cbd_INLINES_H
#define H_6cd52159e3e2d4fd9e286cf9f6db7cbd_INLINES_H

#endif // H_6cd52159e3e2d4fd9e286cf9f6db7cbd_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES