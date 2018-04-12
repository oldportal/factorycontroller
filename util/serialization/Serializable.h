
#ifndef H_ab13ce61766d33b1b895956545b77902_H
#define H_ab13ce61766d33b1b895956545b77902_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Serializable interface
*/
namespace oldportal 
{
namespace util 
{
namespace serialization 
{

class Serializable
{
// constructors:


// members:

public:
static const char* const  _CLASSNAME_FULL;


//methods:

public:
virtual std::string get_id_as_string() const = 0;

public:
virtual void load(pugi::xml_node& node) = 0;

/**
Second phase of load - restore pointers to other objects.
*/
public:
virtual void load_restore_rependencies() = 0;

public:
virtual void save() = 0;



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace util
}// namespace serialization


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_ab13ce61766d33b1b895956545b77902_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_ab13ce61766d33b1b895956545b77902_INLINES_H
#define H_ab13ce61766d33b1b895956545b77902_INLINES_H

#endif // H_ab13ce61766d33b1b895956545b77902_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES