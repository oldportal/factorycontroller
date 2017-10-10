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
#ifndef H_3c4c38701267fd476049629f313437fa_H
#define H_3c4c38701267fd476049629f313437fa_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
The general planned (TODO) command for the network device. Could keep real-time stamp for execution start.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{

class DeviceCommand
:  public std::enable_shared_from_this< oldportal::fc::network::DeviceCommand >
{
// constructors:
public:
DeviceCommand();
public:
DeviceCommand(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device);
public:
DeviceCommand(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process);


public:
virtual ~DeviceCommand();

// members:

protected:
bool _command_completed;
protected:
bool _result_success;
/**
System time in milliseconds.
*/
public:
std::chrono::high_resolution_clock::time_point _created;
/**
System time in milliseconds.
*/
public:
std::chrono::high_resolution_clock::time_point _last_processed;
/**
on_command_completed event callback function.
*/
public:
std::function< void(oldportal::fc::network::DeviceCommand * const, oldportal::fc::network::NetworkController * const) > _on_command_completed;
public:
std::shared_ptr< oldportal::fc::hardware::HardwareDevice > _device;
public:
std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > _device_process;
public:
std::shared_ptr< oldportal::fc::scheduler::ExecutorInterface > _executor;
public:
uint8_t _priority;


//methods:

public:
virtual void clear();

public:
bool is_command_completed() const;

public:
bool is_result_success() const;

/**
Handler.
Called after command processed. Called in main step thread.
*/
protected:
virtual void onProcessed();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION
friend class oldportal::fc::network::NetworkController;
//END_USER_SECTION_INSIDE_CLASS_DECLARATION


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