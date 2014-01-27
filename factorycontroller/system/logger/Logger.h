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
#ifndef H_8c3bd8eb4e6d6d86a9e524c02331bd92_H
#define H_8c3bd8eb4e6d6d86a9e524c02331bd92_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Additional loggong service:
- events log
- events aggregation by type.
*/
namespace oldportal 
{
namespace fc 
{
namespace system 
{
namespace logger 
{

class Logger
{
// constructors:
private:
Logger();


// members:

private:
static oldportal::fc::system::logger::Logger _logger;


//methods:

public:
static oldportal::fc::system::logger::Logger& getLogger();



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace system
}// namespace logger


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_8c3bd8eb4e6d6d86a9e524c02331bd92_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_8c3bd8eb4e6d6d86a9e524c02331bd92_INLINES_H
#define H_8c3bd8eb4e6d6d86a9e524c02331bd92_INLINES_H

#endif // H_8c3bd8eb4e6d6d86a9e524c02331bd92_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES