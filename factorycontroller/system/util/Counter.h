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
#ifndef H_cc4b7da06db87f0cbb6610643f91e08f_H
#define H_cc4b7da06db87f0cbb6610643f91e08f_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Industrial network error counter.
*/
namespace oldportal 
{
namespace fc 
{
namespace system 
{
namespace util 
{

class Counter
{
// constructors:
public:
Counter();


// members:

private:
std::atomic_uint_fast64_t _counter;


//methods:

/**
Reset counter to 0.
*/
public:
void clear();

/**
Get counter value.
*/
public:
uint64_t get() const;

public:
void increment();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace system
}// namespace util


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_cc4b7da06db87f0cbb6610643f91e08f_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_cc4b7da06db87f0cbb6610643f91e08f_INLINES_H
#define H_cc4b7da06db87f0cbb6610643f91e08f_INLINES_H

#endif // H_cc4b7da06db87f0cbb6610643f91e08f_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES