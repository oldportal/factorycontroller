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


public:
virtual ~DeviceCommand();

// members:

public:
std::shared_ptr< oldportal::fc::hardware::HardwareDevice > _device;
public:
std::shared_ptr< oldportal::fc::network::NetworkController > _controller;
public:
uint8_t _priority;


//methods:

/**
Handler.
Called after command processed. Called in main step thread.
*/
protected:
void onProcessed();

/**
Process command to device in realtime background thread.
This handler must know about used protocol.
*/
protected:
virtual void process() = 0;



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