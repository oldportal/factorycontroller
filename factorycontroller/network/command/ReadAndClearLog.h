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

class ReadAndClearLog
:  public virtual oldportal::fc::network::modbus::ModbusDeviceCommand
{
// constructors:
public:
ReadAndClearLog(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, oldportal::fc::network::modbus::data::SystemLogReport* log_records, uint16_t log_record_count = CONTROLLER_LOG_SIZE);


public:
virtual ~ReadAndClearLog();

// members:

public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
Process command to device in realtime background thread.
This handler must know about used protocol.

With Modbus this handler shold process request and response with libmodbus modbus_t context stored in  _modbus_ctx
*/
public:
virtual void process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller);



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