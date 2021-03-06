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


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::fc::hardware::mechatronics::command::GetMotionState::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::command::GetMotionState";


oldportal::fc::hardware::mechatronics::command::GetMotionState::GetMotionState(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_a84b36fc8e1ee05d4c84cfce11a1c814

}//END_a84b36fc8e1ee05d4c84cfce11a1c814



oldportal::fc::hardware::mechatronics::command::GetMotionState::~GetMotionState()
{//BEGIN_ac02cdcf28c219da19e50d05ba0e28ae

}//END_ac02cdcf28c219da19e50d05ba0e28ae


void oldportal::fc::hardware::mechatronics::command::GetMotionState::onProcessed()
{//BEGIN_2820fe92dee8fa9179a0f3326e6d0fc7
    // empty
}//END_2820fe92dee8fa9179a0f3326e6d0fc7

void oldportal::fc::hardware::mechatronics::command::GetMotionState::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_4e3507a92ef4831d96535832e77d1c87
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    // modbus read registers
    uint16_t registers[motor_device->_modbus_data._driverData.getModbusRegistersSizeof() + motor_device->_modbus_data._driverDataInput.getModbusRegistersSizeof()];

    // read _driverData
    if (modbus_read_registers(controller->getModbusContext(),
                              motor_device->_modbus_data._driverData._modbus_registers_start_index,
                              motor_device->_modbus_data._driverData.getModbusRegistersSizeof(),
                              registers) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::hardware::mechatronics::command::GetMotionState::process() modbus_read_registers error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    motor_device->_modbus_data._driverData.loadFromRegisterArray(registers);

    // read _driverDataInput
    if (modbus_read_registers(controller->getModbusContext(),
                              motor_device->_modbus_data._driverDataInput._modbus_registers_start_index,
                              motor_device->_modbus_data._driverDataInput.getModbusRegistersSizeof(),
                              registers) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::hardware::mechatronics::command::GetMotionState::process() modbus_read_registers error: " << modbus_strerror(errno));

        // increment error counters
        controller->_error_statistics.increment();
        _device->_error_statistics.increment();

        return;
    }

    motor_device->_modbus_data._driverDataInput.loadFromRegisterArray(registers);

    // update device state
    _device->updateLastPing();
    _device->updateLastResponse();

    _result_success = true;
    _command_completed = true;
}//END_4e3507a92ef4831d96535832e77d1c87


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE