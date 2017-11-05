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


const char* const  oldportal::fc::network::modbus::data::ControllerData::_CLASSNAME_FULL = "oldportal::fc::network::modbus::data::ControllerData";


oldportal::fc::network::modbus::data::ControllerData::ControllerData()

{//BEGIN_c1feca5ec6a2ffca882ec7a0c1bf9854
    // set structure sizeof
    _modbus_registers_sizeof = 9;

    // default values
    _1_mode = CTRLR_MODE_IDLE;
    _2_error_code = CTRLR_NO_ERRORS;
    _7_maximum_radiator_temperature = DEFAULT_MAXIMUM_RADIATOR_TEMPERATURE;
    _6_radiator_temperature = DEFAULT_RADIATOR_TEMPERATURE;
    _3_device_time = oldportal::fhe::network::GetSystemTime();
    _4_network_time_shift = 0;
    _5_maximum_system_step_timeout = 0;
}//END_c1feca5ec6a2ffca882ec7a0c1bf9854


void oldportal::fc::network::modbus::data::ControllerData::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_27ffc6aa766f69683dac4b08ec8d76ae
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    loadFromRegisterArray(registers);
}//END_27ffc6aa766f69683dac4b08ec8d76ae

void oldportal::fc::network::modbus::data::ControllerData::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_87e28eb3bb5eb405841b356230c2c888
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    _1_mode = registers[0];
    _2_error_code = registers[1];

    uint32_t *device_time_register = (uint32_t *)(registers+2);
    _3_device_time = *device_time_register;

    uint32_t *network_time_shift_register = (uint32_t *)(registers+4);
    _4_network_time_shift = *network_time_shift_register;

    _5_maximum_system_step_timeout = registers[6];
    _6_radiator_temperature = registers_i16[7];
    _7_maximum_radiator_temperature = registers_i16[8];
}//END_87e28eb3bb5eb405841b356230c2c888

void oldportal::fc::network::modbus::data::ControllerData::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_efd2a04e01927b64d4db2d3236dc75aa
    // check index range with modbus_mapping->nb_registers:
    assert(_modbus_registers_start_index < modbus_mapping->nb_registers);
    assert(_modbus_registers_start_index + getModbusRegistersSizeof() <= modbus_mapping->nb_registers);

    uint16_t *registers = modbus_mapping->tab_registers;
    registers += _modbus_registers_start_index;

    saveToRegisterArray(registers);
}//END_efd2a04e01927b64d4db2d3236dc75aa

void oldportal::fc::network::modbus::data::ControllerData::saveToRegisterArray(uint16_t* registers)
{//BEGIN_bb9c42d55d8ae770a32ec21fe55cd6a2
    assert(registers);

    int16_t *registers_i16 = (int16_t *)registers;

    // variables
    registers[0] = _1_mode;
    registers[1] = _2_error_code;

    uint32_t *device_time_register = (uint32_t *)(registers+2);
    *device_time_register = _3_device_time;

    uint32_t *network_time_shift_register = (uint32_t *)(registers+4);
    *network_time_shift_register = _4_network_time_shift;

    registers[6] = _5_maximum_system_step_timeout;
    registers_i16[7] = _6_radiator_temperature;
    registers_i16[8] = _7_maximum_radiator_temperature;
}//END_bb9c42d55d8ae770a32ec21fe55cd6a2


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE