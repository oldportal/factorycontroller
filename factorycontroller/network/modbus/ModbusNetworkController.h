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
#ifndef H_660aabb0543c047f551da3f514074cd4_H
#define H_660aabb0543c047f551da3f514074cd4_H



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

protected:
modbus_t* _modbus_ctx;
protected:
mutable bool _close_interrupted_flag;
protected:
mutable bool _run_thread_cycle_flag;
protected:
std::chrono::high_resolution_clock::time_point _last_time_synchronization;
protected:
std::shared_ptr< std::thread > _realtime_thread;
public:
oldportal::fc::network::modbus::ModbusNetworkSettings _network_settings;
public:
oldportal::fc::network::modbus::SerialPortSettings _port_settings;
public:
static const char* const  _CLASSNAME_FULL;


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
protected:
void closeModbusContext();

public:
modbus_t* getModbusContext() const;

/**
1. Init and open Modbus port.
2. Start background realtime network thread.
*/
public:
virtual void initHardware() = 0;

/**
1. Init and open Modbus port.
2. Start background realtime network thread.
*/
protected:
virtual void initModbusSettings();

/**
1. Init and open Modbus port.
2. Start background realtime network thread.
*/
protected:
virtual void initRealtimeThread();

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
protected:
void pingDevicesStep();

protected:
virtual void processDeviceCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command);

public:
virtual void pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command);

private:
static void realtime_run(oldportal::fc::network::modbus::ModbusNetworkController* const  controller);

/**
Update state.
Logic processes step.
*/
public:
virtual void step();

/**
Host time synchronization with devices, if timeout in settings passed.
*/
protected:
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


#endif // H_660aabb0543c047f551da3f514074cd4_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_660aabb0543c047f551da3f514074cd4_INLINES_H
#define H_660aabb0543c047f551da3f514074cd4_INLINES_H

#endif // H_660aabb0543c047f551da3f514074cd4_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES