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
#ifndef H_239d8fbde27418a9ec3aaa0ab347d3ef_H
#define H_239d8fbde27418a9ec3aaa0ab347d3ef_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fhe 
{

class EmulatorApplication
{
// constructors:
public:
EmulatorApplication();


public:
virtual ~EmulatorApplication();

// members:

protected:
oldportal::fhe::network::NetworkClock _device_time;
public:
std::shared_ptr< oldportal::fhe::network::ModbusNetworkController > _network;
public:
std::vector< std::shared_ptr< oldportal::fhe::device::Device > > _devices;


//methods:

public:
NETWORK_TIME getDeviceTime();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fhe


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_239d8fbde27418a9ec3aaa0ab347d3ef_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_239d8fbde27418a9ec3aaa0ab347d3ef_INLINES_H
#define H_239d8fbde27418a9ec3aaa0ab347d3ef_INLINES_H

#endif // H_239d8fbde27418a9ec3aaa0ab347d3ef_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES