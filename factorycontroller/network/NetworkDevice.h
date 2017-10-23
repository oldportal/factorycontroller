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
#ifndef H_05ad12c1924072c4f513f05ccdcc1e00_H
#define H_05ad12c1924072c4f513f05ccdcc1e00_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Abstract industrial network slave device (terminal unit).
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{

class NetworkDevice
:  public std::enable_shared_from_this< oldportal::fc::network::NetworkDevice >
{
// constructors:
public:
NetworkDevice();
public:
NetworkDevice(std::weak_ptr< oldportal::fc::network::Network > network);


public:
virtual ~NetworkDevice();

// members:

protected:
std::chrono::high_resolution_clock::time_point _last_ping;
protected:
std::chrono::high_resolution_clock::time_point _last_response;
public:
boost::uuids::uuid _id;
public:
oldportal::fc::system::util::Counter _error_statistics;
public:
std::string _description;
public:
std::weak_ptr< oldportal::fc::network::Network > _network;


//methods:

public:
std::chrono::high_resolution_clock::time_point getLastPing() const;

public:
std::chrono::high_resolution_clock::time_point getLastResponse() const;

/**
Update state.
Logic processes step.
*/
public:
virtual void step() = 0;

public:
virtual std::string toString();

public:
void updateLastPing();

public:
void updateLastResponse();



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


#endif // H_05ad12c1924072c4f513f05ccdcc1e00_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_05ad12c1924072c4f513f05ccdcc1e00_INLINES_H
#define H_05ad12c1924072c4f513f05ccdcc1e00_INLINES_H

#endif // H_05ad12c1924072c4f513f05ccdcc1e00_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES