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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusMessagePair::ModbusMessagePair()

{//BEGIN_ec0da4ab8c59963dd06b220481f2da85
    // flags:
    _is_response_dynamic_size = false;
    _is_received_ok = false;
    _is_sent_ok = false;
    _is_broadcast_message = false;
    // variables
    _response_message_length = 0;
    _request_message_length = 0;
    _predicted_response_message_length = 0;

    // clear data structures:
    for (auto& buf_byte : _received_buf)
        buf_byte = 0;
    for (auto& buf_byte : _send_buf)
        buf_byte = 0;
}//END_ec0da4ab8c59963dd06b220481f2da85


void oldportal::fc::network::modbus::ModbusMessagePair::calculate_and_set_CRC(uint8_t message_length)
{//BEGIN_4300ea1c4e1113846fd7fa4f2ad25c47
    assert(message_length >= FC_MODBUS_INTERFACE_FRAME_CHECK_HEADER_SIZE);
    assert(message_length <= MODBUS_RTU_MAX_ADU_LENGTH);

    boost::crc_16_type crc16sum;
    crc16sum.process_bytes(_send_buf.data(), message_length);
    uint16_t sum16 = crc16sum.checksum();
    //TODO: set sum16 after message

}//END_4300ea1c4e1113846fd7fa4f2ad25c47

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

void oldportal::fc::network::modbus::ModbusMessagePair::setHardResponseMessageLength(uint8_t message_length)
{//BEGIN_8c5fa50ebbb133befe0bf564c7a92ced
    assert(message_length >= FC_MODBUS_INTERFACE_FRAME_CHECK_HEADER_SIZE);

    _response_message_length = message_length;
    _predicted_response_message_length = message_length;
}//END_8c5fa50ebbb133befe0bf564c7a92ced

void oldportal::fc::network::modbus::ModbusMessagePair::setRequestAddress(uint16_t modbus_address)
{//BEGIN_27d1c6b8262657603a141b32939a314e
    assert (modbus_address <= 0xFF);

    _send_buf[FC_MODBUS_ADU_DEVICE_ADDRESS_SHIFT] = (uint8_t)modbus_address;
}//END_27d1c6b8262657603a141b32939a314e

void oldportal::fc::network::modbus::ModbusMessagePair::setRequestFunctionCode(uint8_t function_code_number)
{//BEGIN_9dcb234106ede48c1d7609cfd0dd245d
    _send_buf[FC_MODBUS_ADU_DEVICE_FUNCTION_CODE_SHIFT] =  function_code_number;
}//END_9dcb234106ede48c1d7609cfd0dd245d

void oldportal::fc::network::modbus::ModbusMessagePair::setRequestFunctionSubcode(uint8_t function_subcode_number)
{//BEGIN_4f16d035a7e1c6865e988038bd131740
    _send_buf[FC_MODBUS_ADU_DEVICE_FUNCTION_SUBCODE_SHIFT] =  function_subcode_number;
}//END_4f16d035a7e1c6865e988038bd131740

void oldportal::fc::network::modbus::ModbusMessagePair::setRequestLength(uint8_t message_length)
{//BEGIN_1d7e8bfe0b992b38f28de1ac061a9ec1
    assert(message_length >= FC_MODBUS_INTERFACE_FRAME_CHECK_HEADER_SIZE);

    _request_message_length = message_length;
}//END_1d7e8bfe0b992b38f28de1ac061a9ec1


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
