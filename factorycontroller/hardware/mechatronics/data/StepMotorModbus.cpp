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


const char* const  oldportal::fc::hardware::mechatronics::data::StepMotorModbus::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::data::StepMotorModbus";


oldportal::fc::hardware::mechatronics::data::StepMotorModbus::StepMotorModbus()

{//BEGIN_40d4aec2b867efdf8c752d072f2067aa
    // set structure sizeof
    _modbus_registers_sizeof = _controllerData.getModbusRegistersSizeof() +
            _driverCalculationConstants.getModbusRegistersSizeof() +
            _driverData.getModbusRegistersSizeof() +
            _driverDataInput.getModbusRegistersSizeof() +
            _systemLog[0].getModbusRegistersSizeof()*CONTROLLER_LOG_SIZE;

    // set members structures sizeof
    _controllerData._modbus_registers_start_index = 0;
    _driverCalculationConstants._modbus_registers_start_index = _controllerData.getModbusRegistersSizeof();
    _driverData._modbus_registers_start_index = _controllerData.getModbusRegistersSizeof() +
            _driverCalculationConstants.getModbusRegistersSizeof();
    _driverDataInput._modbus_registers_start_index = _controllerData.getModbusRegistersSizeof() +
            _driverCalculationConstants.getModbusRegistersSizeof() +
            _driverData.getModbusRegistersSizeof();

    for (int index = 0; index < CONTROLLER_LOG_SIZE; index++)
    {
        _systemLog[index]._modbus_registers_start_index = _controllerData.getModbusRegistersSizeof() +
                _driverCalculationConstants.getModbusRegistersSizeof() +
                _driverData.getModbusRegistersSizeof() +
                _driverDataInput.getModbusRegistersSizeof() +
                _systemLog[0].getModbusRegistersSizeof()*index;
    }

    // first structure reserved for "other error" reports
    _systemLog[0]._1_error_code = CTRLR_OTHER_ERROR;
}//END_40d4aec2b867efdf8c752d072f2067aa


void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::checkDriverModbusParameters()
{//BEGIN_bbd0a4f4144a9c56f556917fdf2e59f1
    if (_driverData._1_mode == DRIVER_SERVO_CONTINUOUS_SPEED)
    {
        if (abs(_driverData._7_rotor_angle_end_continuous_speed) > _driverData._13_motor_maximum_allowed_angle_speed)
        {
            // report system error
            _driverData._2_hardware_error_code = DRIVER_SOFRWARE_COMMAND_ANGLE_OVERSPEED;
            ctrlReportError(DRIVER_SOFRWARE_COMMAND_ANGLE_OVERSPEED);
        }
    }
    else if (_driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION_TO_END_SPEED)
    {
        // check for system error where acceleration direction opposite to end speed:
        if ((_driverData._7_rotor_angle_end_continuous_speed > 0 && _driverData._6_rotor_angle_acceleration_speed < 0) ||
            (_driverData._7_rotor_angle_end_continuous_speed < 0 && _driverData._6_rotor_angle_acceleration_speed > 0))
        {
            // report system error
            _driverData._2_hardware_error_code = DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED;
            ctrlReportError(DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED);
        }
    }
}//END_bbd0a4f4144a9c56f556917fdf2e59f1

void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::ctrlReportError(uint16_t error_code)
{//BEGIN_9ef25e7d521f764cc681fec5c0627dd2
    ctrlReportErrorWithParameter(error_code, ZERO_ERROR_LOG_PARAMETER);
}//END_9ef25e7d521f764cc681fec5c0627dd2

void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::ctrlReportErrorWithParameter(uint16_t error_code, uint16_t parameter)
{//BEGIN_fde39ee1e0c273c3e18b0948ae2826fc
    if (error_code == CTRLR_NO_ERRORS)
            return;// nothing

       _controllerData._2_error_code = error_code;

        // clear log report structures
        for (uint8_t index=0; index<CONTROLLER_LOG_SIZE; index++)
        {
            if (_systemLog[index]._1_error_code == CTRLR_NO_ERRORS)
            {
                // empty report structure - initialize for this error type
                _systemLog[index]._1_error_code = error_code;
            }

            if (_systemLog[index]._1_error_code == error_code)
            {
                // same error structure - report error
                if (_systemLog[index]._2_count < UINT16_MAX)
                    _systemLog[index]._2_count++;

                _systemLog[index]._4_last_parameter = parameter;
                _systemLog[index]._3_last_time = oldportal::fhe::network::GetSystemTime();
                return;
            }
        }

        // no structures for this type reports and no empty structures -> report to zero structure reserved for "other error" reports
        if (_systemLog[0]._2_count < UINT16_MAX)
            _systemLog[0]._2_count++;

        _systemLog[0]._4_last_parameter = parameter;
        _systemLog[0]._3_last_time = oldportal::fhe::network::GetSystemTime();
}//END_fde39ee1e0c273c3e18b0948ae2826fc

void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_bcacd04f7bb2ffba40b3f730f454783a
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    _controllerData.loadFromRegisterArray(modbus_mapping);
    _driverCalculationConstants.loadFromRegisterArray(modbus_mapping);
    _driverData.loadFromRegisterArray(modbus_mapping);
    _driverDataInput.loadFromRegisterArray(modbus_mapping);
    for (int index = 0; index < CONTROLLER_LOG_SIZE; index++)
    {
        _systemLog[index].loadFromRegisterArray(modbus_mapping);
    }
}//END_bcacd04f7bb2ffba40b3f730f454783a

void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_c530bda55373de96b6014767cb294482
    assert(registers);

    LOG4CXX_ERROR(logger, "function StepMotorModbus::loadFromRegisterArray(const uint16_t* registers) is not supported");
}//END_c530bda55373de96b6014767cb294482

void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_1b090a13c101b30e043d6f2354064dcf
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    _controllerData.saveToRegisterArray(modbus_mapping);
    _driverCalculationConstants.saveToRegisterArray(modbus_mapping);
    _driverData.saveToRegisterArray(modbus_mapping);
    _driverDataInput.saveToRegisterArray(modbus_mapping);
    for (int index = 0; index < CONTROLLER_LOG_SIZE; index++)
    {
        _systemLog[index].saveToRegisterArray(modbus_mapping);
    }
}//END_1b090a13c101b30e043d6f2354064dcf

void oldportal::fc::hardware::mechatronics::data::StepMotorModbus::saveToRegisterArray(uint16_t* registers)
{//BEGIN_4423a6e2185ad532ee83b10cc8527ab7
    assert(registers);

    LOG4CXX_ERROR(logger, "function StepMotorModbus::saveToRegisterArray(uint16_t* registers) is not supported");
}//END_4423a6e2185ad532ee83b10cc8527ab7


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE