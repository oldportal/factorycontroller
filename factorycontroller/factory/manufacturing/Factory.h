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
#ifndef H_98ee59666b249c214f9414fc44120404_H
#define H_98ee59666b249c214f9414fc44120404_H



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

class Factory
{
// constructors:
public:
Factory(std::shared_ptr< oldportal::fc::factory::manufacturing::FactoryLoader > loader);


public:
virtual ~Factory();

// members:

protected:
std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > _storage_manager;
protected:
std::shared_ptr< oldportal::fc::scheduler::Scheduler > _scheduler;
protected:
std::vector< std::shared_ptr<oldportal::fc::network::Network> > _networks;
protected:
std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > _network_controllers;
protected:
std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > _executors;


//methods:

public:
std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > getExecutors();

public:
std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > getNetworkControllers();

public:
std::vector< std::shared_ptr<oldportal::fc::network::Network> > getNetworks();

public:
std::shared_ptr< oldportal::fc::scheduler::Scheduler > getScheduler();

public:
std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > getStorageManager();

private:
void run();

/**
Start factory run in separate thread.
*/
public:
virtual void start();

/**
Update state.
Logic processes step.

main step cycle for all subcomponents.
*/
protected:
virtual void step();



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace factory
}// namespace manufacturing


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_98ee59666b249c214f9414fc44120404_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_98ee59666b249c214f9414fc44120404_INLINES_H
#define H_98ee59666b249c214f9414fc44120404_INLINES_H

#endif // H_98ee59666b249c214f9414fc44120404_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES