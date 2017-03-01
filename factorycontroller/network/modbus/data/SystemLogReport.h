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
#ifndef H_85ee658f5aa520fd2fb3d9b0b46309e1_H
#define H_85ee658f5aa520fd2fb3d9b0b46309e1_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION
#define CONTROLLER_LOG_SIZE 10
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
namespace data 
{

class SystemLogReport
:  public virtual oldportal::fc::network::modbus::data::ModbusRegistersMapping
{
// constructors:
public:
SystemLogReport();


// members:

/**
error type
*/
public:
uint16_t _1_error_code;
/**
count of this error type reports
*/
public:
uint16_t _2_count;
/**
custom parameter value of last report
*/
public:
uint16_t _4_last_parameter;
/**
device time of this error type last report
*/
public:
uint32_t _3_last_time;


//methods:

public:
virtual void loadFromRegisterArray(const modbus_mapping_t* modbus_mapping);

public:
virtual void saveToRegisterArray(const modbus_mapping_t* modbus_mapping);



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


#endif // H_85ee658f5aa520fd2fb3d9b0b46309e1_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_85ee658f5aa520fd2fb3d9b0b46309e1_INLINES_H
#define H_85ee658f5aa520fd2fb3d9b0b46309e1_INLINES_H

#endif // H_85ee658f5aa520fd2fb3d9b0b46309e1_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES