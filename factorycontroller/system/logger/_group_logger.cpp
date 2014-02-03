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
*    Copyright (C) Dmitry Ognyannikov, 2012
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE




void oldportal::fc::system::logger::log(std::wstring message)
{//BEGIN_b034dc6cf51407f73a74b6854e70a466
    std::wcout << message << std::endl;
}//END_b034dc6cf51407f73a74b6854e70a466

void oldportal::fc::system::logger::log(std::wstring topic, std::wstring message)
{//BEGIN_5b2146e1131feb320ab73025d505782c
    std::wcout << topic << L" : " << message << std::endl;
}//END_5b2146e1131feb320ab73025d505782c

void oldportal::fc::system::logger::log_hardware(std::wstring topic, std::wstring message)
{//BEGIN_ee21dc1c4d309ca38ea32370452ebc7f
    std::wcout << L"hardware log : " << topic << L" : " << message << std::endl;
}//END_ee21dc1c4d309ca38ea32370452ebc7f



//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE