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

//END_USER_SECTION_AFTER_MASTER_INCLUDE


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
    ret.push_back(u8"network.modbus.NetworkController");
    ret.push_back(u8"network.modbus.NetworkDevice");

    //TODO: getTagList()
    return ret;
}//END_fb14e05bde7d8c61534d44d1cc8846fa

void oldportal::fc::factory::manufacturing::proc::DefaultTagHandler::processElement(std::string tag_name, boost::property_tree::ptree& property_tree, boost::property_tree::ptree::value_type& element)
{//BEGIN_8628844f5d70f80ab3c49b37d2049b09
    //TODO: processElement()
}//END_8628844f5d70f80ab3c49b37d2049b09


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE