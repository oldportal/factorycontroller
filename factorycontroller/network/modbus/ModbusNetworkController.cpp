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
#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif
//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController()

{//BEGIN_6724b29e7b540ba96d924367ee3d6b85
    _close_interrupted_flag = false;
}//END_6724b29e7b540ba96d924367ee3d6b85

oldportal::fc::network::modbus::ModbusNetworkController::ModbusNetworkController(std::shared_ptr< oldportal::fc::network::Network > network)
    : oldportal::fc::network::NetworkController(network)
{//BEGIN_07e0f66a5c8adc2ca4ad385b32e14479
    _close_interrupted_flag = false;
    _network = network;
}//END_07e0f66a5c8adc2ca4ad385b32e14479



oldportal::fc::network::modbus::ModbusNetworkController::~ModbusNetworkController()
{//BEGIN_d7d316a8510aff274bca8908a5a3b0b7
    _run_thread_cycle_flag = false;
    _close_interrupted_flag = true;

    closeSerialPort();
}//END_d7d316a8510aff274bca8908a5a3b0b7


void oldportal::fc::network::modbus::ModbusNetworkController::close()
{//BEGIN_59b44143cde316021c103d93a2acb7fc
    _close_interrupted_flag = true;
}//END_59b44143cde316021c103d93a2acb7fc

void oldportal::fc::network::modbus::ModbusNetworkController::closeSerialPort()
{//BEGIN_1ee5c89496456a1159e90add755bcadc
    if (_serial_port && _serial_port->is_open())
    {
        _serial_port->close();
        _serial_port.reset();
    }
}//END_1ee5c89496456a1159e90add755bcadc

void oldportal::fc::network::modbus::ModbusNetworkController::initHardware()
{//BEGIN_f8023113994496e435af338c650de451
    // init network time
    _network_time.init();

    // open serial port with reference to boost::asio::io_service _serial_port_io
    oldportal::fc::system::logger::log(L"oldportal::fc::network::modbus::ModbusNetworkController::initHardware() open serial port...");
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

    oldportal::fc::system::logger::log(L"oldportal::fc::network::modbus::ModbusNetworkController::initHardware() serial port opened");

    // start soft realtime thread
    _run_thread_cycle_flag = true;
    _close_interrupted_flag = false;
    _realtime_thread = std::make_shared<std::thread>(oldportal::fc::network::modbus::ModbusNetworkController::realtime_run, this);

    // set realtime thread priority
#ifdef WIN32
    // WIN API
    // HIGH_PRIORITY_CLASS->REALTIME_PRIORITY_CLASS
    if (!SetPriorityClass(_realtime_thread->native_handle(), HIGH_PRIORITY_CLASS))
    // THREAD_PRIORITY_NORMAL->THREAD_PRIORITY_HIGHEST->THREAD_PRIORITY_TIME_CRITICAL
    if (!SetThreadPriority(_realtime_thread->native_handle(), THREAD_PRIORITY_TIME_CRITICAL))
    {
        DWORD dwError = GetLastError();
        std::cout << "cannot set modbus thread priority, error: " << dwError;
    }
#else
    // pthread library
    int policy;
    struct sched_param param;

    pthread_getschedparam(_realtime_thread->native_handle(), &policy, &param);
    // you would use policies SCHED_FIFO, SCHED_RR where you can specify HIGH priority of thread
    policy = SCHED_RR;
    param.sched_priority = sched_get_priority_max(policy);
    pthread_setschedparam(_realtime_thread->native_handle(), policy, &param);
#endif
}//END_f8023113994496e435af338c650de451

void oldportal::fc::network::modbus::ModbusNetworkController::processMessagePair(std::shared_ptr< oldportal::fc::network::modbus::ModbusMessagePair > message)
{//BEGIN_9573ab2dbdd64b510691a2ff16c486b1
    //TODO: processMessagePair()
    //TODO: read modbus commands queue and send, read response with timeout
    //TODO: handle port errors
}//END_9573ab2dbdd64b510691a2ff16c486b1

void oldportal::fc::network::modbus::ModbusNetworkController::realtime_run(oldportal::fc::network::modbus::ModbusNetworkController* controller)
{//BEGIN_28cef3745d943d472fa32591aa5d754b
    assert(controller);

    if (!controller->_serial_port || !controller->_serial_port->is_open())
    {
        //TODO: report error as error status
        oldportal::fc::system::logger::log(L"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() ERROR - serial port is not opened, thread stopping...");

        return;
    }
    oldportal::fc::system::logger::log(L"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() realtime thread started");

    while (controller->_run_thread_cycle_flag)
    {
        // main work, process messages
        while (!controller->_message_queue.empty())
        {
            auto message = controller->_message_queue.front();
            controller->processMessagePair(message);
            controller->_message_queue.pop();
        }

        // check for interruption and closing
        if (controller->_close_interrupted_flag)
        {
            oldportal::fc::system::logger::log(L"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() thread stopping...");
            controller->_run_thread_cycle_flag = false;
            controller->closeSerialPort();
            oldportal::fc::system::logger::log(L"oldportal::fc::network::modbus::ModbusNetworkController::realtime_run() thread stopped");
            return;
        }

        // sleep with chrono
        std::chrono::milliseconds sleep_duration( 1 );
        std::this_thread::sleep_for( sleep_duration );
    }
}//END_28cef3745d943d472fa32591aa5d754b


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE