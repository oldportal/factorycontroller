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
#ifndef H_f77adeaed10a9e7f7df37115ab8aea50_H
#define H_f77adeaed10a9e7f7df37115ab8aea50_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
General modbus slave embedded device emulator.
*/
namespace oldportal 
{
namespace fhe 
{
namespace device 
{

class Device
{
// constructors:
public:
Device();


public:
virtual ~Device();

// members:

protected:
modbus_mapping_t* _modbus_mapping;
public:
uint8_t _modbus_address;


//methods:

/**
Process Modbus request.
If message is not BROADCAST then send response.
*/
public:
virtual void process_request(const uint8_t* request, const uint16_t request_length, const uint8_t slave_address, const uint8_t modbus_function, modbus_t* modbus_ctx) = 0;

public:
virtual void step() = 0;



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fhe
}// namespace device


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_f77adeaed10a9e7f7df37115ab8aea50_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_f77adeaed10a9e7f7df37115ab8aea50_INLINES_H
#define H_f77adeaed10a9e7f7df37115ab8aea50_INLINES_H

#endif // H_f77adeaed10a9e7f7df37115ab8aea50_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES