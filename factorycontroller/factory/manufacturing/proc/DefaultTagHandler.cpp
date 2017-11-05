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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::_CLASSNAME_FULL = "oldportal::fc::factory::manufacturing::proc::DefaultTagHandler";


oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::DefaultTagHandler()

{//BEGIN_6e9f7ce607e6782f6b048b5ba86ff2f5

}//END_6e9f7ce607e6782f6b048b5ba86ff2f5



oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::~DefaultTagHandler()
{//BEGIN_b3a7e3c7ecd42fdced50b62726e5eec0

}//END_b3a7e3c7ecd42fdced50b62726e5eec0


std::vector< std::string > oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::getTagList()
{//BEGIN_fb14e05bde7d8c61534d44d1cc8846fa
    std::vector< std::string > ret;

    // processed tags:
    ret.push_back(u8"network.Network");
    ret.push_back(u8"network.modbus.ModbusNetworkController");
    ret.push_back(u8"network.modbus.ModbusDevice");

    //TODO: getTagList() - add tags
    return ret;
}//END_fb14e05bde7d8c61534d44d1cc8846fa

void oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::processElement(std::string tag_name, boost::property_tree::ptree& root_ptree, boost::property_tree::ptree& element_ptree, oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader* loader, void* parentModelObject)
{//BEGIN_ff9d319bd3032866013c5741e7cf82a5
    assert(loader);
    assert(parentModelObject);

    if (tag_name == u8"network.Network")
    {
        LOG4CXX_TRACE(logger, "tag network.Network");
        processNetwork(tag_name, root_ptree, element_ptree, loader, parentModelObject);
    }
    else if (tag_name == u8"network.modbus.ModbusNetworkController")
    {
        LOG4CXX_TRACE(logger, "tag network.modbus.ModbusNetworkController");
        processNetworkController(tag_name, root_ptree, element_ptree, loader, parentModelObject);
    }
    else if (tag_name == u8"network.modbus.ModbusDevice")
    {
        LOG4CXX_TRACE(logger, "tag network.modbus.ModbusDevice");
        processModbusDevice(tag_name, root_ptree, element_ptree, loader, parentModelObject);
    }
}//END_ff9d319bd3032866013c5741e7cf82a5

void oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::processModbusDevice(std::string tag_name, boost::property_tree::ptree& root_ptree, boost::property_tree::ptree& element_ptree, oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader* loader, void* parentModelObject)
{//BEGIN_a171779b4305c997f5c6ee56b5d4a742
    assert(loader);
    assert(parentModelObject);
    assert (tag_name == u8"network.modbus.ModbusDevice");

    LOG4CXX_TRACE(logger, "processModbusDevice() call");

    //TODO: processElement()
}//END_a171779b4305c997f5c6ee56b5d4a742

void oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::processNetwork(std::string tag_name, boost::property_tree::ptree& root_ptree, boost::property_tree::ptree& element_ptree, oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader* loader, void* parentModelObject)
{//BEGIN_8628844f5d70f80ab3c49b37d2049b09
    assert(loader);
    assert(parentModelObject);
    assert (tag_name == u8"tag network.Network");

    LOG4CXX_TRACE(logger, "processNetwork() call");

    //TODO: processElement()
}//END_8628844f5d70f80ab3c49b37d2049b09

void oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::processNetworkController(std::string tag_name, boost::property_tree::ptree& root_ptree, boost::property_tree::ptree& element_ptree, oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader* loader, void* parentModelObject)
{//BEGIN_bdd3fa5da99ee98f06d1b53906a4f6b6
    assert(loader);
    assert(parentModelObject);
    assert (tag_name == u8"network.modbus.ModbusNetworkController");

    LOG4CXX_TRACE(logger, "processNetworkController() call");

    //TODO: processElement()
}//END_bdd3fa5da99ee98f06d1b53906a4f6b6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE