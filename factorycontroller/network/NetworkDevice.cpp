/*
*    This file is part of FactoryController project.
*    
*    FactoryController is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    FactoryController is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2016
*    dmogn@mail.ru
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::NetworkDevice::NetworkDevice()

{//BEGIN_cdd0d751faedb253d8c85ef546ebbedd

}//END_cdd0d751faedb253d8c85ef546ebbedd

oldportal::fc::network::NetworkDevice::NetworkDevice(std::weak_ptr< oldportal::fc::network::Network > network)

{//BEGIN_273e84bb6fb903466ceec820d3609da7
    _last_ping = std::chrono::high_resolution_clock::time_point::min();
    _last_response = std::chrono::high_resolution_clock::time_point::min();
}//END_273e84bb6fb903466ceec820d3609da7



oldportal::fc::network::NetworkDevice::~NetworkDevice()
{//BEGIN_5e4f14d5355f3501bcea974516620b98

}//END_5e4f14d5355f3501bcea974516620b98


std::chrono::high_resolution_clock::time_point oldportal::fc::network::NetworkDevice::getLastPing() const
{//BEGIN_70763944677c875c476da26a5179c3ce
    return _last_ping;
}//END_70763944677c875c476da26a5179c3ce

std::chrono::high_resolution_clock::time_point oldportal::fc::network::NetworkDevice::getLastResponse() const
{//BEGIN_098cc37b35a22b6e348005f92030631a
    return _last_response;
}//END_098cc37b35a22b6e348005f92030631a


std::string oldportal::fc::network::NetworkDevice::toString()
{//BEGIN_8811979f01fa1905caf4d72934ac86a2
    return (boost::format("NetworkDevice [ id: %i, description: %s ]") % _id % _description).str();
}//END_8811979f01fa1905caf4d72934ac86a2

void oldportal::fc::network::NetworkDevice::updateLastPing()
{//BEGIN_5a2efdefc6c24e959ebabb0c6d7af4cd
   _last_ping = std::chrono::high_resolution_clock::now();
}//END_5a2efdefc6c24e959ebabb0c6d7af4cd

void oldportal::fc::network::NetworkDevice::updateLastResponse()
{//BEGIN_52e8e70cfca58ebbff529828c4dc5f8f
   _last_response = std::chrono::high_resolution_clock::now();
}//END_52e8e70cfca58ebbff529828c4dc5f8f


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
