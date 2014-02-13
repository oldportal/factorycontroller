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
#ifndef H_ba0a2667edf60c6757785687f5801a3f_H
#define H_ba0a2667edf60c6757785687f5801a3f_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Network device state report.

Purposes:
- Ping device.
- Read device status.
- Read device errors.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace command 
{

class StateReport
:  public virtual oldportal::fc::network::modbus::ModbusDeviceCommand
{
// constructors:


public:
virtual ~StateReport();

// members:


//methods:

/**
Process command to device in realtime background thread.
This handler must know about used protocol.

With Modbus this handler shold process request and response with libmodbus modbus_t context stored in  _modbus_ctx
*/
public:
virtual void process();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace command


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_ba0a2667edf60c6757785687f5801a3f_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_ba0a2667edf60c6757785687f5801a3f_INLINES_H
#define H_ba0a2667edf60c6757785687f5801a3f_INLINES_H

#endif // H_ba0a2667edf60c6757785687f5801a3f_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES