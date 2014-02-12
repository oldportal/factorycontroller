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
#ifndef H_3e0cd1cdd0a8e7729fa9e73d8a745c85_H
#define H_3e0cd1cdd0a8e7729fa9e73d8a745c85_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace erpconnector 
{

class Connector
{
// constructors:


// members:

public:
std::u16string _address;
public:
std::u16string _login;
public:
std::u16string _password;
public:
uint16_t _port;


//methods:

public:
const oldportal::fc::erpconnector::StateProxy* getStateProxy();

public:
const oldportal::fc::erpconnector::TaskProxy* getTaskProxy();



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace erpconnector


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_3e0cd1cdd0a8e7729fa9e73d8a745c85_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_3e0cd1cdd0a8e7729fa9e73d8a745c85_INLINES_H
#define H_3e0cd1cdd0a8e7729fa9e73d8a745c85_INLINES_H

#endif // H_3e0cd1cdd0a8e7729fa9e73d8a745c85_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES