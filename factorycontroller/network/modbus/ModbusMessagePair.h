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
#ifndef H_882fa2af205cedb8d28d8550b0d300f9_H
#define H_882fa2af205cedb8d28d8550b0d300f9_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Modbus RTU request frame and response frame data.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

struct ModbusMessagePair
{
// constructors:
public:
ModbusMessagePair();


// members:

public:
bool _is_received_ok;
/**
true if response with dynamic size (data section size readed from response).
*/
public:
bool _is_response_dynamic_size;
public:
bool _is_sent_ok;
public:
std::array< uint8_t, 256 > _received_buf;
public:
std::array< uint8_t, 256 > _send_buf;


//methods:

public:
bool checkResponseCRC();

public:
uint8_t getResponseMessageLength();

public:
void setCRC(uint8_t message_length);

public:
void setMessageAddress(uint16_t modbus_address);

public:
void setMessageFunction(uint8_t function_number);

public:
void setMessageLength(uint8_t message_length);



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace modbus


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_882fa2af205cedb8d28d8550b0d300f9_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_882fa2af205cedb8d28d8550b0d300f9_INLINES_H
#define H_882fa2af205cedb8d28d8550b0d300f9_INLINES_H

#endif // H_882fa2af205cedb8d28d8550b0d300f9_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES