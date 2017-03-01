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
#ifndef H_fb313121fe57e0646771a031b4e0fd1f_H
#define H_fb313121fe57e0646771a031b4e0fd1f_H




//BEGIN_PROJECT_COMMENT
/**
Emulate factory embedded Modbus network with embedded device controllers.

For:
- Testing and development purposes.
- Factory MES CNC programs verification.
- Factory MES tasks verification.

*/
//END_PROJECT_COMMENT


//BEGIN_USER_SECTION_0
#define FACTORY_HARDWARE_EMULATOR_HEADER

// C Standard Libraries
#include <cstdint>

// diagnostics
#include <cassert>
#include <cerrno>
#include <stdexcept>

// C++ Standard Libraries
#include <memory>
#include <string>
#include <atomic>
#include <array>
#include <queue>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <limits>
#include <typeinfo>
#include <csignal>

// Boost
#include <boost/date_time/posix_time/posix_time.hpp>

#include <boost/crc.hpp>

//#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
//#include <boost/log/utility/setup/file.hpp>
//#include <boost/log/sources/severity_logger.hpp>

#include <boost/property_tree/ptree.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

// Third party libraries
#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>

#include <log4cxx/logger.h>

#ifndef FACTORYCONTROLLER_HEADER
#include "../factorycontroller/factorycontroller.h"
#endif
//END_USER_SECTION_0


//BEGIN_TYPE_DECLARATION_12a3f5a7f8c363b6a6ba95729499e214 NETWORK_TIME
typedef uint64_t NETWORK_TIME;
//END_TYPE_DECLARATION_12a3f5a7f8c363b6a6ba95729499e214 NETWORK_TIME
//BEGIN_TYPE_DECLARATION_656354ee5fc21c11e57bf6aa268df51b int16_t

//END_TYPE_DECLARATION_656354ee5fc21c11e57bf6aa268df51b int16_t
//BEGIN_TYPE_DECLARATION_3319d7fb96913b6df79f6e41b0cf3c5b int32_t

//END_TYPE_DECLARATION_3319d7fb96913b6df79f6e41b0cf3c5b int32_t
//BEGIN_TYPE_DECLARATION_470dc447b5d28c6118aeec5dfb774469 int64_t

//END_TYPE_DECLARATION_470dc447b5d28c6118aeec5dfb774469 int64_t
//BEGIN_TYPE_DECLARATION_eca6ac20a41e554764c38376960d1938 int8_t

//END_TYPE_DECLARATION_eca6ac20a41e554764c38376960d1938 int8_t
//BEGIN_TYPE_DECLARATION_15b4a7c72e42802c0243269250ce30d9 modbus_mapping_t
/* libmodbus mapping */
//END_TYPE_DECLARATION_15b4a7c72e42802c0243269250ce30d9 modbus_mapping_t
//BEGIN_TYPE_DECLARATION_6acb9435986539fcbffc1772eb77876d modbus_t
/* libmodbus context */
//END_TYPE_DECLARATION_6acb9435986539fcbffc1772eb77876d modbus_t


// class predeclarations:
namespace oldportal 
{
namespace fhe 
{
class EmulatorApplication;

namespace device 
{
class Device;

}// namespace device
namespace hardware 
{
class HardwareDevice;

namespace mechatronics 
{
class Motor;
struct MotorModbus;
class MotorSettings;
class StepMotor;

}// namespace mechatronics
}// namespace hardware
namespace network 
{
class ModbusNetworkController;
struct NetworkClock;

namespace scheduled 
{
class ScheduledCommandRequest;
class ScheduledCommandResult;
class ScheduledDeviceCommandQueue;

}// namespace scheduled
}// namespace network
namespace system 
{

}// namespace system
}// namespace fhe
}// namespace oldportal


// Make sure the inline implementations are skipped
#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#undef OBJECTS_BUILDER_PROJECT_INLINES
#endif

// Include project classes, for declarations
#include "device/_group_device.h"
#include "hardware/_group_hardware.h"
#include "network/_group_network.h"
#include "system/_group_system.h"
#include "network/NetworkClock.h"
#include "EmulatorApplication.h"
#include "device/Device.h"
#include "hardware/HardwareDevice.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorModbus.h"
#include "hardware/mechatronics/Motor.h"
#include "hardware/mechatronics/StepMotor.h"
#include "network/ModbusNetworkController.h"
#include "network/scheduled/ScheduledCommandRequest.h"
#include "network/scheduled/ScheduledCommandResult.h"
#include "network/scheduled/ScheduledDeviceCommandQueue.h"


// global members
namespace oldportal 
{
namespace fhe 
{
// global variables declaration
extern log4cxx::LoggerPtr logger;
}// namespace fhe
}// namespace oldportal


// global methods
namespace oldportal 
{
namespace fhe 
{
// global methods declaration
}// namespace fhe
}// namespace oldportal


#define OBJECTS_BUILDER_PROJECT_INLINES
// Inline functions:


// Include classes again, for inline implementation:
#include "device/_group_device.h"
#include "hardware/_group_hardware.h"
#include "network/_group_network.h"
#include "system/_group_system.h"
#include "network/NetworkClock.h"
#include "EmulatorApplication.h"
#include "device/Device.h"
#include "hardware/HardwareDevice.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorModbus.h"
#include "hardware/mechatronics/Motor.h"
#include "hardware/mechatronics/StepMotor.h"
#include "network/ModbusNetworkController.h"
#include "network/scheduled/ScheduledCommandRequest.h"
#include "network/scheduled/ScheduledCommandResult.h"
#include "network/scheduled/ScheduledDeviceCommandQueue.h"




//BEGIN_USER_SECTION_1

//END_USER_SECTION_1

#endif // H_fb313121fe57e0646771a031b4e0fd1f_H