/*
*    This file is part of FactoryController project.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
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
*    Copyright (C) Dmitry Ognyannikov, 2012-2016
*    dmogn@mail.ru
*/
#ifndef H_175d66dfe33102a889043fad55a4af45_H
#define H_175d66dfe33102a889043fad55a4af45_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

class SerialPortSettings
{
// constructors:
public:
SerialPortSettings();


// members:

/**
'N' = None
'E' = 
'O' = Odd
*/
public:
char _parity;
/**
System serial port name.

Unix/Linux examples:
"/dev/ttyUSB0", "/dev/ttyAMA0"

Windows examples:
"COM1" - "COM255"
*/
public:
std::string _port_name;
/**
Typical values:
{110, 300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400};
*/
public:
uint32_t _baud_rate;
/**
7 or 8 databits in transferred byte.
*/
public:
uint8_t _databits;
/**
1 or 2 stopbits.
*/
public:
uint8_t _stopbits;


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


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_175d66dfe33102a889043fad55a4af45_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_175d66dfe33102a889043fad55a4af45_INLINES_H
#define H_175d66dfe33102a889043fad55a4af45_INLINES_H

#endif // H_175d66dfe33102a889043fad55a4af45_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES