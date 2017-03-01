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
#ifndef H_cdaae8adcfdebbaa2e15cd3634d263b9_H
#define H_cdaae8adcfdebbaa2e15cd3634d263b9_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Modbus interface settings.

0000 = ??? ??????????, uint16_t
0001 = ?????? ??, uint16_t
0002 = MODBUS address, defaul = 1, uint16_t
0003 = ???????? ????????, defaul = 4800, uint16_t
0004 (MSB) = ????????: 
0 - no parity
1 - odd parity
2 - even parity
default = ?, uint8_t
0004 (LSB) = ???? ???:
1 = 1 ???? ???
2 = 2 ???? ????
default = ?, uint8_t
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{
namespace data 
{

class InterfaceSettings
{
// constructors:
public:
InterfaceSettings();


// members:

public:
uint16_t _1_device_type;
/**
controloler firmware version
*/
public:
uint16_t _2_firmware_version;
/**
MODBUS address
*/
public:
uint16_t _3_modbus_address;
/**
serial port speed
*/
public:
uint16_t _4_serial_speed;
/**
serial port parity (MSB): 
0 - no parity
1 - odd parity
2 - even parity
*/
public:
uint8_t _5_serial_parity;
/**
(LSB) = ???? ???:
1 = 1 ???? ???
2 = 2 ???? ????
default = ?, uint8_t
*/
public:
uint8_t _6_stop_bit;


//methods:


//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace modbus
}// namespace data


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_cdaae8adcfdebbaa2e15cd3634d263b9_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_cdaae8adcfdebbaa2e15cd3634d263b9_INLINES_H
#define H_cdaae8adcfdebbaa2e15cd3634d263b9_INLINES_H

#endif // H_cdaae8adcfdebbaa2e15cd3634d263b9_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES