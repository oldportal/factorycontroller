/*
*    This file is part of factory-hardware-emulator program and part of FactoryController project.
*    
*    factory-hardware-emulator is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    factory-hardware-emulator is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factory-hardware-emulator; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2014-2016
*    dmogn@mail.ru
*/
#ifndef H_d7159df8f6a3d1d69e63c82405cf616d_H
#define H_d7159df8f6a3d1d69e63c82405cf616d_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fhe 
{
namespace network 
{

class ModbusNetworkController
{
// constructors:
public:
ModbusNetworkController(std::weak_ptr< oldportal::fhe::EmulatorApplication > application);


public:
virtual ~ModbusNetworkController();

// members:

protected:
modbus_t* _modbus_ctx;
protected:
mutable bool _run_thread_cycle_flag;
protected:
mutable int _socket;
protected:
uint8_t* _query;
public:
std::weak_ptr< oldportal::fhe::EmulatorApplication > _application;


//methods:

public:
void close();

public:
modbus_t* getModbusContext();

public:
void init();

public:
void run();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fhe
}// namespace network


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_d7159df8f6a3d1d69e63c82405cf616d_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_d7159df8f6a3d1d69e63c82405cf616d_INLINES_H
#define H_d7159df8f6a3d1d69e63c82405cf616d_INLINES_H

#endif // H_d7159df8f6a3d1d69e63c82405cf616d_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES