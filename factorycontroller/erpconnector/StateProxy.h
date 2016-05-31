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
#ifndef H_988ad57d0a6eff16f31563ddd0ef8157_H
#define H_988ad57d0a6eff16f31563ddd0ef8157_H



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

class StateProxy
{
// constructors:
protected:
StateProxy(std::shared_ptr< oldportal::fc::erpconnector::Connector > connector);


// members:

protected:
std::weak_ptr< oldportal::fc::erpconnector::Connector > _connector;


//methods:

public:
void reportExecutorState();

public:
void reportNetworkDeviceState();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace erpconnector


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_988ad57d0a6eff16f31563ddd0ef8157_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_988ad57d0a6eff16f31563ddd0ef8157_INLINES_H
#define H_988ad57d0a6eff16f31563ddd0ef8157_INLINES_H

#endif // H_988ad57d0a6eff16f31563ddd0ef8157_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES