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
Modbus command number.
*/
protected:
uint8_t _command_number;


//methods:

public:
uint8_t get_command_number();



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace modbus


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_893c5f7a84c9f6c310f6a6e903ece71d_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_893c5f7a84c9f6c310f6a6e903ece71d_INLINES_H
#define H_893c5f7a84c9f6c310f6a6e903ece71d_INLINES_H

#endif // H_893c5f7a84c9f6c310f6a6e903ece71d_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES