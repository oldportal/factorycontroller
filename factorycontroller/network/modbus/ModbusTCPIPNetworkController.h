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
#ifndef H_bd6703c087f26dea38460672d40526f6_H
#define H_bd6703c087f26dea38460672d40526f6_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Connect with test modbus network emulator via Modbus over TCP/IP connection.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

class ModbusTCPIPNetworkController
:  public virtual oldportal::fc::network::modbus::ModbusNetworkController
{
// constructors:
public:
ModbusTCPIPNetworkController(std::shared_ptr< oldportal::fc::network::Network > network);


public:
virtual ~ModbusTCPIPNetworkController();

// members:

public:
oldportal::fc::network::modbus::TCPIPAddressSettings _address_settings;


//methods:

/**
Close realtime thread after queue empty.
*/
public:
virtual void close();

/**
Close and free _modbus_ctx context.
Set _modbus_ctx to nullptr.
*/
private:
void closeModbusContext();

public:
virtual void initHardware();

/**
Ping devices, for which timeout passed.

Maximum 1 device per step.
*/
private:
void pingDevicesStep();

protected:
virtual void processDeviceCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command);

public:
virtual void pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command);

private:
static void realtime_run(oldportal::fc::network::modbus::ModbusTCPIPNetworkController* controller);

/**
Update state.
Logic processes step.
*/
public:
virtual void step();

/**
Host time synchronization with devices, if timeout in settings passed.
*/
private:
void timeSynchronizationStep();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace modbus


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_bd6703c087f26dea38460672d40526f6_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_bd6703c087f26dea38460672d40526f6_INLINES_H
#define H_bd6703c087f26dea38460672d40526f6_INLINES_H

#endif // H_bd6703c087f26dea38460672d40526f6_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES