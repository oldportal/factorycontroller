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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::fc::system::plugin::PluginRegistry::_CLASSNAME_FULL = "oldportal::fc::system::plugin::PluginRegistry";


void oldportal::fc::system::plugin::PluginRegistry::add(std::shared_ptr< oldportal::fc::system::plugin::Plugin > plugin)
{//BEGIN_efb0214276b2310e945069eb029f7724
    // add to list of plugins (if not added yet)
    bool exist = false;
    for (auto p : _plugins)
    {
        if (plugin == p || typeid(*p.get()) == typeid(*plugin.get()) )
        {
            exist = true;
            break;
        }
    }
    if (!exist) {
        _plugins.push_back(plugin);
    }

    // register available classes
    auto classes = plugin->get_supported_classes_list();
    for (auto class_name : classes)
    {
        _classes[class_name] = plugin;
    }
}//END_efb0214276b2310e945069eb029f7724

bool oldportal::fc::system::plugin::PluginRegistry::is_class_supported(std::string class_name)
{//BEGIN_bcf7f0f7d297edd041e577e788d8e89d
    auto plugin_pair = _classes.find(class_name);
    return (plugin_pair != _classes.end());
}//END_bcf7f0f7d297edd041e577e788d8e89d

std::shared_ptr< oldportal::fc::system::serialization::Serializable > oldportal::fc::system::plugin::PluginRegistry::load_class(std::string class_name)
{//BEGIN_11dbbacb52356fa4861e70a069ed4d8c
    auto plugin_pair = _classes.find(class_name);
    if (plugin_pair != _classes.end()) {
        // plugin found for the class
        return plugin_pair->second->load_class(class_name);
    }
    else {
        // class not found, return empty
        return std::shared_ptr< oldportal::fc::system::serialization::Serializable >();
    }
}//END_11dbbacb52356fa4861e70a069ed4d8c

void oldportal::fc::system::plugin::PluginRegistry::remove(std::shared_ptr< oldportal::fc::system::plugin::Plugin > plugin)
{//BEGIN_12d6dca7190a68fb48acc3fc688bbb53
    for(auto it = _classes.begin(); it != _classes.end(); )
        if(it->second == plugin || typeid(*it->second.get()) == typeid(*plugin.get()))
            it = _classes.erase(it);
        else
            ++it;

    _plugins.remove(plugin);
}//END_12d6dca7190a68fb48acc3fc688bbb53


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE