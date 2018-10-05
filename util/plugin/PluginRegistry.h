
#ifndef H_bd6b8ecb8c4010b1b02cd2750fc58327_H
#define H_bd6b8ecb8c4010b1b02cd2750fc58327_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Global refistry of available plugins.
*/
namespace oldportal 
{
namespace util 
{
namespace plugin 
{

class PluginRegistry
{
// constructors:


// members:

protected:
std::list< std::shared_ptr< oldportal::util::plugin::Plugin > > _plugins;
/**
Registered classes.
*/
protected:
std::map< std::string, std::shared_ptr< oldportal::util::plugin::Plugin > > _classes;
public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
Add plugin.
*/
public:
void add(std::shared_ptr< oldportal::util::plugin::Plugin > plugin);

/**
Is class supported check.
*/
public:
bool is_class_supported(std::string class_name);

public:
std::shared_ptr< oldportal::util::serialization::Serializable > load_class(std::string class_name);

/**
Remove plugin.
*/
public:
void remove(std::shared_ptr< oldportal::util::plugin::Plugin > plugin);



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace util
}// namespace plugin


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_bd6b8ecb8c4010b1b02cd2750fc58327_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_bd6b8ecb8c4010b1b02cd2750fc58327_INLINES_H
#define H_bd6b8ecb8c4010b1b02cd2750fc58327_INLINES_H

#endif // H_bd6b8ecb8c4010b1b02cd2750fc58327_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES