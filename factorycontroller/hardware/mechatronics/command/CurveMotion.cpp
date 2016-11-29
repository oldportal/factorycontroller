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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::hardware::mechatronics::command::CurveMotion::~CurveMotion()
{//BEGIN_ef2eb2a4a709629721d79b69aab3d7f9

}//END_ef2eb2a4a709629721d79b69aab3d7f9


void oldportal::fc::hardware::mechatronics::command::CurveMotion::onProcessed()
{//BEGIN_02604cd6a72fde0de5aa4ca4380fa438
    // empty
}//END_02604cd6a72fde0de5aa4ca4380fa438

void oldportal::fc::hardware::mechatronics::command::CurveMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_640ed55747407171dde65949e41b13d1
    assert(controller);
    assert(_device);
    assert(_device_process);
    //TODO:
}//END_640ed55747407171dde65949e41b13d1


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE