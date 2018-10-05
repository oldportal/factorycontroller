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
#ifndef H_015d1a9f745f45a5f192b7b08a78915a_H
#define H_015d1a9f745f45a5f192b7b08a78915a_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Motion from start speed to end position with acceleration rate.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace mechatronics 
{
namespace command 
{

class ToEndPositionMotion
:  public virtual oldportal::fc::network::modbus::ModbusDeviceCommand
{
// constructors:
public:
ToEndPositionMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process, float acceleration, float end_position);


public:
virtual ~ToEndPositionMotion();

// members:

private:
float _acceleration;
private:
float _end_position;
public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
Handler.
Called after command processed. Called in main step thread.
*/
protected:
virtual void onProcessed();

/**
Process command to device in realtime background thread.
This handler must know about used protocol.

With Modbus this handler shold process request and response with libmodbus modbus_t context stored in  _modbus_ctx
*/
protected:
virtual void process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller);



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware
}// namespace mechatronics
}// namespace command


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_015d1a9f745f45a5f192b7b08a78915a_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_015d1a9f745f45a5f192b7b08a78915a_INLINES_H
#define H_015d1a9f745f45a5f192b7b08a78915a_INLINES_H

#endif // H_015d1a9f745f45a5f192b7b08a78915a_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES