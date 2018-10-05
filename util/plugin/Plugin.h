
#ifndef H_8cf4dcaa53ed088b2cfef83334246117_H
#define H_8cf4dcaa53ed088b2cfef83334246117_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Plugin interface.
*/
namespace oldportal 
{
namespace util 
{
namespace plugin 
{

class Plugin
{
// constructors:


// members:

public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
List of supported classes
*/
public:
virtual std::list< std::string > get_supported_classes_list() = 0;

/**
Is class supported check.
*/
public:
virtual bool is_supported(std::string class_name) = 0;

public:
virtual std::shared_ptr< oldportal::util::serialization::Serializable > load_class(std::string class_name) = 0;



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


#endif // H_8cf4dcaa53ed088b2cfef83334246117_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_8cf4dcaa53ed088b2cfef83334246117_INLINES_H
#define H_8cf4dcaa53ed088b2cfef83334246117_INLINES_H

#endif // H_8cf4dcaa53ed088b2cfef83334246117_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES