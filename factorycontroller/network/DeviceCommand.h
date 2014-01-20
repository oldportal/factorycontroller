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
#ifndef H_3c4c38701267fd476049629f313437fa_H
#define H_3c4c38701267fd476049629f313437fa_H



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

class DeviceCommand
{
// constructors:


// members:

public:
std::shared_ptr< oldportal::fc::hardware::HardwareDevice > _device;
public:
uint8_t _priority;


//methods:

public:
virtual void onModbusResponse(oldportal::fc::network::modbus::ModbusMessagePair& modbusMessage, std::shared_ptr< oldportal::fc::network::modbus::ModbusNetworkController > controller) = 0;

/**
Executed direct in network driver's soft realtime thread while modbus response has been readed.

Be carefull to this function execution interval, use it only for short latency-critical tasks.
*/
public:
virtual void onRealTimeModbusResponse(oldportal::fc::network::modbus::ModbusMessagePair& modbusMessage, std::shared_ptr< oldportal::fc::network::modbus::ModbusNetworkController > controller);

public:
virtual void saveModbusMessage(oldportal::fc::network::modbus::ModbusMessagePair& modbusMessage) = 0;



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace network


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_3c4c38701267fd476049629f313437fa_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_3c4c38701267fd476049629f313437fa_INLINES_H
#define H_3c4c38701267fd476049629f313437fa_INLINES_H

#endif // H_3c4c38701267fd476049629f313437fa_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES