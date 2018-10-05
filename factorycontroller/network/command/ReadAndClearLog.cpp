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


const char* const  oldportal::fc::network::command::ReadAndClearLog::_CLASSNAME_FULL = "oldportal::fc::network::command::ReadAndClearLog";


oldportal::fc::network::command::ReadAndClearLog::ReadAndClearLog(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, oldportal::fc::network::modbus::data::SystemLogReport* log_records, uint16_t log_record_count/* = CONTROLLER_LOG_SIZE */)
    : oldportal::fc::network::DeviceCommand(device)
{//BEGIN_7beba502117e9095cf401c036398cc43

}//END_7beba502117e9095cf401c036398cc43



oldportal::fc::network::command::ReadAndClearLog::~ReadAndClearLog()
{//BEGIN_d1555c3373090cf5a5b01ddf233ffacc

}//END_d1555c3373090cf5a5b01ddf233ffacc


void oldportal::fc::network::command::ReadAndClearLog::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_b9522da80d4b05e42e2b9d9a702ae52d
    assert(controller);
    assert(_device);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    // read controller LOG data

    // init registers array
    uint16_t start_address = motor_device->_modbus_data._systemLog[0]._modbus_registers_start_index;
    uint16_t registers_count = CONTROLLER_LOG_SIZE * motor_device->_modbus_data._systemLog[0].getModbusRegistersSizeof();
    size_t reg_size = CONTROLLER_LOG_SIZE * motor_device->_modbus_data._systemLog[0].getModbusRegistersSizeof();
    uint16_t tab_reg[reg_size];

    // modbus read log registers
    if (modbus_read_registers(controller->getModbusContext(), start_address, registers_count, tab_reg) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::ReadAndClearLog::process() modbus_read_registers error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    // parse device state structure registers
    for (uint16_t i=0; i<CONTROLLER_LOG_SIZE; i++)
    {
        motor_device->_modbus_data._systemLog[i].loadFromRegisterArray(tab_reg + i*motor_device->_modbus_data._systemLog[i].getModbusRegistersSizeof());
    }

    // modbus clear log registers
    memset(tab_reg, 0, reg_size*sizeof(uint16_t));

    if (modbus_write_registers(controller->getModbusContext(), start_address, registers_count, tab_reg) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::ReadAndClearLog::process() modbus_write_registers error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    // update device state
    _device->updateLastPing();
    _device->updateLastResponse();

    _result_success = true;
    _command_completed = true;
}//END_b9522da80d4b05e42e2b9d9a702ae52d


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE