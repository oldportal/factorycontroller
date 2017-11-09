


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../util.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::util::counter::StepCounter::_CLASSNAME_FULL = "oldportal::util::counter::StepCounter";


oldportal::util::counter::StepCounter::StepCounter()

{//BEGIN_160f73f81374f577d41f76749977191c

}//END_160f73f81374f577d41f76749977191c


bool oldportal::util::counter::StepCounter::checkDivider(const uint32_t divider) const
{//BEGIN_a20b0836a1093704949ade58542efb3e
    return get() % divider == 0;
}//END_a20b0836a1093704949ade58542efb3e

bool oldportal::util::counter::StepCounter::checkDivider(const uint32_t divider, const uint32_t add) const
{//BEGIN_cd12e9d176305d7a82037e963536804e
    return get() % divider == add;
}//END_cd12e9d176305d7a82037e963536804e


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE