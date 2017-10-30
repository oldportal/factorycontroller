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
#ifndef H_2c43b80034c6892a508d0bfada839428_H
#define H_2c43b80034c6892a508d0bfada839428_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Modbus register mapping for power line device.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace power 
{
namespace data 
{

class PowerLineModbus
:  public virtual oldportal::fc::network::modbus::data::ModbusRegistersMapping
{
// constructors:
public:
PowerLineModbus();


// members:

public:
oldportal::fc::hardware::power::data::PowerLineDriverCalculationConstants _driverCalculationConstants;
public:
oldportal::fc::hardware::power::data::PowerLineDriverData _driverData;
public:
oldportal::fc::hardware::power::data::PowerLineDriverDataInput _driverDataInput;
public:
oldportal::fc::network::modbus::data::ControllerData _controllerData;
public:
oldportal::fc::network::modbus::data::InterfaceSettings _1_interface;
public:
oldportal::fc::network::modbus::data::SystemLogReport _systemLog[CONTROLLER_LOG_SIZE];


//methods:

/**
Load structure's data from modbus registers array.
*/
public:
virtual void loadFromRegisterArray(const modbus_mapping_t* modbus_mapping);

/**
Load structure's data from modbus registers array.
The structure's data starts from zero offset. Pointer registers represents the first register of the structure.
*/
public:
virtual void loadFromRegisterArray(const uint16_t* registers);

/**
Save structure's data from modbus registers array.
*/
public:
virtual void saveToRegisterArray(const modbus_mapping_t* modbus_mapping);

/**
Save structure's data from modbus registers array.

The structure's data starts from zero offset. Pointer registers represents the first register of the structure.
*/
public:
virtual void saveToRegisterArray(uint16_t* registers);



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware
}// namespace power
}// namespace data


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_2c43b80034c6892a508d0bfada839428_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_2c43b80034c6892a508d0bfada839428_INLINES_H
#define H_2c43b80034c6892a508d0bfada839428_INLINES_H

#endif // H_2c43b80034c6892a508d0bfada839428_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES