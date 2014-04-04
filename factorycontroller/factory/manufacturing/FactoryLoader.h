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
#ifndef H_f8ca224a231cd1f12e5f14e6c6145372_H
#define H_f8ca224a231cd1f12e5f14e6c6145372_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace factory 
{
namespace manufacturing 
{

class FactoryLoader
{
// constructors:
public:
FactoryLoader();


public:
virtual ~FactoryLoader();

// members:

public:
std::u16string _name;


//methods:

public:
virtual std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > getExecutors() = 0;

public:
virtual std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > getNetworkControllers() = 0;

public:
virtual std::vector< std::shared_ptr<oldportal::fc::network::Network> > getNetworks() = 0;

public:
virtual std::shared_ptr< oldportal::fc::scheduler::Scheduler > getScheduler() = 0;

public:
virtual std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > getStorageManager() = 0;

/**
Init program loader.
*/
public:
virtual void init() = 0;



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace factory
}// namespace manufacturing


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_f8ca224a231cd1f12e5f14e6c6145372_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_f8ca224a231cd1f12e5f14e6c6145372_INLINES_H
#define H_f8ca224a231cd1f12e5f14e6c6145372_INLINES_H

#endif // H_f8ca224a231cd1f12e5f14e6c6145372_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES