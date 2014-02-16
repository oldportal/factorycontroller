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
#ifndef H_1bcb52a90131fe0924008fee3f7993d2_H
#define H_1bcb52a90131fe0924008fee3f7993d2_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

class ModbusNetworkController
:  public virtual oldportal::fc::network::NetworkController
{
// constructors:
public:
ModbusNetworkController();
public:
ModbusNetworkController(std::shared_ptr< oldportal::fc::network::Network > network);


public:
virtual ~ModbusNetworkController();

// members:

private:
modbus_t* _modbus_ctx;
private:
mutable bool _close_interrupted_flag;
private:
mutable bool _run_thread_cycle_flag;
protected:
std::chrono::high_resolution_clock::time_point _last_time_synchronization;
protected:
std::shared_ptr< std::thread > _realtime_thread;
public:
oldportal::fc::network::modbus::ModbusNetworkSettings _network_settings;
public:
oldportal::fc::network::modbus::SerialPortSettings _port_settings;


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
modbus_t* getModbusContext();

/**
1. Init and open Modbus port.
2. Start background realtime network thread.
*/
public:
virtual void initHardware();

/**
Return true if serial port successfull opened and background realtime thread run.
Otherwise return false.
*/
public:
bool isOpened();

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
static void realtime_run(oldportal::fc::network::modbus::ModbusNetworkController* controller);

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


#endif // H_1bcb52a90131fe0924008fee3f7993d2_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_1bcb52a90131fe0924008fee3f7993d2_INLINES_H
#define H_1bcb52a90131fe0924008fee3f7993d2_INLINES_H

#endif // H_1bcb52a90131fe0924008fee3f7993d2_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES