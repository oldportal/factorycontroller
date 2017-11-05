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
#ifndef H_893c5f7a84c9f6c310f6a6e903ece71d_H
#define H_893c5f7a84c9f6c310f6a6e903ece71d_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Modbus RTU mesage pair (request and response) general data wrapper.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

class ModbusMessageWrapper
{
// constructors:
public:
ModbusMessageWrapper(oldportal::fc::network::modbus::ModbusMessagePair* pair);


// members:

protected:
oldportal::fc::network::modbus::ModbusMessagePair* _pair;
/**
Modbus function code.
*/
protected:
uint8_t _function_code;
/**
Predefined response frame size for fixed size frame.

Minimum response frame size for dynamic size frame (with wariable data section size).
*/
protected:
uint8_t _response_minimum_length;
public:
static const char* const  _CLASSNAME_FULL;


//methods:

public:
uint8_t get_function_code();

public:
uint8_t get_response_minimum_length();



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

/* bitmasks */
#define MB_BITMASK_0 0x0001
#define MB_BITMASK_1 0x0002
#define MB_BITMASK_2 0x0004
#define MB_BITMASK_3 0x0008
#define MB_BITMASK_4 0x0010
#define MB_BITMASK_5 0x0020
#define MB_BITMASK_6 0x0040
#define MB_BITMASK_7 0x0080
#define MB_BITMASK_8 0x0100
#define MB_BITMASK_9 0x0200
#define MB_BITMASK_10 0x0400
#define MB_BITMASK_11 0x0800
#define MB_BITMASK_12 0x1000
#define MB_BITMASK_13 0x2000
#define MB_BITMASK_14 0x4000
#define MB_BITMASK_15 0x8000

/* HI LOW BYTE masks */
#define MB_LOW_BYTE_MASK 0x00FF
#define MB_HIGH_BYTE_MASK 0xFF00

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_893c5f7a84c9f6c310f6a6e903ece71d_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_893c5f7a84c9f6c310f6a6e903ece71d_INLINES_H
#define H_893c5f7a84c9f6c310f6a6e903ece71d_INLINES_H

#endif // H_893c5f7a84c9f6c310f6a6e903ece71d_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES