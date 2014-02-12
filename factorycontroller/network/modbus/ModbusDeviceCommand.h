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
#ifndef H_12b33b1f36b39bb0a1d4431491cc73ff_H
#define H_12b33b1f36b39bb0a1d4431491cc73ff_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
General planned (TO DO) command to network device. Could keep real-time stamp for execution start.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

class ModbusDeviceCommand
:  public virtual oldportal::fc::network::DeviceCommand
{
// constructors:
public:
ModbusDeviceCommand();


public:
virtual ~ModbusDeviceCommand();

// members:

public:
modbus_t* _modbus_ctx;


//methods:

/**
Handler.
Called after command processed. Called in main step thread.
*/
protected:
virtual void onProcessed();

/**
Process command to device in realtime background thread.
This handler must know about used protocol.

With Modbus this handler shold process request and response with libmodbus modbus_t context stored in  _modbus_ctx
*/
public:
virtual void process();



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace modbus


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_12b33b1f36b39bb0a1d4431491cc73ff_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_12b33b1f36b39bb0a1d4431491cc73ff_INLINES_H
#define H_12b33b1f36b39bb0a1d4431491cc73ff_INLINES_H

#endif // H_12b33b1f36b39bb0a1d4431491cc73ff_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES