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


const char* const  oldportal::fc::hardware::edm::data::EDMModbus::_CLASSNAME_FULL = "oldportal::fc::hardware::edm::data::EDMModbus";


oldportal::fc::hardware::edm::data::EDMModbus::EDMModbus()

{//BEGIN_81432d6c47c41e6d38f1bbea8da094e7
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
}//END_81432d6c47c41e6d38f1bbea8da094e7


void oldportal::fc::hardware::edm::data::EDMModbus::loadFromRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_4162d9406e76adf9467686372fd04332
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
}//END_4162d9406e76adf9467686372fd04332

void oldportal::fc::hardware::edm::data::EDMModbus::loadFromRegisterArray(const uint16_t* registers)
{//BEGIN_3c95fe6f8d26c43e7305f25c166fe6c3
    assert(registers);

    LOG4CXX_ERROR(logger, "function EDMModbus::loadFromRegisterArray(const uint16_t* registers) is not supported");
}//END_3c95fe6f8d26c43e7305f25c166fe6c3

void oldportal::fc::hardware::edm::data::EDMModbus::saveToRegisterArray(const modbus_mapping_t* modbus_mapping)
{//BEGIN_2e5dea857f89651b9f8ba0e51b7ec313
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
}//END_2e5dea857f89651b9f8ba0e51b7ec313

void oldportal::fc::hardware::edm::data::EDMModbus::saveToRegisterArray(uint16_t* registers)
{//BEGIN_e19ec87b1bdf55cf010603c02b9f20e2
    assert(registers);

    LOG4CXX_ERROR(logger, "function EDMModbus::saveToRegisterArray(uint16_t* registers) is not supported");
}//END_e19ec87b1bdf55cf010603c02b9f20e2


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE