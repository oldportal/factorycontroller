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


oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::ModbusSerialRTUNetworkController()

{//BEGIN_1540738fb4e875afede8ad1c3eb3677c

}//END_1540738fb4e875afede8ad1c3eb3677c

oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::ModbusSerialRTUNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::modbus::ModbusNetworkController(network)
{//BEGIN_17140ab021ca3f2bd11e039871242a38
    assert(network && "ModbusSerialRTUNetworkController cannot be initialized with empty Network");

    _network = network;

    //oldportal::fc::system::log::error(u8"oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::ModbusSerialRTUNetworkController() initialization with network: " + network->_name);
}//END_17140ab021ca3f2bd11e039871242a38



oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::~ModbusSerialRTUNetworkController()
{//BEGIN_10f48711bd06cd04d26eed80dc27d4e2

}//END_10f48711bd06cd04d26eed80dc27d4e2


void oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::initHardware()
{//BEGIN_803ad91ba2984c5f99212c75897a3c72
    assert(_modbus_ctx == nullptr && !_realtime_thread && "ModbusSerialRTUNetworkController must be closed with close() before new initHardware() call");

    oldportal::fc::system::log::error(u8"oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::initHardware() call");

    // init network time
    _network_time.init();

    // settings example
    /*Set up arrays with the different possibilities for communications parameters */
    // port_name "/dev/ttyAMA0", "/dev/ttyUSB0"
    //int baud_rates[12] = {110, 300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400};
    //char parity[3] = {'N', 'E', 'O'};
    //int databits[2] ={7, 8};
    //int stopbits[2] = {1, 2};

    // set serial port name and settings
    _modbus_ctx = modbus_new_rtu(_port_settings._port_name.c_str(), _port_settings._baud_rate, _port_settings._parity, _port_settings._databits, _port_settings._stopbits);

    if (_modbus_ctx == nullptr)
    {
        oldportal::fc::system::log::error(u8"oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::initHardware() serial port create context error");
    }

    //Enable debugging for tests
    // modbus_set_debug(mb,TRUE);

    modbus_rtu_set_serial_mode(_modbus_ctx, MODBUS_RTU_RS485);
    // set to send request state
    //modbus_rtu_set_rts(_modbus_ctx, MODBUS_RTU_RTS_UP);

    if (modbus_connect(_modbus_ctx) != 0)
    {
        oldportal::fc::system::log::error(u8"oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::initHardware() serial port open error");
        oldportal::fc::system::log::error(modbus_strerror(errno));
        closeModbusContext();
        return;
    }

    oldportal::fc::system::log::log(u8"oldportal::fc::network::modbus::ModbusSerialRTUNetworkController::initHardware() serial port opened");

    initModbusSettings();

    initRealtimeThread();
}//END_803ad91ba2984c5f99212c75897a3c72


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE