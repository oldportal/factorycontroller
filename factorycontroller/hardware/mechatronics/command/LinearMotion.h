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
#ifndef H_5441d7eb92c3cb580e4905056b5575df_H
#define H_5441d7eb92c3cb580e4905056b5575df_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

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

class LinearMotion
:  public virtual oldportal::fc::network::modbus::ModbusDeviceCommand
{
// constructors:
public:
LinearMotion(std::shared_ptr< oldportal::fc::network::NetworkDevice > device, float speed);


public:
virtual ~LinearMotion();

// members:

private:
float _speed;


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


#endif // H_5441d7eb92c3cb580e4905056b5575df_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_5441d7eb92c3cb580e4905056b5575df_INLINES_H
#define H_5441d7eb92c3cb580e4905056b5575df_INLINES_H

#endif // H_5441d7eb92c3cb580e4905056b5575df_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES