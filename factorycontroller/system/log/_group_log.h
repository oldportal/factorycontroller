/*
*    This file is part of FactoryController project.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
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
*    Copyright (C) Dmitry Ognyannikov, 2012-2016
*    dmogn@mail.ru
*/
#ifndef H_8da73644b7a2f25d63b322db774ac672_H
#define H_8da73644b7a2f25d63b322db774ac672_H




//BEGIN_GROUP_COMMENT
/**
*/
//END_GROUP_COMMENT


//BEGIN_USER_SECTION_0

//END_USER_SECTION_0


namespace oldportal 
{
namespace fc 
{
namespace system 
{
namespace log 
{
// global variables declaration
extern log4cxx::LoggerPtr logger;
}// namespace log
}// namespace system
}// namespace fc
}// namespace oldportal


namespace oldportal 
{
namespace fc 
{
namespace system 
{
namespace log 
{
// global methods declaration
void error(std::string message);

void error(std::u16string message);

void error(std::string topic, std::string message);

void error(std::u16string topic, std::u16string message);

void error_hardware(std::string topic, std::string message);

void error_hardware(std::u16string topic, std::u16string message);

void log(std::string message);

void log(std::u16string message);

void log(std::string topic, std::string message);

void log(std::u16string topic, std::u16string message);

void log_hardware(std::string topic, std::string message);

void log_hardware(std::u16string topic, std::u16string message);

}// namespace log
}// namespace system
}// namespace fc
}// namespace oldportal





#endif // H_8da73644b7a2f25d63b322db774ac672_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_8da73644b7a2f25d63b322db774ac672_INLINES_H
#define H_8da73644b7a2f25d63b322db774ac672_INLINES_H
//BEGIN_USER_SECTION_1

//END_USER_SECTION_1


#endif // H_8da73644b7a2f25d63b322db774ac672_INLINES_H

#endif //OBJECTS_BUILDER_PROJECT_INLINES