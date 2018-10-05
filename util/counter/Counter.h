
#ifndef H_f8d4712af442bb5f1688eabb1cd75689_H
#define H_f8d4712af442bb5f1688eabb1cd75689_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Industrial network error counter.
*/
namespace oldportal 
{
namespace util 
{
namespace counter 
{

class Counter
{
// constructors:
public:
Counter();


// members:

private:
std::atomic_uint_fast64_t _counter;
public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
Reset counter to 0.
*/
public:
void clear();

/**
Get counter value.
*/
public:
uint64_t get() const;

public:
void increment();



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


#endif // H_f8d4712af442bb5f1688eabb1cd75689_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_f8d4712af442bb5f1688eabb1cd75689_INLINES_H
#define H_f8d4712af442bb5f1688eabb1cd75689_INLINES_H

#endif // H_f8d4712af442bb5f1688eabb1cd75689_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES