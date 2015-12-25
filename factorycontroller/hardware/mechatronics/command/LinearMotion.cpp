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


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::hardware::mechatronics::command::LinearMotion::~LinearMotion()
{//BEGIN_3ae7cbc70058cbc03bebf6e27865f011

}//END_3ae7cbc70058cbc03bebf6e27865f011


void oldportal::fc::hardware::mechatronics::command::LinearMotion::onProcessed()
{//BEGIN_25255f50ef0019f639443262727c6347
    // empty
}//END_25255f50ef0019f639443262727c6347

void oldportal::fc::hardware::mechatronics::command::LinearMotion::process(const oldportal::fc::network::modbus::ModbusNetworkController* controller)
{//BEGIN_5a4ca282f77a69d1fdd39facedaec3a6
    assert(controller);
    assert(_device);
    assert(_device_process);
    //TODO:
}//END_5a4ca282f77a69d1fdd39facedaec3a6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE