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
#ifndef H_04ada1b308f6991ce58ebd9436194e05_H
#define H_04ada1b308f6991ce58ebd9436194e05_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

/* Register offsets in MODBUS registers count (2 bytes) */
#define STEPMRDRV_CALC_CONSTANTS_REGISTER_OFFSET_1_steps_per_revolution 0
#define STEPMRDRV_CALC_CONSTANTS_REGISTER_OFFSET_2_rotor_intertia 1
#define STEPMRDRV_CALC_CONSTANTS_REGISTER_OFFSET_3_moment_elasticity 2
#define STEPMRDRV_CALC_CONSTANTS_REGISTER_OFFSET_4_default_s_in_angle_steps 3

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Translation coefficients.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace welding 
{
namespace data 
{

struct WeldingDriverCalculationConstants
:  public virtual oldportal::fc::network::modbus::data::ModbusRegistersMapping
{
// constructors:
public:
WeldingDriverCalculationConstants();


// members:

public:
static const char* const  _CLASSNAME_FULL;


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
}// namespace welding
}// namespace data


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_04ada1b308f6991ce58ebd9436194e05_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_04ada1b308f6991ce58ebd9436194e05_INLINES_H
#define H_04ada1b308f6991ce58ebd9436194e05_INLINES_H

#endif // H_04ada1b308f6991ce58ebd9436194e05_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES