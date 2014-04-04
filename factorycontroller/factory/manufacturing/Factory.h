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

private:
mutable bool _run_thread_cycle_flag;
protected:
std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > _storage_manager;
protected:
std::shared_ptr< oldportal::fc::scheduler::Scheduler > _scheduler;
protected:
std::shared_ptr< std::thread > _run_thread;
protected:
std::vector< std::shared_ptr<oldportal::fc::network::Network> > _networks;
protected:
std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > _network_controllers;
protected:
std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > _executors;
public:
oldportal::fc::system::util::StepCounter _step_counter;
public:
std::u16string _name;


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
static void run(oldportal::fc::factory::manufacturing::Factory* factory);

/**
Start factory run in separate thread.
*/
public:
virtual void start();

/**
Start factory run in separate thread.
*/
public:
virtual void startInNewThread();

/**
Update state.
Logic processes step.

main step cycle for all subcomponents.
*/
protected:
virtual void step();

public:
virtual void stop();



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


#endif // H_98ee59666b249c214f9414fc44120404_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_98ee59666b249c214f9414fc44120404_INLINES_H
#define H_98ee59666b249c214f9414fc44120404_INLINES_H

#endif // H_98ee59666b249c214f9414fc44120404_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES