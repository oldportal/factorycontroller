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
#ifndef H_1c569a58ca76cb5d525f8ff64b442fc9_H
#define H_1c569a58ca76cb5d525f8ff64b442fc9_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
 Maximum allowed motor temperature (in Celsius)
*/
namespace oldportal 
{
namespace fhe 
{
namespace hardware 
{

class HardwareDevice
:  public virtual oldportal::fhe::device::Device
{
// constructors:
public:
HardwareDevice();


public:
virtual ~HardwareDevice();

// members:

public:
bool _controllerTemperatureSupported;
public:
bool _deviceTemperatureSupported;
/**
Controller temperature in Celsius.
*/
public:
float _controllerTemperature;
/**
Device temperature in Celsius.
*/
public:
float _deviceTemperature;


//methods:

public:
static void controller_data_step(oldportal::fc::network::modbus::data::ControllerData& controller_data);

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
}// namespace hardware


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_1c569a58ca76cb5d525f8ff64b442fc9_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_1c569a58ca76cb5d525f8ff64b442fc9_INLINES_H
#define H_1c569a58ca76cb5d525f8ff64b442fc9_INLINES_H

#endif // H_1c569a58ca76cb5d525f8ff64b442fc9_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES