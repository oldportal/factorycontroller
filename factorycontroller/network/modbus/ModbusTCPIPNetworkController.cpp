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


oldportal::fc::network::modbus::ModbusTCPIPNetworkController::ModbusTCPIPNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::modbus::ModbusNetworkController(network)
{//BEGIN_da7390f47b64c6919e1ad8426b698765
    assert(network && "ModbusTCPIPNetworkController cannot be initialized with empty Network");

    _network = network;

}//END_da7390f47b64c6919e1ad8426b698765



oldportal::fc::network::modbus::ModbusTCPIPNetworkController::~ModbusTCPIPNetworkController()
{//BEGIN_c14b688eeb561dc50dd75338cfd271b1

}//END_c14b688eeb561dc50dd75338cfd271b1


void oldportal::fc::network::modbus::ModbusTCPIPNetworkController::initHardware()
{//BEGIN_f919d3d7379153553fbea5b0aa2a6cd5
    assert(_modbus_ctx == nullptr && !_realtime_thread && "ModbusTCPIPNetworkController must be closed with close() before new initHardware() call");

    // init network time
    _network_time.init();

    std::string address = oldportal::fc::system::util::utf16_to_utf8(_address_settings._network_address);
    std::string service = oldportal::fc::system::util::utf16_to_utf8(_address_settings._service);

    _modbus_ctx = modbus_new_tcp_pi(address.c_str(), service.c_str());

    if (_modbus_ctx == nullptr)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusTCPIPNetworkController::initHardware() TCPIP port open error");
        oldportal::fc::system::logger::error(modbus_strerror(errno));
        closeModbusContext();
        return;
    }

    if (modbus_connect(_modbus_ctx) != 0)
    {
        oldportal::fc::system::logger::error(u8"oldportal::fc::network::modbus::ModbusTCPIPNetworkController::initHardware() TCPIP connect error");
        oldportal::fc::system::logger::error(modbus_strerror(errno));
        closeModbusContext();
        return;
    }

    oldportal::fc::system::logger::log(u8"oldportal::fc::network::modbus::ModbusTCPIPNetworkController::initHardware() connection opened");

    initModbusSettings();

    initRealtimeThread();
}//END_f919d3d7379153553fbea5b0aa2a6cd5


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE