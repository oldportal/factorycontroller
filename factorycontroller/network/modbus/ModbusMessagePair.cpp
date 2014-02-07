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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

// Modbus functions:
#define MODBUS_FUNC_READ_HOLDING_REGISTERS	0x03 //Read Holding Registers
#define MODBUS_FUNC_READ_INPUT_REGISTERS	0x04 //Read Input Registers
#define MODBUS_FUNC_WRITE_SINGLE_REGISTER	0x06 //Write Single Register
#define MODBUS_FUNC_DIAGNOSTICS	0x08 //Diagnostics
#define MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS	0x10 //Write Multiple Registers
#define MODBUS_FUNC_REPORT_SLAVE_ID	0x11 //Report Slave ID
#define MODBUS_FUNC_UTILITE	0x2B  // + 0x0E Read Device Identification

#define MODBUS_FUNC_UTILITE_SUBCODE_READ_DEVICE_IDENTIFICATION 0x0E	// Read Device Identification

#define MODBUS_FUNC_EXCEPTION_SHIFT 0x80

// application data unit (ADU) structure
// application data unit (ADU) include device address, protocol data unit (PDU), checksum
#define MODBUS_ADU_DEVICE_ADDRESS_SHIFT 0
#define MODBUS_ADU_DEVICE_FUNCTION_CODE_SHIFT 1
#define MODBUS_ADU_DEVICE_FUNCTION_SUBCODE_SHIFT 2
#define MODBUS_ADU_DEVICE_PDU_BEGIN_SHIFT 1

#define MODBUS_INTERFACE_BROADBAND_DEVICE_NUMBER 0
#define MODBUS_INTERFACE_FRAME_CHECK_HEADER_SIZE 3
#define MODBUS_INTERFACE_FRAME_CHECK_ARRAY_SIZE 8

// maximum UART timeout in milliseconds
#define MODBUS_INTERFACE_MAX_UART_TIMEOUT 100

// modbus exception codes
#define MODBUS_EXCEPTION_CODE_ILLEGAL_FUNCTION 1
#define MODBUS_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS 2
#define MODBUS_EXCEPTION_CODE_ILLEGAL_DATA_VALUE 3
#define MODBUS_EXCEPTION_CODE_SLAVE_DEVICE_FAILURE 4
#define MODBUS_EXCEPTION_CODE_ACKNOWLEDGE 5
#define MODBUS_EXCEPTION_CODE_MEMORY_PARITY_ERROR 8
#define MODBUS_EXCEPTION_CODE_GATEWAY_PATH_UNAVAILABLE 0xA
#define MODBUS_EXCEPTION_CODE_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND 0xB

// modbus registers
#define MODBUS_HOLDING_REGISTERS_SHIFT 0x1000
#define MODBUS_INPUT_REGISTERS_SHIFT 0x1000

#define MODBUS_MAX_IO_RESISTERS_COUNT 0x007D

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusMessagePair::ModbusMessagePair()

{//BEGIN_ec0da4ab8c59963dd06b220481f2da85
    // flags:
    _is_response_dynamic_size = false;
    _is_received_ok = false;
    _is_sent_ok = false;

    // clear data structures:
    for (uint8_t& buf_byte : _received_buf)
        buf_byte = 0;
    for (uint8_t& buf_byte : _send_buf)
        buf_byte = 0;
}//END_ec0da4ab8c59963dd06b220481f2da85


bool oldportal::fc::network::modbus::ModbusMessagePair::checkResponseCRC()
{//BEGIN_6af82b8d8077d80fde78b23c5104b649
    uint8_t message_length = getResponseMessageLength();
    boost::crc_16_type crc16sum;
    crc16sum.process_bytes(_send_buf.data(), message_length);
    uint16_t sum16 = crc16sum.checksum();
    uint16_t *p_message_sum16 = (uint16_t *)(_received_buf.data()+message_length);

    return sum16 == *p_message_sum16;
}//END_6af82b8d8077d80fde78b23c5104b649

uint8_t oldportal::fc::network::modbus::ModbusMessagePair::getResponseMessageLength()
{//BEGIN_a3112b12fff85643440f7919f0706a64
    //TODO: getResponseMessageLength()
    return _received_buf[1];//temp, check!
}//END_a3112b12fff85643440f7919f0706a64

void oldportal::fc::network::modbus::ModbusMessagePair::setCRC(uint8_t message_length)
{//BEGIN_4300ea1c4e1113846fd7fa4f2ad25c47
    boost::crc_16_type crc16sum;
    crc16sum.process_bytes(_send_buf.data(), 250);
    //TODO: real data length
    uint16_t sum16 = crc16sum.checksum();
    //TODO: set sum16

    //TODO: setCRC()
}//END_4300ea1c4e1113846fd7fa4f2ad25c47

void oldportal::fc::network::modbus::ModbusMessagePair::setMessageAddress(uint16_t modbus_address)
{//BEGIN_27d1c6b8262657603a141b32939a314e
    //TODO: setMessageAddress()
}//END_27d1c6b8262657603a141b32939a314e

void oldportal::fc::network::modbus::ModbusMessagePair::setMessageFunction(uint8_t function_number)
{//BEGIN_9dcb234106ede48c1d7609cfd0dd245d
    //TODO: setMessageAddress()
}//END_9dcb234106ede48c1d7609cfd0dd245d

void oldportal::fc::network::modbus::ModbusMessagePair::setMessageLength(uint8_t message_length)
{//BEGIN_1d7e8bfe0b992b38f28de1ac061a9ec1
    //TODO: setCRC()
}//END_1d7e8bfe0b992b38f28de1ac061a9ec1


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE