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


oldportal::fc::network::NetworkClock::NetworkClock()

{//BEGIN_e78e68ce2c9012b95739d0ad514a76fb
    _network_start_time = std::chrono::high_resolution_clock::now();
}//END_e78e68ce2c9012b95739d0ad514a76fb


NETWORK_TIME oldportal::fc::network::NetworkClock::getCurrentNetworkTime() const
{//BEGIN_900028361f6190d91a17f049b385701e
    std::chrono::high_resolution_clock::time_point current_time =
        std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - _network_start_time);
    NETWORK_TIME difference = time_span.count();
    return difference;
}//END_900028361f6190d91a17f049b385701e

std::chrono::high_resolution_clock::time_point oldportal::fc::network::NetworkClock::getStartTime() const
{//BEGIN_0ddc1cba7d9f96ed91788bbdb91cefb9
    return _network_start_time;
}//END_0ddc1cba7d9f96ed91788bbdb91cefb9

void oldportal::fc::network::NetworkClock::init()
{//BEGIN_9655658420dce1e6a0cd63336b820bdb
    _network_start_time = std::chrono::high_resolution_clock::now();
}//END_9655658420dce1e6a0cd63336b820bdb

NETWORK_TIME oldportal::fc::network::NetworkClock::toNetworkTime(std::chrono::high_resolution_clock::time_point system_time) const
{//BEGIN_6d4b3732f1bf4d75d39e536217883d27
    std::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(system_time - _network_start_time);
    NETWORK_TIME difference = time_span.count();
    return difference;
}//END_6d4b3732f1bf4d75d39e536217883d27

std::chrono::high_resolution_clock::time_point oldportal::fc::network::NetworkClock::toSystemTime(NETWORK_TIME network_time) const
{//BEGIN_08ceb6411a138ef839fc72ebdd751592
    return _network_start_time + std::chrono::milliseconds(network_time); // = _network_start_time + network_time;
}//END_08ceb6411a138ef839fc72ebdd751592


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE