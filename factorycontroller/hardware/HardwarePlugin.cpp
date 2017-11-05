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


#include "../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::fc::hardware::HardwarePlugin::_CLASSNAME_FULL = "oldportal::fc::hardware::HardwarePlugin";


std::list< std::string > oldportal::fc::hardware::HardwarePlugin::get_supported_classes_list()
{//BEGIN_f957b7f83e42287cd373315aabb364a3
    std::list< std::string > ret = {
        oldportal::fc::hardware::edm::EDMPowerSource::_CLASSNAME_FULL,
        oldportal::fc::hardware::mechatronics::Motor::_CLASSNAME_FULL,
        oldportal::fc::hardware::metallurgy::InductionHeater::_CLASSNAME_FULL,
        oldportal::fc::hardware::power::PowerBus::_CLASSNAME_FULL,
        oldportal::fc::hardware::welding::proc::WeldingProcess::_CLASSNAME_FULL
    };
    return ret;
}//END_f957b7f83e42287cd373315aabb364a3

bool oldportal::fc::hardware::HardwarePlugin::is_supported(std::string class_name)
{//BEGIN_3eb533001a940634c0f5cffbd626f450
    std::list< std::string > classes = get_supported_classes_list();
    for (auto c : classes)
        if (c == class_name)
            return true;

    return false;
}//END_3eb533001a940634c0f5cffbd626f450

std::shared_ptr< oldportal::fc::system::serialization::Serializable > oldportal::fc::hardware::HardwarePlugin::load_class(std::string class_name)
{//BEGIN_51164ce62fc87552266d6072db87e353
    std::shared_ptr< oldportal::fc::system::serialization::Serializable > ret;
    //TODO: load_class()
    return ret;
}//END_51164ce62fc87552266d6072db87e353


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
