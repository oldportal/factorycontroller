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
#ifndef H_861355b4f15ffef9415bc66842c46794_H
#define H_861355b4f15ffef9415bc66842c46794_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Abstract Industrial Bus (Network) controller.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{

class NetworkController
{
// constructors:
public:
NetworkController();
public:
NetworkController(std::shared_ptr< oldportal::fc::network::Network > network);


public:
virtual ~NetworkController();

// members:

protected:
std::queue< std::shared_ptr<oldportal::fc::network::DeviceCommand> > _command_back_queue;
protected:
std::queue< std::shared_ptr<oldportal::fc::network::DeviceCommand> > _command_queue;
/**
Mutex for both command front (to execution) and back queues.
*/
protected:
std::recursive_mutex _command_queue_lock;
public:
oldportal::fc::network::NetworkClock _network_time;
public:
oldportal::fc::system::util::Counter _error_statistics;
public:
oldportal::fc::system::util::StepCounter _step_counter;
public:
std::shared_ptr< oldportal::fc::network::Network > _network;


//methods:

/**
Close realtime thread after queue empty.
*/
public:
virtual void close();

public:
virtual void initHardware() = 0;

public:
virtual void pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command);

/**
Update state.
Logic processes step.
*/
public:
virtual void step();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace network


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_861355b4f15ffef9415bc66842c46794_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_861355b4f15ffef9415bc66842c46794_INLINES_H
#define H_861355b4f15ffef9415bc66842c46794_INLINES_H

#endif // H_861355b4f15ffef9415bc66842c46794_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES