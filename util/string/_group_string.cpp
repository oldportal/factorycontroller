


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../util.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//#include <codecvt>
//#include <cuchar>

//#include <boost/locale.hpp>
#include "../../../foreign_libs/utf8.h"

// variant 1
//    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
//    std::string a = convert.to_bytes(u8"This string has UTF-16 content");

// variant 2
//    std::wstring_convert<std::codecvt_utf16<wchar_t, WCHAR_MAX, std::consume_header>, wchar_t> conv;
//    std::wstring ws = conv.from_bytes(reinterpret_cast<const char*> (&message[0]),
//            reinterpret_cast<const char*> (&message[s.size()]));
//    std::wcerr << ws << std::endl;

// variant 3
    // c16rtomb as variant

// variant 4 - Boost.Locale
    // Boost.Locale provides stream codepage conversion facets based on the std::codecvt facet. This allows conversion between wide-character encodings and 8-bit encodings like UTF-8, ISO-8859 or Shift-JIS.
    //std::string utf8_string = to_utf<char>(latin1_string,"Latin1");
    //std::wstring wide_string = to_utf<wchar_t>(latin1_string,"Latin1");
    //std::string utf8_string2 = utf_to_utf<char>(wide_string);
    //std::wstring s=to_utf<wchar_t>("string","UTF-8",stop);

// variant 5 - utf8 library
    // convert to UTF-8
    //std::string utf8message;
    //utf8::utf16to8(message.begin(), message.end(), back_inserter(utf8message));

//END_USER_SECTION_AFTER_MASTER_INCLUDE


log4cxx::LoggerPtr oldportal::util::string::logger = log4cxx::Logger::getLogger("oldportal.fc.system.util");


std::string oldportal::util::string::utf16_to_utf8(std::u16string str)
{//BEGIN_4ece007fa7bf98234b30dc3fab79f3c6
    std::string ret;
    utf8::utf16to8(str.begin(), str.end(), back_inserter(ret));
    return ret;
}//END_4ece007fa7bf98234b30dc3fab79f3c6

std::wstring oldportal::util::string::utf16_to_w(std::u16string str)
{//BEGIN_cefdfccdceff49ced1ce35bbe8f72609
    std::wstring ret;
    //TODO: utf16tow()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_cefdfccdceff49ced1ce35bbe8f72609

std::u16string oldportal::util::string::utf8_to_utf16(std::string str)
{//BEGIN_966fbd79f03b30d7051e7a6cec4c5692
    std::u16string ret;
    utf8::utf8to16(str.begin(), str.end(), back_inserter(ret));
    return ret;
}//END_966fbd79f03b30d7051e7a6cec4c5692

std::wstring oldportal::util::string::utf8_to_w(std::string str)
{//BEGIN_0ba79c68bd0dbe5c411977bd9a2443c4
    std::wstring ret;
    //TODO: utf8tow()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_0ba79c68bd0dbe5c411977bd9a2443c4

std::u16string oldportal::util::string::w_to_utf16(std::wstring str)
{//BEGIN_9a54740c1f7102187364b51eaf42fa3e
    std::u16string ret;
    //TODO: w_to_utf16()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_9a54740c1f7102187364b51eaf42fa3e

std::string oldportal::util::string::w_to_utf8(std::wstring str)
{//BEGIN_32be0cc4b8c5a08ce32d3596a7e99563
    std::string ret;
    //TODO: wtoutf8()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_32be0cc4b8c5a08ce32d3596a7e99563



//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE