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
#ifndef H_27b01b8d0e674fd1dc735b761cacb3c7_H
#define H_27b01b8d0e674fd1dc735b761cacb3c7_H



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
namespace proc 
{

class FactoryConfigurationFileLoader
:  public virtual oldportal::fc::factory::manufacturing::FactoryLoader
{
// constructors:
public:
FactoryConfigurationFileLoader(const std::string& configuration_filename);


public:
virtual ~FactoryConfigurationFileLoader();

// members:

protected:
std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > _storage_manager;
protected:
std::shared_ptr< oldportal::fc::scheduler::Scheduler > _scheduler;
protected:
std::string _configuration_filename;
protected:
std::vector< std::shared_ptr<oldportal::fc::factory::manufacturing::proc::ConfigurationLoaderTagHandler > > _tag_handlers;
protected:
std::vector< std::shared_ptr<oldportal::fc::network::Network> > _networks;
protected:
std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > _network_controllers;
protected:
std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > _executors;


//methods:

public:
void addTagHandler(std::shared_ptr< oldportal::fc::factory::manufacturing::proc::ConfigurationLoaderTagHandler > tag_handler);

public:
virtual std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > getExecutors();

public:
virtual std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > getNetworkControllers();

public:
virtual std::vector< std::shared_ptr<oldportal::fc::network::Network> > getNetworks();

public:
virtual std::shared_ptr< oldportal::fc::scheduler::Scheduler > getScheduler();

public:
virtual std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > getStorageManager();

public:
virtual void init();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace factory
}// namespace manufacturing
}// namespace proc


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION
#define FC_LOGGER_TAG_SERIALIZATION (u8"serialization")
//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_27b01b8d0e674fd1dc735b761cacb3c7_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_27b01b8d0e674fd1dc735b761cacb3c7_INLINES_H
#define H_27b01b8d0e674fd1dc735b761cacb3c7_INLINES_H

#endif // H_27b01b8d0e674fd1dc735b761cacb3c7_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES