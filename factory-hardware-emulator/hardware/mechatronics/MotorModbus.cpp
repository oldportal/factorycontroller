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


#include "../../factory-hardware-emulator.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fhe::hardware::mechatronics::MotorModbus::MotorModbus()

{//BEGIN_6ca1ad45040297580b922c50c0922d36
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
}//END_6ca1ad45040297580b922c50c0922d36


void oldportal::fhe::hardware::mechatronics::MotorModbus::CheckDriverModbusParameters()
{//BEGIN_a5188233ca8363a6d5a582c1c4b0cd99
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
}//END_a5188233ca8363a6d5a582c1c4b0cd99

void oldportal::fhe::hardware::mechatronics::MotorModbus::ctrlReportError(uint16_t error_code)
{//BEGIN_b38277a56ee6ba25ce23545f9b221d90
    ctrlReportErrorWithParameter(error_code, ZERO_ERROR_LOG_PARAMETER);
}//END_b38277a56ee6ba25ce23545f9b221d90

void oldportal::fhe::hardware::mechatronics::MotorModbus::ctrlReportErrorWithParameter(uint16_t error_code, uint16_t parameter)
{//BEGIN_6b48935c77aadb47c2a2341a2f8c01f7
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
}//END_6b48935c77aadb47c2a2341a2f8c01f7

void oldportal::fhe::hardware::mechatronics::MotorModbus::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_78fc3366898319efcb31f2aa857f113b
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
}//END_78fc3366898319efcb31f2aa857f113b

void oldportal::fhe::hardware::mechatronics::MotorModbus::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_b71c476c1b34c76ccb5e14bfbb49777a
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
}//END_b71c476c1b34c76ccb5e14bfbb49777a


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE