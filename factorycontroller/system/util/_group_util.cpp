/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*    
*    factorycontroller is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

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




std::string oldportal::fc::system::util::utf16_to_utf8(std::u16string str)
{//BEGIN_3d547f9c3b2330d1817691e656ccf9fc
    std::string ret;
    utf8::utf16to8(str.begin(), str.end(), back_inserter(ret));
    return ret;
}//END_3d547f9c3b2330d1817691e656ccf9fc

std::wstring oldportal::fc::system::util::utf16_to_w(std::u16string str)
{//BEGIN_d2ce8c085033d64f043bbbf485cb97b2
    std::wstring ret;
    //TODO: utf16tow()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_d2ce8c085033d64f043bbbf485cb97b2

std::u16string oldportal::fc::system::util::utf8_to_utf16(std::string str)
{//BEGIN_32ad04e5d9aaf302986706cfc7bd9e9d
    std::u16string ret;
    utf8::utf8to16(str.begin(), str.end(), back_inserter(ret));
    return ret;
}//END_32ad04e5d9aaf302986706cfc7bd9e9d

std::wstring oldportal::fc::system::util::utf8_to_w(std::string str)
{//BEGIN_92e7469a5bf3d43f22c71e117a0250e9
    std::wstring ret;
    //TODO: utf8tow()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_92e7469a5bf3d43f22c71e117a0250e9

std::u16string oldportal::fc::system::util::w_to_utf16(std::wstring str)
{//BEGIN_5edddcf078a6f5690659ca82f9e1a83e
    std::u16string ret;
    //TODO: w_to_utf16()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_5edddcf078a6f5690659ca82f9e1a83e

std::string oldportal::fc::system::util::w_to_utf8(std::wstring str)
{//BEGIN_a0628645cca2e09a6cb46ad6b08b901d
    std::string ret;
    //TODO: wtoutf8()
    throw std::logic_error(std::string("Method is not implemented yet"));
    return ret;
}//END_a0628645cca2e09a6cb46ad6b08b901d



//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
