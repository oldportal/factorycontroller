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


oldportal::fc::hardware::mechatronics::command::StopMotion::~StopMotion()
{//BEGIN_edd86cc0bfd363426f9f451e431a9666

}//END_edd86cc0bfd363426f9f451e431a9666


void oldportal::fc::hardware::mechatronics::command::StopMotion::onProcessed()
{//BEGIN_54ca0f1a3e69d91a3de9a722c200d309
    // empty
}//END_54ca0f1a3e69d91a3de9a722c200d309

void oldportal::fc::hardware::mechatronics::command::StopMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_24b28aceb4ccdcd30267159a4f322962
    assert(controller);
    assert(_device);
    assert(_device_process);

    auto motorDevice = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motorDevice);

    //TODO:
}//END_24b28aceb4ccdcd30267159a4f322962


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE