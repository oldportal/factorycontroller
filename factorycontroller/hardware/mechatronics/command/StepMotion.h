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
#ifndef H_f5f32a6d6e4aa04d51bdb9d16897eb00_H
#define H_f5f32a6d6e4aa04d51bdb9d16897eb00_H



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
namespace command 
{

class StepMotion
:  public virtual oldportal::fc::network::modbus::ModbusDeviceCommand
{
// constructors:


public:
virtual ~StepMotion();

// members:


//methods:

/**
Process command to device in realtime background thread.
This handler must know about used protocol.

With Modbus this handler shold process request and response with libmodbus modbus_t context stored in  _modbus_ctx
*/
protected:
virtual void process();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware
}// namespace mechatronics
}// namespace command


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_f5f32a6d6e4aa04d51bdb9d16897eb00_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_f5f32a6d6e4aa04d51bdb9d16897eb00_INLINES_H
#define H_f5f32a6d6e4aa04d51bdb9d16897eb00_INLINES_H

#endif // H_f5f32a6d6e4aa04d51bdb9d16897eb00_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES