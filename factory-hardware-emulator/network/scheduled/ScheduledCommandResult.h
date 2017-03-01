/*
*    This file is part of factory-hardware-emulator program and part of FactoryController project.
*    
*    factory-hardware-emulator is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    factory-hardware-emulator is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factory-hardware-emulator; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2014-2016
*    dmogn@mail.ru
*/
#ifndef H_0f6e4015274bfd80b54c5ad84bfe7a8b_H
#define H_0f6e4015274bfd80b54c5ad84bfe7a8b_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Result of command execution.
*/
namespace oldportal 
{
namespace fhe 
{
namespace network 
{
namespace scheduled 
{

class ScheduledCommandResult
{
// constructors:


// members:

public:
NETWORK_TIME _start_network_time;
public:
uint32_t _id;
public:
uint32_t _previous_command_id;
/**
queue number (individual for modbus device)
*/
public:
uint32_t _queue_number;
/**
esult execution time in milliseconds
*/
public:
uint32_t _result_execution_time;
/**
command custom result data
*/
public:
uint8_t _result_data[CTRL_COMMAND_RESULT_MAX_CUSTOM_DATA_LENGTH];
public:
uint8_t _type;


//methods:


//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fhe
}// namespace network
}// namespace scheduled


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_0f6e4015274bfd80b54c5ad84bfe7a8b_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_0f6e4015274bfd80b54c5ad84bfe7a8b_INLINES_H
#define H_0f6e4015274bfd80b54c5ad84bfe7a8b_INLINES_H

#endif // H_0f6e4015274bfd80b54c5ad84bfe7a8b_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES