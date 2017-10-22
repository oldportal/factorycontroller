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
#ifndef H_06e3bb8ea8a7bddc72babb54cf90ce79_H
#define H_06e3bb8ea8a7bddc72babb54cf90ce79_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Object with mapping internal variables to array of modbus protocol registers.
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

class ModbusRegistersMapping
{
// constructors:
public:
ModbusRegistersMapping();


// members:

/**
Registers count for save structure (structure size in array of registers).
*/
protected:
uint8_t _modbus_registers_sizeof;
public:
uint16_t _modbus_registers_start_index;


//methods:

public:
uint8_t getModbusRegistersSizeof();

/**
Load structure's data from modbus registers array.
*/
public:
virtual void loadFromRegisterArray(const modbus_mapping_t* modbus_mapping) = 0;

/**
Load structure's data from modbus registers array.

The structure's data starts from zero offset. Pointer registers represents the first register of the structure.
*/
public:
virtual void loadFromRegisterArray(const uint16_t* registers) = 0;

/**
Save structure's data from modbus registers array.
*/
public:
virtual void saveToRegisterArray(const modbus_mapping_t* modbus_mapping) = 0;

/**
Save structure's data from modbus registers array.

The structure's data starts from zero offset. Pointer registers represents the first register of the structure.
*/
public:
virtual void saveToRegisterArray(uint16_t* registers) = 0;



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


#endif // H_06e3bb8ea8a7bddc72babb54cf90ce79_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_06e3bb8ea8a7bddc72babb54cf90ce79_INLINES_H
#define H_06e3bb8ea8a7bddc72babb54cf90ce79_INLINES_H

#endif // H_06e3bb8ea8a7bddc72babb54cf90ce79_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES