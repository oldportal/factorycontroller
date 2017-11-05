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


const char* const  oldportal::fc::hardware::power::data::PowerLineModbus::_CLASSNAME_FULL = "oldportal::fc::hardware::power::data::PowerLineModbus";


oldportal::fc::hardware::power::data::PowerLineModbus::PowerLineModbus()

{//BEGIN_c5ce604259e3b4b40eaaea2ea791eb15
    // set structure sizeof
    _modbus_registers_sizeof = _controllerData.getModbusRegistersSizeof() +
            //_driverCalculationConstants.getModbusRegistersSizeof() +
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
}//END_c5ce604259e3b4b40eaaea2ea791eb15


void oldportal::fc::hardware::power::data::PowerLineModbus::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_97521a9dcee40af70bad83b88bd91859
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
}//END_97521a9dcee40af70bad83b88bd91859

void oldportal::fc::hardware::power::data::PowerLineModbus::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_c4b7eb5caeb2a84acca57fa34e6c7031
    assert(registers);

    LOG4CXX_ERROR(logger, "function PowerLineModbus::loadFromRegisterArray(const uint16_t* registers) is not supported");
}//END_c4b7eb5caeb2a84acca57fa34e6c7031

void oldportal::fc::hardware::power::data::PowerLineModbus::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_565270738cb23f7c1bc309d5fa5d5db3
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
}//END_565270738cb23f7c1bc309d5fa5d5db3

void oldportal::fc::hardware::power::data::PowerLineModbus::saveToRegisterArray(uint16_t* registers)
{//BEGIN_120c39e007483de4964bb590810b4079
    assert(registers);

    LOG4CXX_ERROR(logger, "function PowerLineModbus::saveToRegisterArray(uint16_t* registers) is not supported");
}//END_120c39e007483de4964bb590810b4079


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE