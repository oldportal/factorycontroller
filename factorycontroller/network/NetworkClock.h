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
#ifndef H_586186b6874c506a9ac0916692599df9_H
#define H_586186b6874c506a9ac0916692599df9_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Time translation from network time to host system time.
*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{

struct NetworkClock
{
// constructors:
public:
NetworkClock();


// members:

/**
System time in milliseconds.
*/
private:
std::chrono::high_resolution_clock::time_point _network_start_time;


//methods:

public:
NETWORK_TIME getCurrentNetworkTime() const;

/**
Start time in system time,
*/
public:
std::chrono::high_resolution_clock::time_point getStartTime() const;

public:
void init();

public:
NETWORK_TIME toNetworkTime(std::chrono::high_resolution_clock::time_point system_time) const;

public:
std::chrono::high_resolution_clock::time_point toSystemTime(NETWORK_TIME network_time) const;



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


#endif // H_586186b6874c506a9ac0916692599df9_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_586186b6874c506a9ac0916692599df9_INLINES_H
#define H_586186b6874c506a9ac0916692599df9_INLINES_H

#endif // H_586186b6874c506a9ac0916692599df9_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES