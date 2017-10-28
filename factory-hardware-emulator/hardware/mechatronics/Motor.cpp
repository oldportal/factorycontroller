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
#include <stdint.h>
//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fhe::hardware::mechatronics::Motor::Motor()

{//BEGIN_af6f30859e21bb21da954b58d4c5a933
    _current_position = _settings._default_start_position;
}//END_af6f30859e21bb21da954b58d4c5a933



oldportal::fhe::hardware::mechatronics::Motor::~Motor()
{//BEGIN_51c1a47c1ac6e7d841a5516bb0b5ab4a

}//END_51c1a47c1ac6e7d841a5516bb0b5ab4a


void oldportal::fhe::hardware::mechatronics::Motor::process_request(const uint8_t* request, const uint16_t request_length, const uint8_t slave_address, const uint8_t modbus_function, modbus_t* modbus_ctx)
{//BEGIN_5b55e939e368cf5f2f98e49c2e3d2cf6
    assert (slave_address == MODBUS_BROADCAST_ADDRESS || slave_address == _modbus_address);

    // update registers in modbus mapping
    _modbus.saveToRegisterArray(_modbus_mapping);

    // call example:
    // uint16_t value = MODBUS_GET_INT16_FROM_INT8(query, header_length + 1);
    // modbus_reply_exception(ctx, query, MODBUS_EXCEPTION_SLAVE_OR_SERVER_BUSY);

    if (slave_address != MODBUS_BROADCAST_ADDRESS)
    {// default reply handler
        int result = modbus_reply(modbus_ctx, request, request_length, _modbus_mapping);
        if (result == -1) 
        {
            fprintf(stderr, "StepMotor::process_request() modbus_reply() error: %s\n", modbus_strerror(errno));
            LOG4CXX_ERROR(logger, std::string("StepMotor::process_request() modbus_reply() error: ") + modbus_strerror(errno));
        }
    }

    // update structures from registers in modbus mapping
    _modbus.loadFromRegisterArray(_modbus_mapping);
}//END_5b55e939e368cf5f2f98e49c2e3d2cf6

void oldportal::fhe::hardware::mechatronics::Motor::servoCalculatePositionAndSpeed()
{//BEGIN_4cd55fb0b6c71bd805ddd6bfe7d0e6fd
    int16_t rotor_angle_speed_error = 0;

    if (_modbus._driverData._1_mode == DRIVER_SERVO_IDLE)
        ;
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_KEEP_POSITION)
    {
        ;
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_CONTINUOUS_SPEED)
    {
        rotor_angle_speed_error = _modbus._driverData._7_rotor_angle_end_continuous_speed - _modbus._driverDataInput._1_rotor_angle_speed;

        //_modbus._driverDataInput._7_rotor_angle_end_continuous_speed = _modbus._driverData.rotor_angle_end_speed;
        //TODO: position
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION)
    {
        uint32_t time_difference = oldportal::fhe::network::CalculateTimeInterval(oldportal::fhe::network::GetSystemTime(), _modbus._driverData._4_rotor_angle_start_speed);

        int32_t current_planed_speed = _modbus._driverData._4_rotor_angle_start_speed + (_modbus._driverData._6_rotor_angle_acceleration_speed * time_difference) / F_SYSTEM_TIMER_TICKS;

        if (abs(current_planed_speed) > _modbus._driverData._13_motor_maximum_allowed_angle_speed)
            if (current_planed_speed >= 0)
                current_planed_speed = _modbus._driverData._13_motor_maximum_allowed_angle_speed;
            else
                current_planed_speed = -_modbus._driverData._13_motor_maximum_allowed_angle_speed;

        rotor_angle_speed_error = current_planed_speed - _modbus._driverDataInput._1_rotor_angle_speed;

        //_modbus._driverDataInput._4_rotor_planned_angle_speed = (uint16_t)current_planed_speed;

        //TODO: position and speed
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION_TO_END_SPEED)
    {
        uint32_t time_difference = oldportal::fhe::network::CalculateTimeInterval(oldportal::fhe::network::GetSystemTime(), _modbus._driverData._5_rotor_angle_start_speed_time);

        int32_t current_planed_speed = _modbus._driverData._4_rotor_angle_start_speed + (_modbus._driverData._6_rotor_angle_acceleration_speed * time_difference) / F_SYSTEM_TIMER_TICKS;

        // check for system error where acceleration direction opposite to end speed:
        if ((_modbus._driverData._7_rotor_angle_end_continuous_speed > 0 && _modbus._driverData._6_rotor_angle_acceleration_speed < 0) ||
            (_modbus._driverData._7_rotor_angle_end_continuous_speed < 0 && _modbus._driverData._6_rotor_angle_acceleration_speed > 0))
        {
            // report system error
            _modbus._driverData._2_hardware_error_code = DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED;
            _modbus.ctrlReportError(DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED);
        }

        // check for end speed
        if (current_planed_speed > 0 && _modbus._driverData._7_rotor_angle_end_continuous_speed >= 0)
            if  (current_planed_speed > _modbus._driverData._7_rotor_angle_end_continuous_speed)
            {
                current_planed_speed = _modbus._driverData._7_rotor_angle_end_continuous_speed;
                // switch mode to DRIVER_SERVO_CONTINUOUS_SPEED
                _modbus._driverData._1_mode = DRIVER_SERVO_CONTINUOUS_SPEED;
            }

        if (current_planed_speed < 0 && _modbus._driverData._7_rotor_angle_end_continuous_speed <= 0)
            if  (current_planed_speed < _modbus._driverData._7_rotor_angle_end_continuous_speed)
            {
                current_planed_speed = _modbus._driverData._7_rotor_angle_end_continuous_speed;
                // switch mode to DRIVER_SERVO_CONTINUOUS_SPEED
                _modbus._driverData._1_mode = DRIVER_SERVO_CONTINUOUS_SPEED;
            }

        // check for maximum mechanic speed limit
        if (abs(current_planed_speed) > _modbus._driverData._13_motor_maximum_allowed_angle_speed)
        {
            if (current_planed_speed >= 0)
                current_planed_speed = _modbus._driverData._13_motor_maximum_allowed_angle_speed;
            else
                current_planed_speed = -_modbus._driverData._13_motor_maximum_allowed_angle_speed;

            _modbus.ctrlReportError(DRIVER_SOFRWARE_COMMAND_ANGLE_OVERSPEED);
        }

        rotor_angle_speed_error = current_planed_speed - _modbus._driverDataInput._1_rotor_angle_speed;

        //_modbus._driverDataInput._4_rotor_planned_angle_speed = (uint16_t)current_planed_speed;

        //TODO: position and speed
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_TO_END_POSITION)
    {
        //TODO:
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_CONTINUOUS_FORCE)
    {
        //TODO: report system error, not applicable mode for step motor
    }
    else if (_modbus._driverData._1_mode == DRIVER_STEP_DIRECT)
    {
        ;// direct drive, no calculations
    }
}//END_4cd55fb0b6c71bd805ddd6bfe7d0e6fd

void oldportal::fhe::hardware::mechatronics::Motor::servoCalculateSpeedAndTorque()
{//BEGIN_f6e2a1705bd97f1a91b7869c4df93ce2
    int16_t rotor_angle_speed_error = 0;

    if (_modbus._driverData._1_mode == DRIVER_SERVO_IDLE)
    {
        _modbus._driverDataInput._4_rotor_planned_angle_speed = 0;
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_KEEP_POSITION)
    {
        //TODO: calculate keep position error and feedback torque
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_CONTINUOUS_SPEED)
    {
        rotor_angle_speed_error = _modbus._driverData._7_rotor_angle_end_continuous_speed - _modbus._driverDataInput._1_rotor_angle_speed;

        _modbus._driverDataInput._4_rotor_planned_angle_speed = _modbus._driverData._7_rotor_angle_end_continuous_speed;

        //TODO: torque
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION)
    {
        uint32_t time_difference = oldportal::fhe::network::CalculateTimeInterval(oldportal::fhe::network::GetSystemTime(), _modbus._driverData._5_rotor_angle_start_speed_time);

        int32_t current_planed_speed = _modbus._driverData._4_rotor_angle_start_speed + (_modbus._driverData._6_rotor_angle_acceleration_speed * time_difference) / F_SYSTEM_TIMER_TICKS;

        if (abs(current_planed_speed) > _modbus._driverData._13_motor_maximum_allowed_angle_speed)
            if (current_planed_speed >= 0)
                current_planed_speed = _modbus._driverData._13_motor_maximum_allowed_angle_speed;
            else
                current_planed_speed = -_modbus._driverData._13_motor_maximum_allowed_angle_speed;

        rotor_angle_speed_error = current_planed_speed - _modbus._driverDataInput._1_rotor_angle_speed;

        _modbus._driverDataInput._4_rotor_planned_angle_speed = (uint16_t)current_planed_speed;

        //TODO: torque
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION_TO_END_SPEED)
    {
        uint32_t time_difference = oldportal::fhe::network::CalculateTimeInterval(oldportal::fhe::network::GetSystemTime(), _modbus._driverData._5_rotor_angle_start_speed_time);

        int32_t current_planed_speed = _modbus._driverData._4_rotor_angle_start_speed + (_modbus._driverData._6_rotor_angle_acceleration_speed * time_difference) / F_SYSTEM_TIMER_TICKS;

        // check for system error where acceleration direction opposite to end speed:
        if ((_modbus._driverData._7_rotor_angle_end_continuous_speed > 0 && _modbus._driverData._6_rotor_angle_acceleration_speed < 0) ||
            (_modbus._driverData._7_rotor_angle_end_continuous_speed < 0 && _modbus._driverData._6_rotor_angle_acceleration_speed > 0))
        {
            // report system error
            _modbus._driverData._2_hardware_error_code = DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED;
            _modbus.ctrlReportError(DRIVER_SOFRWARE_COMMAND_ANGLE_ACCELERATION_OPPOSITE_TO_ENDSPEED);
        }

        // check for end speed
        if (current_planed_speed > 0 && _modbus._driverData._7_rotor_angle_end_continuous_speed >= 0)
            if  (current_planed_speed > _modbus._driverData._7_rotor_angle_end_continuous_speed)
                current_planed_speed = _modbus._driverData._7_rotor_angle_end_continuous_speed;

        if (current_planed_speed < 0 && _modbus._driverData._7_rotor_angle_end_continuous_speed <= 0)
            if  (current_planed_speed < _modbus._driverData._7_rotor_angle_end_continuous_speed)
                current_planed_speed = _modbus._driverData._7_rotor_angle_end_continuous_speed;

        // check for maximum mechanic speed limit
        if (abs(current_planed_speed) > _modbus._driverData._13_motor_maximum_allowed_angle_speed)
        {
            if (current_planed_speed >= 0)
                current_planed_speed = _modbus._driverData._13_motor_maximum_allowed_angle_speed;
            else
                current_planed_speed = -_modbus._driverData._13_motor_maximum_allowed_angle_speed;

            _modbus.ctrlReportError(DRIVER_SOFRWARE_COMMAND_ANGLE_OVERSPEED);
        }

        rotor_angle_speed_error = current_planed_speed - _modbus._driverDataInput._1_rotor_angle_speed;

        _modbus._driverDataInput._4_rotor_planned_angle_speed = (uint16_t)current_planed_speed;

        //TODO: torque
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_TO_END_POSITION)
    {
        //TODO: position-driven mode
    }
    else if (_modbus._driverData._1_mode == DRIVER_SERVO_CONTINUOUS_FORCE)
    {
        _modbus._driverDataInput._4_rotor_planned_angle_speed = _modbus._driverDataInput._1_rotor_angle_speed;
        _modbus._driverDataInput._5_rotor_planned_angle_torque = _modbus._driverData._9_rotor_angle_force;
    }
    else if (_modbus._driverData._1_mode == DRIVER_STEP_DIRECT)
    {
        //TODO:
    }
}//END_f6e2a1705bd97f1a91b7869c4df93ce2

void oldportal::fhe::hardware::mechatronics::Motor::step()
{//BEGIN_139a1c7a4966eeccad82b1856e6ad1e1
    // update controller data
    controller_data_step(_modbus._controllerData);

    //if (_modbus._controllerData._1_mode == 0)

    //TODO: update _controllerData


    _modbus.checkDriverModbusParameters();

    // update motor state
    if (_modbus._driverData._1_mode != DRIVER_SERVO_IDLE)
    {
        // no activity in IDLE mode
    }
    else if (_modbus._controllerData._1_mode == CTRLR_MODE_DIRECT_CONTROL || _modbus._controllerData._1_mode == CTRLR_MODE_NC_COMMANDS_FLOW)
    {
        if (_modbus._controllerData._1_mode == CTRLR_MODE_NC_COMMANDS_FLOW)
        {
            //TODO: check time and update current command status
        }

        // resolve current state

        if (_modbus._driverData._1_mode == DRIVER_SERVO_KEEP_POSITION)
        {
            // same motor position, no inertia (simplification)
        }
        else if (_modbus._driverData._1_mode == DRIVER_SERVO_CONTINUOUS_SPEED)
        {
            float angle_speed = _modbus._driverData._4_rotor_angle_start_speed;
            //TODO: update motor position

        }
        else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION)
        {
            float angle_speed = _modbus._driverData._4_rotor_angle_start_speed;
            //TODO: update motor position
        }
        else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_AND_ACCELERATION_TO_END_SPEED)
        {
            float angle_speed = _modbus._driverData._4_rotor_angle_start_speed;
            //TODO: update motor position
        }
        else if (_modbus._driverData._1_mode == DRIVER_SERVO_SPEED_TO_END_POSITION)
        {
            //TODO: update motor position
        }
        else if (_modbus._driverData._1_mode == DRIVER_SERVO_CONTINUOUS_FORCE)
        {
            //TODO: update motor position
        }
        else if (_modbus._driverData._1_mode == DRIVER_STEP_DIRECT)
        {
            if (abs(_modbus._driverData._10_rotor_angle_direct_step) == 1)
            {
                // update motor position
                // position +- step
                _modbus._driverDataInput._3_rotor_absolute_angle_position += _modbus._driverData._10_rotor_angle_direct_step;

                //stepMotorSetNextStep((int8_t) _modbus._driverData._10_rotor_angle_direct_step);

                _modbus._driverData._10_rotor_angle_direct_step = 0;                
            }

            if (_modbus._driverData._10_rotor_angle_direct_step != 0)
            {
                //TODO: report illegal parameters: direct step must be +-1 or 0.
            }
        }
    }

    _modbus.checkDriverModbusParameters();
}//END_139a1c7a4966eeccad82b1856e6ad1e1

void oldportal::fhe::hardware::mechatronics::Motor::stepMotorSetNextStep(int8_t direction)
{//BEGIN_38c4d5678390d929b9d3d69b4d812cba
    // calculate shift
    int8_t microstep_scaler = 4;// full step
    if (_modbus._driverData._14_motor_step_scale == 2)
        microstep_scaler = 2;
    else if (_modbus._driverData._14_motor_step_scale == 4)
        microstep_scaler = 1;

        // update step mode data
//        step_motor_data.pwmMicroStepMode += microstep_scaler * direction;
//        if (step_motor_data.pwmMicroStepMode < 0)
//            step_motor_data.pwmMicroStepMode += 64;
//        if (step_motor_data.pwmMicroStepMode > 15)
//            step_motor_data.pwmMicroStepMode = step_motor_data.pwmMicroStepMode % 16;

    _currentStepStartTime = std::chrono::high_resolution_clock::now();

    // set PWM rates for new step position
    //StepMotorKeepPositionUpdatePWMRates();
}//END_38c4d5678390d929b9d3d69b4d812cba

void oldportal::fhe::hardware::mechatronics::Motor::stopAllDeviceActivity()
{//BEGIN_827fa5cd792ee4d2e5996a97826b7edf
    LOG4CXX_INFO(logger, std::string("Motor::stopAllDeviceActivity(), _modbus_address: ") + std::to_string(_modbus_address));
    //TODO: stopAllDeviceActivity()
}//END_827fa5cd792ee4d2e5996a97826b7edf


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE