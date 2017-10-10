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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


log4cxx::LoggerPtr oldportal::fc::system::log::logger = log4cxx::Logger::getLogger("oldportal.fc.system.log");


void oldportal::fc::system::log::error_hardware(std::string topic, std::string message)
{//BEGIN_7cc7907f2991739748563fc61fffed48
    std::cerr << "hardware error : " << topic << " : " << message << std::endl;
}//END_7cc7907f2991739748563fc61fffed48

void oldportal::fc::system::log::error_hardware(std::u16string topic, std::u16string message)
{//BEGIN_2ff0cbbe3cf50e0d8392b7e58d227636
    // convert to UTF-8
    std::cerr << "hardware error : " << oldportal::fc::system::util::utf16_to_utf8(topic) << " : " << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_2ff0cbbe3cf50e0d8392b7e58d227636

void oldportal::fc::system::log::log_hardware(std::string topic, std::string message)
{//BEGIN_ee21dc1c4d309ca38ea32370452ebc7f
    std::cout << "hardware log : " << topic << " : " << message << std::endl;
}//END_ee21dc1c4d309ca38ea32370452ebc7f

void oldportal::fc::system::log::log_hardware(std::u16string topic, std::u16string message)
{//BEGIN_8dc02bc4284321d5a7b60dfcc1b14992
    // convert to UTF-8
    std::cout << "hardware log : " << oldportal::fc::system::util::utf16_to_utf8(topic) << " : " << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_8dc02bc4284321d5a7b60dfcc1b14992



//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE