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


oldportal::fc::hardware::mechatronics::command::LinearMotion::LinearMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process, float speed)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_f1e42a2902ff79a631b19822cf0c87bb
    _speed = speed;
}//END_f1e42a2902ff79a631b19822cf0c87bb



oldportal::fc::hardware::mechatronics::command::LinearMotion::~LinearMotion()
{//BEGIN_3ae7cbc70058cbc03bebf6e27865f011

}//END_3ae7cbc70058cbc03bebf6e27865f011


void oldportal::fc::hardware::mechatronics::command::LinearMotion::onProcessed()
{//BEGIN_25255f50ef0019f639443262727c6347
    // empty
}//END_25255f50ef0019f639443262727c6347

void oldportal::fc::hardware::mechatronics::command::LinearMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_5a4ca282f77a69d1fdd39facedaec3a6
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    // init structure state
    motor_device->_modbus_data._driverData._1_mode = DRIVER_SERVO_CONTINUOUS_SPEED;
    motor_device->_modbus_data._driverData._6_rotor_angle_acceleration_speed = 0;

    assert (_speed < INT16_MAX && _speed > INT16_MIN);
    assert (abs(_speed) <= motor_device->_modbus_data._driverData._13_motor_maximum_allowed_angle_speed);

    int16_t speed = (int16_t)_speed;
    motor_device->_modbus_data._driverData._4_rotor_angle_start_speed = speed;
    motor_device->_modbus_data._driverData._7_rotor_angle_end_continuous_speed = speed;

    // write to modbus
    uint16_t start_address = motor_device->_modbus_data._driverData._modbus_registers_start_index;
    uint16_t registers[motor_device->_modbus_data._driverData.getModbusRegistersSizeof()];
    motor_device->_modbus_data._driverData.saveToRegisterArray(registers);

    if (modbus_write_registers(controller->getModbusContext(),
                               motor_device->_modbus_data._driverData._modbus_registers_start_index,
                               STEPMRDRV_DATA_REGISTER_OFFSET_8_rotor_angle_stop_position, // size = register index after last changed value
                               registers) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::LinearMotion::process() modbus_write_registers error: " << modbus_strerror(errno));

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
}//END_5a4ca282f77a69d1fdd39facedaec3a6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
