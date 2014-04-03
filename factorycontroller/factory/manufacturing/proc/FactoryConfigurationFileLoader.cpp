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
}//END_c037b730f87c52811d3fd00dd6c2693f



oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader::~FactoryConfigurationFileLoader()
{//BEGIN_1f0482e3d3ea6c7bd98d13887ab3eeeb

}//END_1f0482e3d3ea6c7bd98d13887ab3eeeb


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
    // open configuration file and load property_tree
    // load _configuration_filename

    boost::property_tree::ptree pt;

    //TODO: JSON and INFO support
    read_xml(_configuration_filename, pt);

    // init members:

    // network controllers:
    std::shared_ptr< oldportal::fc::network::Network > network = std::make_shared< oldportal::fc::network::Network >();

    std::shared_ptr< oldportal::fc::network::modbus::ModbusNetworkController > networkController = std::make_shared< oldportal::fc::network::modbus::ModbusNetworkController >();

    std::shared_ptr< oldportal::fc::network::modbus::ModbusDevice > networkDevice = std::make_shared< oldportal::fc::network::modbus::ModbusDevice >();

    // task schedulers:
    _scheduler = std::make_shared< oldportal::fc::scheduler::Scheduler >();

    // storage manager:
    _storage_manager = std::make_shared< oldportal::fc::factory::warehouse::StorageManager >();
}//END_5110e6763784e4dbb95a3c8e4ca572d3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
