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
#ifndef H_a3987fab79caf96c664ca98d3ced20a8_H
#define H_a3987fab79caf96c664ca98d3ced20a8_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Network device ID report.

Uses MODBUS_FUNC_REPORT_SLAVE_ID 0x11.

Purposes:
- Read device ID.
- Ping device availability.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace command 
{

class DeviceIDReport
:  public virtual oldportal::fc::network::modbus::ModbusDeviceCommand
{
// constructors:
public:
DeviceIDReport(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device);


public:
virtual ~DeviceIDReport();

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


#endif // H_a3987fab79caf96c664ca98d3ced20a8_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_a3987fab79caf96c664ca98d3ced20a8_INLINES_H
#define H_a3987fab79caf96c664ca98d3ced20a8_INLINES_H

#endif // H_a3987fab79caf96c664ca98d3ced20a8_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES