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
#ifndef H_1bcb52a90131fe0924008fee3f7993d2_H
#define H_1bcb52a90131fe0924008fee3f7993d2_H



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

class ModbusSerialRTUNetworkController
:  public virtual oldportal::fc::network::modbus::ModbusNetworkController
{
// constructors:
public:
ModbusSerialRTUNetworkController();
public:
ModbusSerialRTUNetworkController(std::shared_ptr< oldportal::fc::network::Network > network);


public:
virtual ~ModbusSerialRTUNetworkController();

// members:

public:
oldportal::fc::network::modbus::SerialPortSettings _port_settings;
public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
1. Init and open Modbus port.
2. Start background realtime network thread.
*/
public:
virtual void initHardware();



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


#endif // H_1bcb52a90131fe0924008fee3f7993d2_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_1bcb52a90131fe0924008fee3f7993d2_INLINES_H
#define H_1bcb52a90131fe0924008fee3f7993d2_INLINES_H

#endif // H_1bcb52a90131fe0924008fee3f7993d2_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES