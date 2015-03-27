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
#ifndef H_93eb4d2f06717e63c57eb5f94d7eda36_H
#define H_93eb4d2f06717e63c57eb5f94d7eda36_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION
#define CTRL_COMMANDFLOW_QUEUE_LENGTH 4
#define CTRL_COMMAND_MAX_CUSTOM_DATA_LENGTH 24
#define CTRL_COMMANDFLOW_RESULT_QUEUE_LENGTH 8
#define CTRL_COMMAND_RESULT_MAX_CUSTOM_DATA_LENGTH 16

typedef enum
{
	CTRL_COMMAND_RESULT_SUCCESS = 0
} ctrlCommandResultCode;
//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Command for real time scheduled execution in command flow.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace command 
{
namespace scheduled 
{

class ScheduledCommandRequest
{
// constructors:


// members:

public:
NETWORK_TIME _start_network_time;
public:
uint32_t _id;
/**
planned execution time in milliseconds
*/
public:
uint32_t _planned_execution_time;
public:
uint32_t _previous_command_id;
/**
queue number (individual for modbus device)
*/
public:
uint32_t _queue_number;
/**
command custom data
*/
public:
uint8_t _custom_data[CTRL_COMMAND_MAX_CUSTOM_DATA_LENGTH];
public:
uint8_t _type;


//methods:


//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace command
}// namespace scheduled


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_93eb4d2f06717e63c57eb5f94d7eda36_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_93eb4d2f06717e63c57eb5f94d7eda36_INLINES_H
#define H_93eb4d2f06717e63c57eb5f94d7eda36_INLINES_H

#endif // H_93eb4d2f06717e63c57eb5f94d7eda36_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES