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
*    Copyright (C) Dmitry Ognyannikov, 2012
*/
#ifndef H_6ce6d74f4936484fb21dcbc9f2b2d596_H
#define H_6ce6d74f4936484fb21dcbc9f2b2d596_H



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

class HardwareDevice
:  public oldportal::fc::network::modbus::ModbusDevice
{
// constructors:
public:
HardwareDevice();


// members:

public:
bool _controllerTemperatureSupported;
public:
bool _deviceTemperatureSupported;
public:
float _controllerTemperature;
public:
float _deviceTemperature;


//methods:

/**
Update state.
Logic processes step.
*/
public:
virtual void step();



//child groups:


//child classes:


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