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

protected:
uint8_t _predicted_response_message_length;
protected:
uint8_t _request_message_length;
protected:
uint8_t _response_message_length;
public:
bool _is_broadcast_message;
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
std::array< uint8_t, MODBUS_MAX_PDU_LENGTH+1 > _received_buf;
public:
std::array< uint8_t, MODBUS_MAX_PDU_LENGTH+1 > _send_buf;


//methods:

/**
Calculate CRC ans set it at the end of the message.

message_length - Length of the frame from device address (buffer zero), but without CRC checksum.
*/
public:
void calculate_and_set_CRC(uint8_t message_length);

public:
bool checkResponseCRC();

public:
uint8_t getResponseMessageLength();

public:
void setHardResponseMessageLength(uint8_t message_length);

public:
void setRequestAddress(uint16_t modbus_address);

public:
void setRequestFunctionCode(uint8_t function_code_number);

public:
void setRequestFunctionSubcode(uint8_t function_subcode_number);

/**
Set length of the frame from device address (buffer zero), but without CRC checksum.
*/
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
/*
The function code received in the query is not an allowable action for
the slave. If a Poll Program Complete command was issued, this
code indicates that no program function preceded it.
*/
#define FC_MODBUS_EXCEPTION_CODE_ILLEGAL_FUNCTION 1
/**
The data address received in the query is not an allowable address
for the slave.
  */
#define FC_MODBUS_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS 2
/**
A value contained in the query data field is not an allowable value for
the slave.
*/
#define FC_MODBUS_EXCEPTION_CODE_ILLEGAL_DATA_VALUE 3
/**
An unrecoverable error occurred while the slave was attempting to
perform the requested action.
*/
#define FC_MODBUS_EXCEPTION_CODE_SLAVE_DEVICE_FAILURE 4
/**
The slave has accepted the request and is processing it, but a long
duration of time will be required to do so. This response is returned to
prevent a timeout error from occurring in the master. The master can
next issue a Poll Program Complete message to determine if
processing is completed.
*/
#define FC_MODBUS_EXCEPTION_CODE_ACKNOWLEDGE 5
/**
The slave is engaged in processing a long–dura
command. The master should retransmit the message later when the
slave is free.
*/
#define FC_MODBUS_EXCEPTION_CODE_SLAVE_DEVICE_BUSY 6
/**
The slave cannot perform the program function received in the query.
This code is returned for an unsuccessful programming request using
function code 13 or 14 decimal. The master should request diagnostic
or error information from the slave.
*/
#define FC_MODBUS_EXCEPTION_CODE_NEGATIVE_ACKNOWLEDGE 7
/**
The slave attempted to read extended memory, but detected a parity
error in the memory. The master can retry the request, but service
may be required on the slave device.
*/
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