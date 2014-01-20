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
*    Copyright (C) Dmitry Ognyannikov, 2012
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE
#include <QDateTime>
//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::NetworkClock::NetworkClock()

{//BEGIN_e78e68ce2c9012b95739d0ad514a76fb
    _network_start_time = 0;
}//END_e78e68ce2c9012b95739d0ad514a76fb


uint64_t oldportal::fc::network::NetworkClock::getStartTime()
{//BEGIN_0ddc1cba7d9f96ed91788bbdb91cefb9
    return _network_start_time;
}//END_0ddc1cba7d9f96ed91788bbdb91cefb9

void oldportal::fc::network::NetworkClock::init()
{//BEGIN_9655658420dce1e6a0cd63336b820bdb
    _network_start_time = QDateTime::currentMSecsSinceEpoch();
}//END_9655658420dce1e6a0cd63336b820bdb

NETWORK_TIME oldportal::fc::network::NetworkClock::toNetworkTime(uint64_t system_time) const
{//BEGIN_cdcb1145f93e4fc57113862d59c118f3
    int64_t difference = system_time - _network_start_time;
    return difference;
}//END_cdcb1145f93e4fc57113862d59c118f3

uint64_t oldportal::fc::network::NetworkClock::toSystemTime(NETWORK_TIME network_time) const
{//BEGIN_08ceb6411a138ef839fc72ebdd751592
    return network_time + _network_start_time;
}//END_08ceb6411a138ef839fc72ebdd751592


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE