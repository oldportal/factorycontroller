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
std::array< uint8_t, MODBUS_MAX_PDU_LENGTH > _received_buf;
public:
std::array< uint8_t, MODBUS_MAX_PDU_LENGTH > _send_buf;


//methods:

public:
bool checkResponseCRC();

public:
uint8_t getResponseMessageLength();

public:
void setCRC(uint8_t message_length);

public:
void setRequestAddress(uint16_t modbus_address);

public:
void setRequestFunctionCode(uint8_t function_number);

public:
void setRequestLength(uint8_t message_length);



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

// Modbus functions:
#define FC_MODBUS_FUNC_READ_HOLDING_REGISTERS	0x03 //Read Holding Registers
#define FC_MODBUS_FUNC_READ_INPUT_REGISTERS	0x04 //Read Input Registers
#define FC_MODBUS_FUNC_WRITE_SINGLE_REGISTER	0x06 //Write Single Register
#define FC_MODBUS_FUNC_DIAGNOSTICS	0x08 //Diagnostics
#define FC_MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS	0x10 //Write Multiple Registers
#define FC_MODBUS_FUNC_REPORT_SLAVE_ID	0x11 //Report Slave ID
#define FC_MODBUS_FUNC_UTILITE	0x2B  // + 0x0E Read Device Identification

#define FC_MODBUS_FUNC_UTILITE_SUBCODE_READ_DEVICE_IDENTIFICATION 0x0E	// Read Device Identification

#define FC_MODBUS_FUNC_EXCEPTION_SHIFT 0x80

// application data unit (ADU) structure
// application data unit (ADU) include device address, protocol data unit (PDU), checksum
#define FC_MODBUS_ADU_DEVICE_ADDRESS_SHIFT 0
#define FC_MODBUS_ADU_DEVICE_FUNCTION_CODE_SHIFT 1
#define FC_MODBUS_ADU_DEVICE_FUNCTION_SUBCODE_SHIFT 2
#define FC_MODBUS_ADU_DEVICE_PDU_BEGIN_SHIFT 1

#define FC_MODBUS_INTERFACE_BROADBAND_DEVICE_NUMBER 0
#define FC_MODBUS_INTERFACE_FRAME_CHECK_HEADER_SIZE 3
#define FC_MODBUS_INTERFACE_FRAME_CHECK_ARRAY_SIZE 8

// maximum UART timeout in milliseconds
#define FC_MODBUS_INTERFACE_MAX_UART_TIMEOUT 100

// modbus exception codes
#define FC_MODBUS_EXCEPTION_CODE_ILLEGAL_FUNCTION 1
#define FC_MODBUS_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS 2
#define FC_MODBUS_EXCEPTION_CODE_ILLEGAL_DATA_VALUE 3
#define FC_MODBUS_EXCEPTION_CODE_SLAVE_DEVICE_FAILURE 4
#define FC_MODBUS_EXCEPTION_CODE_ACKNOWLEDGE 5
#define FC_MODBUS_EXCEPTION_CODE_MEMORY_PARITY_ERROR 8
#define FC_MODBUS_EXCEPTION_CODE_GATEWAY_PATH_UNAVAILABLE 0xA
#define FC_MODBUS_EXCEPTION_CODE_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND 0xB

// modbus registers
#define FC_MODBUS_HOLDING_REGISTERS_SHIFT 0x1000
#define FC_MODBUS_INPUT_REGISTERS_SHIFT 0x1000

#define FC_MODBUS_MAX_IO_RESISTERS_COUNT 0x007D

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_882fa2af205cedb8d28d8550b0d300f9_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_882fa2af205cedb8d28d8550b0d300f9_INLINES_H
#define H_882fa2af205cedb8d28d8550b0d300f9_INLINES_H

#endif // H_882fa2af205cedb8d28d8550b0d300f9_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES