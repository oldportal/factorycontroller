


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../util.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::util::plugin::PluginRegistry::_CLASSNAME_FULL = "oldportal::util::plugin::PluginRegistry";


void oldportal::util::plugin::PluginRegistry::add(std::shared_ptr< oldportal::util::plugin::Plugin > plugin)
{//BEGIN_d0c370d1ab29e93c3333e22c1bd624d6
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
}//END_d0c370d1ab29e93c3333e22c1bd624d6

bool oldportal::util::plugin::PluginRegistry::is_class_supported(std::string class_name)
{//BEGIN_7760672ff67000c196c051b1b3506d6c
    auto plugin_pair = _classes.find(class_name);
    return (plugin_pair != _classes.end());
}//END_7760672ff67000c196c051b1b3506d6c

std::shared_ptr< oldportal::util::serialization::Serializable > oldportal::util::plugin::PluginRegistry::load_class(std::string class_name)
{//BEGIN_200ae0d366a970a29fb39a26338dfb37
    auto plugin_pair = _classes.find(class_name);
    if (plugin_pair != _classes.end()) {
        // plugin found for the class
        return plugin_pair->second->load_class(class_name);
    }
    else {
        // class not found, return empty
        return std::shared_ptr< oldportal::util::serialization::Serializable >();
    }
}//END_200ae0d366a970a29fb39a26338dfb37

void oldportal::util::plugin::PluginRegistry::remove(std::shared_ptr< oldportal::util::plugin::Plugin > plugin)
{//BEGIN_d8673c5ee7a9fec5a3397893d11d5f6d
    for(auto it = _classes.begin(); it != _classes.end(); )
        if(it->second == plugin || typeid(*it->second.get()) == typeid(*plugin.get()))
            it = _classes.erase(it);
        else
            ++it;

    _plugins.remove(plugin);
}//END_d8673c5ee7a9fec5a3397893d11d5f6d


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE