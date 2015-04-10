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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


log4cxx::LoggerPtr oldportal::fc::system::logger::root_logger;


void oldportal::fc::system::logger::error(std::string message)
{//BEGIN_b314fa6ad66678d1424326ea1ecea514
    std::cerr << message << std::endl;
}//END_b314fa6ad66678d1424326ea1ecea514

void oldportal::fc::system::logger::error(std::u16string message)
{//BEGIN_718a5be680c5cd3f2877db828f4b003d
    // convert to UTF-8
    std::cerr << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_718a5be680c5cd3f2877db828f4b003d

void oldportal::fc::system::logger::error(std::string topic, std::string message)
{//BEGIN_b39db29869dd05f377b890a63044aad8
    std::cerr << topic << " : " << message << std::endl;
}//END_b39db29869dd05f377b890a63044aad8

void oldportal::fc::system::logger::error(std::u16string topic, std::u16string message)
{//BEGIN_63f0235b80b0fd3d27380d6b38c2d947
    //std::wcerr << topic << L" : " << message << std::endl; - for widestring, obsolete

    // convert to UTF-8
    std::cerr << "hardware log : " << oldportal::fc::system::util::utf16_to_utf8(topic) << " : " << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_63f0235b80b0fd3d27380d6b38c2d947

void oldportal::fc::system::logger::error_hardware(std::string topic, std::string message)
{//BEGIN_7cc7907f2991739748563fc61fffed48
    std::cerr << "hardware error : " << topic << " : " << message << std::endl;
}//END_7cc7907f2991739748563fc61fffed48

void oldportal::fc::system::logger::error_hardware(std::u16string topic, std::u16string message)
{//BEGIN_2ff0cbbe3cf50e0d8392b7e58d227636
    // convert to UTF-8
    std::cerr << "hardware error : " << oldportal::fc::system::util::utf16_to_utf8(topic) << " : " << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_2ff0cbbe3cf50e0d8392b7e58d227636

void oldportal::fc::system::logger::log(std::string message)
{//BEGIN_b034dc6cf51407f73a74b6854e70a466
    std::cout << message << std::endl;
}//END_b034dc6cf51407f73a74b6854e70a466

void oldportal::fc::system::logger::log(std::u16string message)
{//BEGIN_52112f037e01c585c2baffcb7ba90875
    // convert to UTF-8
    std::cout << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_52112f037e01c585c2baffcb7ba90875

void oldportal::fc::system::logger::log(std::string topic, std::string message)
{//BEGIN_5b2146e1131feb320ab73025d505782c
    std::cout << topic << " : " << message << std::endl;
}//END_5b2146e1131feb320ab73025d505782c

void oldportal::fc::system::logger::log(std::u16string topic, std::u16string message)
{//BEGIN_4750c431f3e654aef752e5133ab34789
    // convert to UTF-8
    std::cout << oldportal::fc::system::util::utf16_to_utf8(topic) << " : " << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_4750c431f3e654aef752e5133ab34789

void oldportal::fc::system::logger::log_hardware(std::string topic, std::string message)
{//BEGIN_ee21dc1c4d309ca38ea32370452ebc7f
    std::cout << "hardware log : " << topic << " : " << message << std::endl;
}//END_ee21dc1c4d309ca38ea32370452ebc7f

void oldportal::fc::system::logger::log_hardware(std::u16string topic, std::u16string message)
{//BEGIN_8dc02bc4284321d5a7b60dfcc1b14992
    // convert to UTF-8
    std::cout << "hardware log : " << oldportal::fc::system::util::utf16_to_utf8(topic) << " : " << oldportal::fc::system::util::utf16_to_utf8(message) << std::endl;
}//END_8dc02bc4284321d5a7b60dfcc1b14992



//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE