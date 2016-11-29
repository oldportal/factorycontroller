/*
*    This file is part of factory-hardware-emulator program and part of FactoryController project.
*    
*    factory-hardware-emulator is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    factory-hardware-emulator is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factory-hardware-emulator; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2014-2016
*    dmogn@mail.ru
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factory-hardware-emulator.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fhe::network::NetworkClock::NetworkClock()

{//BEGIN_6f95947f418e9c221a4abfc82016b70f
    _network_start_time = std::chrono::high_resolution_clock::now();
}//END_6f95947f418e9c221a4abfc82016b70f


NETWORK_TIME oldportal::fhe::network::NetworkClock::getCurrentNetworkTime() const
{//BEGIN_ffff45952ce001d921cead089e29ee87
    std::chrono::high_resolution_clock::time_point current_time =
        std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - _network_start_time);
    NETWORK_TIME difference = time_span.count();
    return difference;
}//END_ffff45952ce001d921cead089e29ee87

std::chrono::high_resolution_clock::time_point oldportal::fhe::network::NetworkClock::getStartTime()
{//BEGIN_83fcf6600c698b622b97a7b9ea24d821
    return _network_start_time;
}//END_83fcf6600c698b622b97a7b9ea24d821

void oldportal::fhe::network::NetworkClock::init()
{//BEGIN_269f8ef037622901c06ff3796f0f1685
    _network_start_time = std::chrono::high_resolution_clock::now();
}//END_269f8ef037622901c06ff3796f0f1685

NETWORK_TIME oldportal::fhe::network::NetworkClock::toNetworkTime(std::chrono::high_resolution_clock::time_point system_time) const
{//BEGIN_7d91143201cde1a74607ebd64e615c21
    std::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(system_time - _network_start_time);
    NETWORK_TIME difference = time_span.count();
    return difference;
}//END_7d91143201cde1a74607ebd64e615c21

std::chrono::high_resolution_clock::time_point oldportal::fhe::network::NetworkClock::toSystemTime(NETWORK_TIME network_time) const
{//BEGIN_e76ff613f5108fa0e31b4d373ae6d2f6
    return _network_start_time + std::chrono::milliseconds(network_time); // = _network_start_time + network_time;
}//END_e76ff613f5108fa0e31b4d373ae6d2f6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE