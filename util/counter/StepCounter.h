
#ifndef H_5738930260b03d7e1a2127995c0182c8_H
#define H_5738930260b03d7e1a2127995c0182c8_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace util 
{
namespace counter 
{

class StepCounter
:  public virtual oldportal::util::counter::Counter
{
// constructors:
public:
StepCounter();


// members:

public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
check counter % divider == 0;
*/
public:
bool checkDivider(const uint32_t divider) const;

/**
check counter % divider == add;
*/
public:
bool checkDivider(const uint32_t divider, const uint32_t add) const;



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace util
}// namespace counter


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_5738930260b03d7e1a2127995c0182c8_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_5738930260b03d7e1a2127995c0182c8_INLINES_H
#define H_5738930260b03d7e1a2127995c0182c8_INLINES_H

#endif // H_5738930260b03d7e1a2127995c0182c8_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES