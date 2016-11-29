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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "factory-hardware-emulator.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fhe::EmulatorApplication::EmulatorApplication()

{//BEGIN_ea638a630e3f154ea1765cc75499beb9
    _device_time.init();
}//END_ea638a630e3f154ea1765cc75499beb9



oldportal::fhe::EmulatorApplication::~EmulatorApplication()
{//BEGIN_115cf4dbc8e7176e8418286d160f009d

}//END_115cf4dbc8e7176e8418286d160f009d


NETWORK_TIME oldportal::fhe::EmulatorApplication::getDeviceTime()
{//BEGIN_dedda9891bd731f76fc71b7d0093e1f8
    return _device_time.getCurrentNetworkTime();
}//END_dedda9891bd731f76fc71b7d0093e1f8


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE