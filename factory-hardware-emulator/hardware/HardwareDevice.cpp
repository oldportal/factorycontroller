/*
*    This file is part of factory-hardware-emulator program and part of FactoryController project.
*    
*    factory-hardware-emulator is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    factory-hardware-emulator is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factory-hardware-emulator; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2014-2016
*    dmogn@mail.ru
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factory-hardware-emulator.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fhe::hardware::HardwareDevice::HardwareDevice()

{//BEGIN_1a4b1400bcfb2aebd9c4a2b219e725eb
    assert(_modbus_mapping == nullptr);

    _modbus_mapping = modbus_mapping_new(0, 0, MODBUS_MAX_READ_REGISTERS, MODBUS_MAX_RW_WRITE_REGISTERS);
}//END_1a4b1400bcfb2aebd9c4a2b219e725eb



oldportal::fhe::hardware::HardwareDevice::~HardwareDevice()
{//BEGIN_5004a49203b0a14ade8e214d41f338f3
    if (_modbus_mapping != nullptr)
    {
         modbus_mapping_free(_modbus_mapping);
        _modbus_mapping = nullptr;
    }
}//END_5004a49203b0a14ade8e214d41f338f3


void oldportal::fhe::hardware::HardwareDevice::controller_data_step(oldportal::fc::network::modbus::data::ControllerData& controller_data)
{//BEGIN_13b7a6e59bc0192e2dae4ae7762dd5e6
    // update maximum_system_step_timeout indication parameter
        uint32_t step_time_shift = oldportal::fhe::network::CalculateTimeInterval(oldportal::fhe::network::GetSystemTime(), controller_data._3_device_time);
        if (step_time_shift > UINT16_MAX)
            step_time_shift = UINT16_MAX;
        controller_data._5_maximum_system_step_timeout = step_time_shift;

        // update device_time indication parameter
        controller_data._3_device_time = oldportal::fhe::network::GetSystemTime();
}//END_13b7a6e59bc0192e2dae4ae7762dd5e6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE