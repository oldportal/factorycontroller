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

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::test::TestNetworkController::TestNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::NetworkController(network)
{//BEGIN_169badb0eee0d94f55cb0b833edc5814
    assert(network && "ModbusNetworkController cannot be initialized with empty Network");

    _run_thread_cycle_flag = false;
    _close_interrupted_flag = false;
    _network = network;

    _modbus_ctx = nullptr;
    _last_time_synchronization = std::chrono::high_resolution_clock::time_point::min();
}//END_169badb0eee0d94f55cb0b833edc5814



oldportal::fc::network::test::TestNetworkController::~TestNetworkController()
{//BEGIN_76058ff9472a91dd56c649daea129d31

}//END_76058ff9472a91dd56c649daea129d31


void oldportal::fc::network::test::TestNetworkController::close()
{//BEGIN_82eae4bef3672100ed4503365393c1a3
    // close() : empty
}//END_82eae4bef3672100ed4503365393c1a3

void oldportal::fc::network::test::TestNetworkController::closeModbusContext()
{//BEGIN_29990b7655690fb97186e69254b261de
    if (_modbus_ctx != nullptr)
    {
        modbus_close(_modbus_ctx);
        modbus_free(_modbus_ctx);

        _modbus_ctx = nullptr;
    }
}//END_29990b7655690fb97186e69254b261de

void oldportal::fc::network::test::TestNetworkController::initHardware()
{//BEGIN_303b6d9cb230b23ea149795bd0d06e69
    // initHardware() : empty
}//END_303b6d9cb230b23ea149795bd0d06e69

bool oldportal::fc::network::test::TestNetworkController::isOpened()
{//BEGIN_c5fe45cf55b71530564330f8205cd654
    return _modbus_ctx != nullptr && _realtime_thread;
}//END_c5fe45cf55b71530564330f8205cd654

void oldportal::fc::network::test::TestNetworkController::step()
{//BEGIN_ae97a14dc042da1bef1d2d3f62dd7c88
    oldportal::fc::network::NetworkController::step();
}//END_ae97a14dc042da1bef1d2d3f62dd7c88


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE