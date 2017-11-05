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
#ifndef H_35419d95bb002f341d69cb131c3ac997_H
#define H_35419d95bb002f341d69cb131c3ac997_H



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

class TCPIPAddressSettings
{
// constructors:
public:
TCPIPAddressSettings();


// members:

public:
static const char* const  _CLASSNAME_FULL;
/**
The _network_address variable specifies the host name or IP address of the host to connect to, eg. 192.168.0.5 , ::1 or server.com

Default value: "localhost"

Look function modbus_new_tcp_pi in libmodbus documentation for detailed description.
*/
public:
std::string _network_address;
/**
The _service variable is the service name/port number to connect to. To use the default Modbus port use the string "502". On many Unix systems, itï

Default value: "1502"

Look function modbus_new_tcp_pi in libmodbus documentation for detailed description.
*/
public:
std::string _service;


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


#endif // H_35419d95bb002f341d69cb131c3ac997_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_35419d95bb002f341d69cb131c3ac997_INLINES_H
#define H_35419d95bb002f341d69cb131c3ac997_INLINES_H

#endif // H_35419d95bb002f341d69cb131c3ac997_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES