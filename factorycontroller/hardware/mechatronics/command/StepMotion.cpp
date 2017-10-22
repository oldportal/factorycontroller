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


oldportal::fc::hardware::mechatronics::command::StepMotion::StepMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process, int16_t direct_step)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_ac3725385c54bbe125b8c2a5b1b020fb
    assert(direct_step == 0 || direct_step == 1 || direct_step == -1);

    _direct_step = direct_step;
}//END_ac3725385c54bbe125b8c2a5b1b020fb



oldportal::fc::hardware::mechatronics::command::StepMotion::~StepMotion()
{//BEGIN_14479bc6cabf11039aad4199e79fc4f3

}//END_14479bc6cabf11039aad4199e79fc4f3


void oldportal::fc::hardware::mechatronics::command::StepMotion::onProcessed()
{//BEGIN_672e70a7205f5de2d78edda67ad10174
    // empty
}//END_672e70a7205f5de2d78edda67ad10174

void oldportal::fc::hardware::mechatronics::command::StepMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_ce66d4c0b634215137cdb5fe36caf9ce
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    // init structure state
    motor_device->_modbus_data._driverData._1_mode = DRIVER_STEP_DIRECT;
    motor_device->_modbus_data._driverData._6_rotor_angle_acceleration_speed = 0;
    motor_device->_modbus_data._driverData._4_rotor_angle_start_speed = 0;
    motor_device->_modbus_data._driverData._7_rotor_angle_end_continuous_speed = 0;
    motor_device->_modbus_data._driverData._10_rotor_angle_direct_step = _direct_step;

    // write to modbus
    uint16_t start_address = motor_device->_modbus_data._driverData._modbus_registers_start_index;
    uint16_t registers[motor_device->_modbus_data._driverData.getModbusRegistersSizeof()];
    motor_device->_modbus_data._driverData.saveToRegisterArray(registers);

    if (modbus_write_registers(controller->getModbusContext(),
                               motor_device->_modbus_data._driverData._modbus_registers_start_index,
                               STEPMRDRV_DATA_REGISTER_OFFSET_11_motor_maximum_allowed_temperature, // size = register index after last changed value
                               registers) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::hardware::mechatronics::command::StepMotion::process() modbus_write_registers error: " << modbus_strerror(errno));

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
}//END_ce66d4c0b634215137cdb5fe36caf9ce


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
