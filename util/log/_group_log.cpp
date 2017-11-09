


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../util.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE




void oldportal::util::log::error_hardware(std::string topic, std::string message)
{//BEGIN_6910207d2b28a50a42e3e839b8bb9072
    std::cerr << "hardware error : " << topic << " : " << message << std::endl;
}//END_6910207d2b28a50a42e3e839b8bb9072

void oldportal::util::log::error_hardware(std::u16string topic, std::u16string message)
{//BEGIN_800c97372cf598b7068ec909a71dc920
    // convert to UTF-8
    std::cerr << "hardware error : " << oldportal::util::string::utf16_to_utf8(topic) << " : " << oldportal::util::string::utf16_to_utf8(message) << std::endl;
}//END_800c97372cf598b7068ec909a71dc920

void oldportal::util::log::log_hardware(std::string topic, std::string message)
{//BEGIN_f83f87f2822f02cd99b3ea68bf22e66b
    std::cout << "hardware log : " << topic << " : " << message << std::endl;
}//END_f83f87f2822f02cd99b3ea68bf22e66b

void oldportal::util::log::log_hardware(std::u16string topic, std::u16string message)
{//BEGIN_db589fffa24b544b46882ace395c7ee8
    // convert to UTF-8
    std::cout << "hardware log : " << oldportal::util::string::utf16_to_utf8(topic) << " : " << oldportal::util::string::utf16_to_utf8(message) << std::endl;
}//END_db589fffa24b544b46882ace395c7ee8



//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
