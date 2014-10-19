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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/info_parser.hpp>
//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::FactoryConfigurationFileLoader(const std::string& configuration_filename)
    :   oldportal::fc::factory::manufacturing::FactoryLoader()
{//BEGIN_c037b730f87c52811d3fd00dd6c2693f
    _configuration_filename = configuration_filename;

    // add DefaultTagHandler
    std::shared_ptr< oldportal::fc::factory::manufacturing::proc::DefaultTagHandler > defaultTagHandler = std::make_shared< oldportal::fc::factory::manufacturing::proc::DefaultTagHandler >();
    addTagHandler(std::dynamic_pointer_cast< oldportal::fc::factory::manufacturing::proc::ConfigurationLoaderTagHandler >(defaultTagHandler));
}//END_c037b730f87c52811d3fd00dd6c2693f



oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::~FactoryConfigurationFileLoader()
{//BEGIN_1f0482e3d3ea6c7bd98d13887ab3eeeb

}//END_1f0482e3d3ea6c7bd98d13887ab3eeeb


void oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::addTagHandler(std::shared_ptr< oldportal::fc::factory::manufacturing::proc::ConfigurationLoaderTagHandler > tag_handler)
{//BEGIN_489331ee736bf8b1a2f4e78e3e5959a0
    // TagHandler class should be unigue
    // check for existing class with same type
    for (size_t i=0; i<_tag_handlers.size(); i++)
    //std::for_each(_tag_handlers.begin(), _tag_handlers.end(), )
    {
        if (typeid(_tag_handlers[i].get()) == typeid(tag_handler.get()))
            return;// do not add duplicated handler
    }

    // add TagHandler
    _tag_handlers.push_back(tag_handler);

    fc::system::logger::log(FC_LOGGER_TAG_SERIALIZATION, std::string(u8"added new TagHandler: ") + typeid(*tag_handler.get()).name());
}//END_489331ee736bf8b1a2f4e78e3e5959a0

std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::getExecutors()
{//BEGIN_35dc9994ce03b036850012793fb08c1e
    return _executors;
}//END_35dc9994ce03b036850012793fb08c1e

std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::getNetworkControllers()
{//BEGIN_c4430f402fbaa9ec643d23863d633559
    return _network_controllers;
}//END_c4430f402fbaa9ec643d23863d633559

std::vector< std::shared_ptr<oldportal::fc::network::Network> > oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::getNetworks()
{//BEGIN_7e7aa6fd48769d1d8d1c9d1f4393bfd5
    return _networks;
}//END_7e7aa6fd48769d1d8d1c9d1f4393bfd5

std::shared_ptr< oldportal::fc::scheduler::Scheduler > oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::getScheduler()
{//BEGIN_4b75b4b3ddcdee4f1789bedef5c37859
    return _scheduler;
}//END_4b75b4b3ddcdee4f1789bedef5c37859

std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::getStorageManager()
{//BEGIN_5cb2dba24094466df65e1a9f1d8bf118
    return _storage_manager;
}//END_5cb2dba24094466df65e1a9f1d8bf118

void oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::init()
{//BEGIN_5110e6763784e4dbb95a3c8e4ca572d3
    fc::system::logger::log(FC_LOGGER_TAG_SERIALIZATION, std::string(u8"FactoryConfigurationFileLoader init() with filename: ") + _configuration_filename);

    // open configuration file and load property_tree
    // load _configuration_filename

    boost::property_tree::ptree pt;

    //TODO: JSON and INFO support
    read_xml(_configuration_filename, pt);

    fc::system::logger::log(FC_LOGGER_TAG_SERIALIZATION, std::string(u8"FactoryConfigurationFileLoader init() property_tree loaded for parsing"));

    // load name
    std::string factory_name = pt.get<std::string>("name");
    _name = fc::system::util::utf8_to_utf16(factory_name);

    // load all child elements:
    for (boost::property_tree::ptree::iterator i = pt.begin(); i!=pt.end(); i++)
    {
        boost::property_tree::ptree::value_type &v = *i;
        //v.first
        //i->
        //std::string tag_name = i.
    }

    // init members:

    // TODO: recursive parsing of ptree
    //pt.get_child_optional()

    // network controllers:
    std::shared_ptr< oldportal::fc::network::Network > network = std::make_shared< oldportal::fc::network::Network >();

    std::shared_ptr< oldportal::fc::network::modbus::ModbusSerialRTUNetworkController > networkController = std::make_shared< oldportal::fc::network::modbus::ModbusSerialRTUNetworkController >(network);

    std::shared_ptr< oldportal::fc::hardware::HardwareDevice > networkDevice = std::make_shared< oldportal::fc::hardware::HardwareDevice >();

    // task schedulers:
    _scheduler = std::make_shared< oldportal::fc::scheduler::Scheduler >();

    // storage manager:
    _storage_manager = std::make_shared< oldportal::fc::factory::warehouse::StorageManager >();
}//END_5110e6763784e4dbb95a3c8e4ca572d3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE