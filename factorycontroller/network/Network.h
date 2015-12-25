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
#ifndef H_c402d083c4b6b3a9b541662950cbc287_H
#define H_c402d083c4b6b3a9b541662950cbc287_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Industrial network. RS-485 as default.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{

class Network
{
// constructors:


// members:

public:
int64_t _id;
public:
std::string _serialPortPath;
public:
std::u16string _name;
public:
std::vector< std::shared_ptr<NetworkDevice> > _devices;
public:
std::weak_ptr< oldportal::fc::network::NetworkController > _controller;


//methods:


//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace network


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_c402d083c4b6b3a9b541662950cbc287_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_c402d083c4b6b3a9b541662950cbc287_INLINES_H
#define H_c402d083c4b6b3a9b541662950cbc287_INLINES_H

#endif // H_c402d083c4b6b3a9b541662950cbc287_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES