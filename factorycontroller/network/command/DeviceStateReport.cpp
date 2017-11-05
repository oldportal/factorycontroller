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


const char* const  oldportal::fc::network::command::DeviceStateReport::_CLASSNAME_FULL = "oldportal::fc::network::command::DeviceStateReport";


oldportal::fc::network::command::DeviceStateReport::DeviceStateReport(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device)
    : oldportal::fc::network::DeviceCommand(device)
{//BEGIN_3b726bc629d0e6d64f72af0cc0a3d8f0

}//END_3b726bc629d0e6d64f72af0cc0a3d8f0



oldportal::fc::network::command::DeviceStateReport::~DeviceStateReport()
{//BEGIN_7535365cc308587e939128fcf5916110

}//END_7535365cc308587e939128fcf5916110


void oldportal::fc::network::command::DeviceStateReport::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_13a74cb896493fe0f59c379b7ca4d5d2
    assert(controller);

    if (!modbus_set_slave(controller))
        return;// hardware error

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
}//END_13a74cb896493fe0f59c379b7ca4d5d2


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE