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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::command::DeviceStateReport::DeviceStateReport(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device)
    : oldportal::fc::network::DeviceCommand(device)
{//BEGIN_7beba502117e9095cf401c036398cc43

}//END_7beba502117e9095cf401c036398cc43



oldportal::fc::network::command::DeviceStateReport::~DeviceStateReport()
{//BEGIN_d1555c3373090cf5a5b01ddf233ffacc

}//END_d1555c3373090cf5a5b01ddf233ffacc


void oldportal::fc::network::command::DeviceStateReport::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_b9522da80d4b05e42e2b9d9a702ae52d
    assert(controller);

    if (modbus_set_slave(controller->getModbusContext(), _device->_modbus_address) != 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::DeviceStateReport::process() set device address error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    // read controller_data (0-8 registers)
    uint16_t tab_reg[64];
    // modbus read registers
    if (modbus_read_registers(controller->getModbusContext(), 0, 8, tab_reg) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::DeviceStateReport::process() modbus_read_registers error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    //TODO: read device state structure registers
    //TODO: parse device state structure registers

    // update device state
    _device->updateLastPing();
    _device->updateLastResponse();

    _result_success = true;
    _command_completed = true;
}//END_b9522da80d4b05e42e2b9d9a702ae52d


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE