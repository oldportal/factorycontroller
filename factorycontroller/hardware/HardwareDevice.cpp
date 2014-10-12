/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*    
*    factorycontroller is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::hardware::HardwareDevice::HardwareDevice()

{//BEGIN_001b57e88de26f85c27fce08008e0dd8
    _controllerTemperatureSupported = false;
    _deviceTemperatureSupported = false;
    _controllerTemperature = 20;
    _deviceTemperature = 20;
}//END_001b57e88de26f85c27fce08008e0dd8



oldportal::fc::hardware::HardwareDevice::~HardwareDevice()
{//BEGIN_8519f1a5f484e96cc696a63a92d6029c

}//END_8519f1a5f484e96cc696a63a92d6029c


void oldportal::fc::hardware::HardwareDevice::step()
{//BEGIN_d42686e1ac956e97373c774ee3cd2a15
    // step() - empty virtual function
}//END_d42686e1ac956e97373c774ee3cd2a15


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE