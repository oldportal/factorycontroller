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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController()

{//BEGIN_6724b29e7b540ba96d924367ee3d6b85

}//END_6724b29e7b540ba96d924367ee3d6b85

oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::NetworkController(network)
{//BEGIN_07e0f66a5c8adc2ca4ad385b32e14479
    _network = network;
}//END_07e0f66a5c8adc2ca4ad385b32e14479



oldportal::fc::network::modbus::ModbusNetworkController::~ModbusNetworkController()
{//BEGIN_d7d316a8510aff274bca8908a5a3b0b7
    if (_serial_port && _serial_port->is_open())
        _serial_port->close();
}//END_d7d316a8510aff274bca8908a5a3b0b7


void oldportal::fc::network::modbus::ModbusNetworkController::initHardware()
{//BEGIN_f8023113994496e435af338c650de451
    // init network time
    _network_time.init();

    // open serial port with reference to boost::asio::io_service _serial_port_io
    _serial_port = std::make_shared<boost::asio::serial_port>(_serial_port_io, _network->_serialPortPath);

    //TODO: set predefined settings
    // what baud rate do we communicate at
    boost::asio::serial_port_base::baud_rate BAUD(19200);
    // how big is each "packet" of data (default is 8 bits)
    boost::asio::serial_port_base::character_size CHARACTER_SIZE( 8 );
    // what flow control is used (default is none)
    boost::asio::serial_port_base::flow_control FLOW( boost::asio::serial_port_base::flow_control::none );
    // what parity is used (default is none)
    boost::asio::serial_port_base::parity PARITY( boost::asio::serial_port_base::parity::none );
    // how many stop bits are used (default is one)
    boost::asio::serial_port_base::stop_bits STOP( boost::asio::serial_port_base::stop_bits::one );

    _serial_port->set_option( BAUD );
    _serial_port->set_option( CHARACTER_SIZE );
    _serial_port->set_option( FLOW );
    _serial_port->set_option( PARITY );
    _serial_port->set_option( STOP );

    //TODO: handle open port errors

    //_serial_port.setPortName(_network->_serialPortPath);
    //_serial_port.open(QIODevice::ReadWrite);
}//END_f8023113994496e435af338c650de451

void oldportal::fc::network::modbus::ModbusNetworkController::processMessagePair(oldportal::fc::network::modbus::ModbusMessagePair& message)
{//BEGIN_9573ab2dbdd64b510691a2ff16c486b1
    //TODO: processMessagePair()
}//END_9573ab2dbdd64b510691a2ff16c486b1

void oldportal::fc::network::modbus::ModbusNetworkController::realtime_run()
{//BEGIN_28cef3745d943d472fa32591aa5d754b
    initHardware();

    // make thread self-owner:
    //this->moveToThread(this);

    if (!_serial_port || !_serial_port->is_open())
    {
        //TODO: report error
        return;
    }

    while (true)
    {
        //QThread::msleep(10);

        while (!_message_queue.empty())
        {
            auto message = _message_queue.front();
            //TODO: read modbus commnds queue and send, wait for response
            _message_queue.pop();
            //TODO: handle port errors
        }
    }
}//END_28cef3745d943d472fa32591aa5d754b


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
