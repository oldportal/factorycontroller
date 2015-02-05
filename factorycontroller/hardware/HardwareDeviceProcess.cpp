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


oldportal::fc::hardware::HardwareDeviceProcess::HardwareDeviceProcess()

{//BEGIN_1a1b39c98ef1e25edf61bdde8f3f5ab1
    _attached = false;
}//END_1a1b39c98ef1e25edf61bdde8f3f5ab1



oldportal::fc::hardware::HardwareDeviceProcess::~HardwareDeviceProcess()
{//BEGIN_db997cad34bff219b67971894976e13d

}//END_db997cad34bff219b67971894976e13d


void oldportal::fc::hardware::HardwareDeviceProcess::detach()
{//BEGIN_3040b7242dcdfa439c3538de2c0e23d9
    //TODO: detach()
}//END_3040b7242dcdfa439c3538de2c0e23d9

bool oldportal::fc::hardware::HardwareDeviceProcess::isAttached()
{//BEGIN_dd31b8b98af2fe695c65a9718342cef8
    return _attached;
}//END_dd31b8b98af2fe695c65a9718342cef8


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE