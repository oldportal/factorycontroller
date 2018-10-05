


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../util.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::util::counter::Counter::_CLASSNAME_FULL = "oldportal::util::counter::Counter";


oldportal::util::counter::Counter::Counter()

{//BEGIN_1a593d575f8655cf06d198bc7e5faf08
    _counter = ATOMIC_VAR_INIT(0);
}//END_1a593d575f8655cf06d198bc7e5faf08


void oldportal::util::counter::Counter::clear()
{//BEGIN_04c27ec3b10a91bfdf6505b4a4592ed1
    _counter = ATOMIC_VAR_INIT(0);
}//END_04c27ec3b10a91bfdf6505b4a4592ed1

uint64_t oldportal::util::counter::Counter::get() const
{//BEGIN_b3ecc4f496f0dcf2eb521ef4608aa8a7
    return _counter;
}//END_b3ecc4f496f0dcf2eb521ef4608aa8a7

void oldportal::util::counter::Counter::increment()
{//BEGIN_8827053f55557db9d6441c1afdb53c33
    _counter++;

    // value overflow check, (not true atomic)
    if (_counter >= UINT64_MAX-1001)
        _counter = ATOMIC_VAR_INIT(0);
}//END_8827053f55557db9d6441c1afdb53c33


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE