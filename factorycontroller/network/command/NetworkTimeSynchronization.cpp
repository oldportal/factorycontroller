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


oldportal::fc::network::command::NetworkTimeSynchronization::NetworkTimeSynchronization()

{//BEGIN_eb0f1b90102c8aa5e194df6319fafd88

}//END_eb0f1b90102c8aa5e194df6319fafd88



oldportal::fc::network::command::NetworkTimeSynchronization::~NetworkTimeSynchronization()
{//BEGIN_e5b984236a7706eb620d3a695b5e018f

}//END_e5b984236a7706eb620d3a695b5e018f


void oldportal::fc::network::command::NetworkTimeSynchronization::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_ba5a8c22a6c4cc0d2dfa663125379790
    assert(controller);

    if (modbus_set_slave(controller->getModbusContext(), MODBUS_BROADCAST_ADDRESS) != 0)
    {
        oldportal::fc::system::log::error(u8"oldportal::fc::network::command::NetworkTimeSynchronization::process() set BROADCAST device address error");
        oldportal::fc::system::log::error(modbus_strerror(errno));
        //TODO: increment errors count
        return;
    }

    // set network time for devices
    NETWORK_TIME network_time = controller->_network_time.getCurrentNetworkTime();

    uint16_t timer_buf[sizeof(network_time)/2];
    // network time register address
    uint16_t addr = 4000;

    // convert network_time to uint16_t Modbus registers
    MODBUS_SET_INT64_TO_INT16(timer_buf, 0, network_time);

    if (modbus_write_registers(controller->getModbusContext(), addr, 4, timer_buf) != 4)
    {
        oldportal::fc::system::log::error(u8"oldportal::fc::network::command::NetworkTimeSynchronization::process() modbus_write_registers() error");
        oldportal::fc::system::log::error(modbus_strerror(errno));
        //TODO: increment errors count
    }

    modbus_flush(controller->getModbusContext());

    // no response for MODBUS_BROADCAST_ADDRESS, return
}//END_ba5a8c22a6c4cc0d2dfa663125379790


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
