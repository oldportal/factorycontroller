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


oldportal::fc::network::command::DeviceIDReport::DeviceIDReport(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device)
    : oldportal::fc::network::DeviceCommand(device)
{//BEGIN_eb79c57be27cdbf036036cddfd9a12a7

}//END_eb79c57be27cdbf036036cddfd9a12a7



oldportal::fc::network::command::DeviceIDReport::~DeviceIDReport()
{//BEGIN_75eb4a1e182d3554b892c1f5df9630cf

}//END_75eb4a1e182d3554b892c1f5df9630cf


void oldportal::fc::network::command::DeviceIDReport::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_47f4dda8d40402b9319a9f212d5100cd
    assert(controller);

    if (!modbus_set_slave(controller))
        return;// hardware error

    /*
    //TODO: ping device
    auto modbusMessagePair = std::make_shared<oldportal::fc::network::modbus::ModbusMessagePair>();
    modbusMessagePair->setRequestAddress(_device->_modbus_address);
    modbusMessagePair->setRequestFunctionCode(FC_MODBUS_FUNC_REPORT_SLAVE_ID);
    //modbusMessagePair->setRequestLength();
    //modbusMessagePair->setCRC();

    // send modbusMessagePair
    //TODO: modbusMessagePair->getRequestLength() - is true length?
    if (modbus_send_raw_request(controller->getModbusContext(), modbusMessagePair->_send_buf, modbusMessagePair->getRequestLength()) != 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::DeviceStateReport::process() modbus_send_raw_request error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    // receive response
    int response_length;
    if ((response_length = modbus_receive_confirmation(controller->getModbusContext(), modbusMessagePair->_received_buf)) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::DeviceStateReport::process() modbus_receive_confirmation error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }
    */

    uint8_t tab_bytes[256];
    memset(tab_bytes, 256, 1);
    const int response_size = modbus_report_slave_id(controller->getModbusContext(), tab_bytes);
    assert(response_size < 256);
    if (response_size < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::DeviceStateReport::process() modbus_report_slave_id error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    // process response
    std::string device_id = (char*)(tab_bytes+3);
    LOG4CXX_INFO(logger, "device response: " << device_id);

    _device->updateLastPing();
    _device->updateLastResponse();

    _result_success = true;
    _command_completed = true;
}//END_47f4dda8d40402b9319a9f212d5100cd


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE