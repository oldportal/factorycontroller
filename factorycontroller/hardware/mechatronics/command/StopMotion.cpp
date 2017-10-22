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


oldportal::fc::hardware::mechatronics::command::StopMotion::StopMotion(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)
    : oldportal::fc::network::DeviceCommand(device, device_process)
{//BEGIN_2245b2ed26b5b0155692968613af50ce

}//END_2245b2ed26b5b0155692968613af50ce



oldportal::fc::hardware::mechatronics::command::StopMotion::~StopMotion()
{//BEGIN_edd86cc0bfd363426f9f451e431a9666

}//END_edd86cc0bfd363426f9f451e431a9666


void oldportal::fc::hardware::mechatronics::command::StopMotion::onProcessed()
{//BEGIN_54ca0f1a3e69d91a3de9a722c200d309
    // empty
}//END_54ca0f1a3e69d91a3de9a722c200d309

void oldportal::fc::hardware::mechatronics::command::StopMotion::process(oldportal::fc::network::modbus::ModbusNetworkController* const  controller)
{//BEGIN_24b28aceb4ccdcd30267159a4f322962
    assert(controller);
    assert(_device);
    assert(_device_process);

    if (!modbus_set_slave(controller))
        return;// hardware error

    std::shared_ptr<oldportal::fc::hardware::mechatronics::Motor> motor_device = std::dynamic_pointer_cast<oldportal::fc::hardware::mechatronics::Motor>(_device);
    assert (motor_device);

    motor_device->_modbus_data._driverData._1_mode = DRIVER_SERVO_KEEP_POSITION;
    uint16_t start_address = motor_device->_modbus_data._driverData._modbus_registers_start_index + STEPMRDRV_DATA_REGISTER_OFFSET_1_mode;

    if (modbus_write_registers(controller->getModbusContext(), start_address, 1, &(motor_device->_modbus_data._driverData._1_mode)) < 0)
    {
        LOG4CXX_ERROR(logger, "oldportal::fc::network::command::StopMotion::process() modbus_write_registers error: " << modbus_strerror(errno));

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
}//END_24b28aceb4ccdcd30267159a4f322962


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE