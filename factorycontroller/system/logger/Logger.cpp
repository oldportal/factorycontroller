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


oldportal::fc::system::logger::Logger oldportal::fc::system::logger::Logger::_logger;


oldportal::fc::system::logger::Logger::Logger()

{//BEGIN_3af28e0c9ceeed3a2eaadfc72e55240a

}//END_3af28e0c9ceeed3a2eaadfc72e55240a


oldportal::fc::system::logger::Logger& oldportal::fc::system::logger::Logger::getLogger()
{//BEGIN_cd3f2d455e614e6b06dcb61c6291081a
    return _logger;
}//END_cd3f2d455e614e6b06dcb61c6291081a

void oldportal::fc::system::logger::Logger::log(std::wstring message)
{//BEGIN_ec9c85481810a08da0714832a779e4d8
    //TODO: log()
}//END_ec9c85481810a08da0714832a779e4d8

void oldportal::fc::system::logger::Logger::log(std::wstring topic, std::wstring message)
{//BEGIN_e9bb0a3f97bd0a79b797dcfe01c2eb0c
    //TODO: log()
}//END_e9bb0a3f97bd0a79b797dcfe01c2eb0c

void oldportal::fc::system::logger::Logger::log_hardware(std::wstring topic, std::wstring message)
{//BEGIN_bf781f62d454fd34bea3f6ebce27c35a
    //TODO: log()
}//END_bf781f62d454fd34bea3f6ebce27c35a


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE