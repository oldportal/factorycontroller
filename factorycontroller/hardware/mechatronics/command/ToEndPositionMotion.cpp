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


oldportal::fc::hardware::mechatronics::command::ToEndPositionMotion::ToEndPositionMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process, float acceleration, float end_position)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_a67ddc7c05dd441e90da575a7c945599
    _acceleration = acceleration;
    _end_position = end_position;
}//END_a67ddc7c05dd441e90da575a7c945599



oldportal::fc::hardware::mechatronics::command::ToEndPositionMotion::~ToEndPositionMotion()
{//BEGIN_1d4498ad6f3b46ed07c5bc7868abde7b

}//END_1d4498ad6f3b46ed07c5bc7868abde7b


void oldportal::fc::hardware::mechatronics::command::ToEndPositionMotion::onProcessed()
{//BEGIN_9a9167eae02c584f7282410cb7a522d3
    // empty
}//END_9a9167eae02c584f7282410cb7a522d3

void oldportal::fc::hardware::mechatronics::command::ToEndPositionMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_cc8328a08aa7f7854165e8a127bca2d3
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    // read current speed from the device
    //TODO:

    assert (_acceleration < INT16_MAX && _acceleration > INT16_MIN);
    /*
    assert (_end_speed < INT16_MAX && _end_speed > INT16_MIN);
    assert (abs(_end_speed) <= motor_device->_modbus_data._driverData._13_motor_maximum_allowed_angle_speed);

    // init structure state
    motor_device->_modbus_data._driverData._1_mode = DRIVER_SERVO_SPEED_AND_ACCELERATION_TO_END_SPEED;
    motor_device->_modbus_data._driverData._6_rotor_angle_acceleration_speed = (int16_t)_acceleration;

    int16_t end_speed = (int16_t)_end_speed;
    //TODO: start_speed
    //motor_device->_modbus_data._driverData._4_rotor_angle_start_speed = speed;
    motor_device->_modbus_data._driverData._7_rotor_angle_end_continuous_speed = end_speed;
    */

    // write to modbus
    uint16_t start_address = motor_device->_modbus_data._driverData._modbus_registers_start_index;
    uint16_t registers[motor_device->_modbus_data._driverData.getModbusRegistersSizeof()];
    motor_device->_modbus_data._driverData.saveToRegisterArray(registers);

    if (modbus_write_registers(controller->getModbusContext(),
                               motor_device->_modbus_data._driverData._modbus_registers_start_index,
                               STEPMRDRV_DATA_REGISTER_OFFSET_8_rotor_angle_stop_position, // size = register index after last changed value
                               registers) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::hardware::mechatronics::command::ToEndPositionMotion::process() modbus_write_registers error: " << modbus_strerror(errno));

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
}//END_cc8328a08aa7f7854165e8a127bca2d3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE