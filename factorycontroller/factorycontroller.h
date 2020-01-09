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
#ifndef H_4908f413ff81a4c0be5d32ee281f9ae6_H
#define H_4908f413ff81a4c0be5d32ee281f9ae6_H




//BEGIN_PROJECT_COMMENT
/**
OldPortal Factory Controller project.
*/
//END_PROJECT_COMMENT


//BEGIN_USER_SECTION_0
#define FACTORYCONTROLLER_HEADER

// C Standard Libraries
#include <cstdint>

// diagnostics
#include <cassert>
#include <cerrno>
#include <exception>
#include <stdexcept>

// C++ Standard Libraries
#include <memory>
#include <string>
#include <atomic>
#include <array>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <limits>
#include <typeinfo>
#include <functional>

// Boost
#include <boost/date_time/posix_time/posix_time.hpp>

#include <boost/crc.hpp>

#include <boost/property_tree/ptree.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <boost/format.hpp>

// Third party libraries
#include <modbus/modbus.h>
// fix libmodbus version before 3.1.2
#ifndef MODBUS_MAX_PDU_LENGTH
#define MODBUS_MAX_PDU_LENGTH 256
#endif

/**
 * UTILS FUNCTIONS
 **/
#ifndef MODBUS_GET_HIGH_BYTE
#define MODBUS_GET_HIGH_BYTE(data) (((data) >> 8) & 0xFF)
#endif

#ifndef MODBUS_GET_LOW_BYTE
#define MODBUS_GET_LOW_BYTE(data) ((data) & 0xFF)
#endif

#ifndef MODBUS_GET_INT64_FROM_INT16
#define MODBUS_GET_INT64_FROM_INT16(tab_int16, index) \
    (((int64_t)tab_int16[(index)    ] << 48) + \
     ((int64_t)tab_int16[(index) + 1] << 32) + \
     ((int64_t)tab_int16[(index) + 2] << 16) + \
      (int64_t)tab_int16[(index) + 3])
#endif

#ifndef MODBUS_GET_INT32_FROM_INT16
#define MODBUS_GET_INT32_FROM_INT16(tab_int16, index) ((tab_int16[(index)] << 16) + tab_int16[(index) + 1])
#endif

#ifndef MODBUS_GET_INT16_FROM_INT8
#define MODBUS_GET_INT16_FROM_INT8(tab_int8, index) ((tab_int8[(index)] << 8) + tab_int8[(index) + 1])
#endif

#ifndef MODBUS_SET_INT16_TO_INT8
#define MODBUS_SET_INT16_TO_INT8(tab_int8, index, value) \
    do { \
        tab_int8[(index)] = (value) >> 8;  \
        tab_int8[(index) + 1] = (value) & 0xFF; \
    } while (0)
#endif

#ifndef MODBUS_SET_INT32_TO_INT16
#define MODBUS_SET_INT32_TO_INT16(tab_int16, index, value) \
    do { \
        tab_int16[(index)    ] = (value) >> 16; \
        tab_int16[(index) + 1] = (value); \
    } while (0)
#endif

#ifndef MODBUS_SET_INT64_TO_INT16
#define MODBUS_SET_INT64_TO_INT16(tab_int16, index, value) \
    do { \
        tab_int16[(index)    ] = (value) >> 48; \
        tab_int16[(index) + 1] = (value) >> 32; \
        tab_int16[(index) + 2] = (value) >> 16; \
        tab_int16[(index) + 3] = (value); \
    } while (0)
#endif


#include <log4cxx/logger.h>

#include "../util/util.h"

//END_USER_SECTION_0


//BEGIN_TYPE_DECLARATION_10e882b2ea715e905fcda554861a73bf NETWORK_TIME
typedef uint64_t NETWORK_TIME;// time interval in milliseconds
//END_TYPE_DECLARATION_10e882b2ea715e905fcda554861a73bf NETWORK_TIME
//BEGIN_TYPE_DECLARATION_98eb91d563cc52091f39b953078892a3 modbus_mapping_t
/* libmodbus mapping */
//END_TYPE_DECLARATION_98eb91d563cc52091f39b953078892a3 modbus_mapping_t
//BEGIN_TYPE_DECLARATION_72767107e7694a839e6e9825d968b14f modbus_t
/* libmodbus context */
//END_TYPE_DECLARATION_72767107e7694a839e6e9825d968b14f modbus_t


// class predeclarations:
namespace oldportal 
{
namespace fc 
{
namespace erpconnector 
{
class Connector;
class StateProxy;
class TaskProxy;

}// namespace erpconnector
namespace factory 
{
namespace cnc 
{
class ChangeToolOperation;
class MashineCenterInterface;
class Tool;
class ToolSet;

namespace edm 
{
class RepairToolOperation;

}// namespace edm
namespace proc 
{
class CNCExecutor;

}// namespace proc
namespace toolpath 
{
class ToolPath;

}// namespace toolpath
namespace wood 
{
class FixPartOperation;
class UnfixPartOperation;

}// namespace wood
}// namespace cnc
namespace handlerobot 
{
class HandleRobotExecutor;
class MovePartOperation;

}// namespace handlerobot
namespace manufacturing 
{
class Factory;
class FactoryLoader;

namespace proc 
{
class ConfigurationLoaderTagHandler;
class DefaultTagHandler;
class FactoryConfigurationFileLoader;
class FactoryPureProgramLoader;

}// namespace proc
}// namespace manufacturing
namespace printer3d 
{
class Printer3DExecutor;
class Printer3DOperation;

}// namespace printer3d
namespace warehouse 
{
class StorageManager;
class StoragePallet;
class StoragePalletPlace;

}// namespace warehouse
}// namespace factory
namespace hardware 
{
class HardwareDevice;
class HardwareDeviceProcess;
class HardwarePlugin;

namespace edm 
{
class EDMPowerSource;
class EDMWorkMode;

namespace command 
{
class GetEDMState;
class StartEDM;
class StopEDM;

}// namespace command
namespace data 
{
struct EDMDriverCalculationConstants;
struct EDMDriverData;
struct EDMDriverDataInput;
class EDMModbus;

}// namespace data
namespace proc 
{
class EDMProcess;

}// namespace proc
}// namespace edm
namespace mechatronics 
{
class Motor;
struct MotorProperties;
class MotorSettings;

namespace command 
{
class AccelerationMotion;
class CurveMotion;
class GetMotionState;
class LinearMotion;
class StepMotion;
class StopMotion;
class ToEndPositionMotion;

}// namespace command
namespace data 
{
struct StepMotorDriverCalculationConstants;
struct StepMotorDriverData;
struct StepMotorDriverDataInput;
struct StepMotorModbus;

}// namespace data
namespace proc 
{
class AccelerationMotion;
class ConstantSpeedMotion;
class CurveMotion;
class LinearMotion;
class Motion;
class StepMotion;

}// namespace proc
}// namespace mechatronics
namespace metallurgy 
{
class InductionHeater;
class InductionHeaterSettings;

namespace command 
{
class GetInductorState;
class StartHeating;
class StopHeating;

}// namespace command
namespace data 
{
struct InductorDriverCalculationConstants;
struct InductorDriverData;
struct InductorDriverDataInput;
class InductorModbus;

}// namespace data
namespace proc 
{
class InductionMeltingProcess;

}// namespace proc
}// namespace metallurgy
namespace power 
{
class EnergyAccumulator;
class EnergyNetwork;
class EnergySource;
class EnergySourceInterface;
class PowerBus;

namespace command 
{
class GetPowerLineState;
class SetPowerLineSettings;
class StopPowerLine;

}// namespace command
namespace data 
{
struct PowerLineDriverCalculationConstants;
struct PowerLineDriverData;
struct PowerLineDriverDataInput;
class PowerLineModbus;

}// namespace data
namespace proc 
{
class PowerLineProcess;

}// namespace proc
}// namespace power
namespace welding 
{
class WeldingPowerSource;
class WeldingPowerSourceMode;
class WeldingPowerSourceSettings;

namespace command 
{
class GetWeldingState;
class StartWelding;
class StopWelding;

}// namespace command
namespace data 
{
struct WeldingDriverCalculationConstants;
struct WeldingDriverData;
struct WeldingDriverDataInput;
class WeldingModbus;

}// namespace data
namespace proc 
{
class WeldingProcess;

}// namespace proc
}// namespace welding
}// namespace hardware
namespace network 
{
class ConfigurationLoader;
class DeviceCommand;
class Network;
struct NetworkClock;
class NetworkController;
class NetworkDevice;

namespace command 
{
class DeviceIDReport;
class DeviceStateReport;
class NetworkTimeSynchronization;
class ReadAndClearLog;

namespace scheduled 
{
class ScheduledCommandRequest;
class ScheduledCommandResult;
class ScheduledDeviceCommandQueue;

}// namespace scheduled
}// namespace command
namespace modbus 
{
class ModbusDevice;
class ModbusDeviceCommand;
struct ModbusMessagePair;
class ModbusMessageWrapper;
class ModbusNetworkController;
class ModbusNetworkSettings;
class ModbusSerialRTUNetworkController;
class ModbusTCPIPNetworkController;
class SerialPortSettings;
class TCPIPAddressSettings;

namespace data 
{
struct ControllerData;
class InterfaceSettings;
class ModbusRegistersMapping;
class SystemLogReport;

}// namespace data
}// namespace modbus
}// namespace network
namespace scheduler 
{
class ExecutorInterface;
class LocalConfiguration;
class Project;
class ProjectTemplate;
class Resource;
class Scheduler;
class Task;
class TaskLogMessage;
class TaskTemplate;

}// namespace scheduler
}// namespace fc
}// namespace oldportal


// Make sure the inline implementations are skipped
#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#undef OBJECTS_BUILDER_PROJECT_INLINES
#endif

// Include project classes, for declarations
#include "erpconnector/_group_erpconnector.h"
#include "factory/_group_factory.h"
#include "hardware/_group_hardware.h"
#include "network/_group_network.h"
#include "scheduler/_group_scheduler.h"
#include "erpconnector/Connector.h"
#include "erpconnector/StateProxy.h"
#include "erpconnector/TaskProxy.h"
#include "scheduler/TaskTemplate.h"
#include "factory/cnc/ChangeToolOperation.h"
#include "factory/cnc/MashineCenterInterface.h"
#include "scheduler/Resource.h"
#include "factory/cnc/Tool.h"
#include "factory/cnc/ToolSet.h"
#include "factory/cnc/edm/RepairToolOperation.h"
#include "scheduler/ExecutorInterface.h"
#include "factory/cnc/proc/CNCExecutor.h"
#include "factory/cnc/toolpath/ToolPath.h"
#include "factory/cnc/wood/FixPartOperation.h"
#include "factory/cnc/wood/UnfixPartOperation.h"
#include "factory/handlerobot/HandleRobotExecutor.h"
#include "factory/handlerobot/MovePartOperation.h"
#include "factory/manufacturing/Factory.h"
#include "factory/manufacturing/FactoryLoader.h"
#include "factory/manufacturing/proc/ConfigurationLoaderTagHandler.h"
#include "factory/manufacturing/proc/DefaultTagHandler.h"
#include "factory/manufacturing/proc/FactoryConfigurationFileLoader.h"
#include "factory/manufacturing/proc/FactoryPureProgramLoader.h"
#include "factory/printer3d/Printer3DExecutor.h"
#include "factory/printer3d/Printer3DOperation.h"
#include "factory/warehouse/StorageManager.h"
#include "factory/warehouse/StoragePallet.h"
#include "factory/warehouse/StoragePalletPlace.h"
#include "network/NetworkDevice.h"
#include "network/modbus/ModbusDevice.h"
#include "hardware/HardwareDevice.h"
#include "hardware/HardwareDeviceProcess.h"
#include "hardware/HardwarePlugin.h"
#include "hardware/edm/EDMWorkMode.h"
#include "hardware/edm/EDMPowerSource.h"
#include "network/DeviceCommand.h"
#include "network/modbus/ModbusDeviceCommand.h"
#include "hardware/edm/command/GetEDMState.h"
#include "hardware/edm/command/StartEDM.h"
#include "hardware/edm/command/StopEDM.h"
#include "network/modbus/data/ModbusRegistersMapping.h"
#include "hardware/edm/data/EDMDriverCalculationConstants.h"
#include "hardware/edm/data/EDMDriverData.h"
#include "hardware/edm/data/EDMDriverDataInput.h"
#include "network/modbus/data/SystemLogReport.h"
#include "network/modbus/data/InterfaceSettings.h"
#include "network/modbus/data/ControllerData.h"
#include "hardware/edm/data/EDMModbus.h"
#include "hardware/edm/proc/EDMProcess.h"
#include "hardware/mechatronics/data/StepMotorDriverDataInput.h"
#include "hardware/mechatronics/data/StepMotorDriverData.h"
#include "hardware/mechatronics/data/StepMotorDriverCalculationConstants.h"
#include "hardware/mechatronics/data/StepMotorModbus.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorProperties.h"
#include "hardware/mechatronics/Motor.h"
#include "hardware/mechatronics/command/AccelerationMotion.h"
#include "hardware/mechatronics/command/CurveMotion.h"
#include "hardware/mechatronics/command/GetMotionState.h"
#include "hardware/mechatronics/command/LinearMotion.h"
#include "hardware/mechatronics/command/StepMotion.h"
#include "hardware/mechatronics/command/StopMotion.h"
#include "hardware/mechatronics/command/ToEndPositionMotion.h"
#include "hardware/mechatronics/proc/Motion.h"
#include "hardware/mechatronics/proc/AccelerationMotion.h"
#include "hardware/mechatronics/proc/ConstantSpeedMotion.h"
#include "hardware/mechatronics/proc/CurveMotion.h"
#include "hardware/mechatronics/proc/LinearMotion.h"
#include "hardware/mechatronics/proc/StepMotion.h"
#include "hardware/metallurgy/InductionHeaterSettings.h"
#include "hardware/metallurgy/InductionHeater.h"
#include "hardware/metallurgy/command/GetInductorState.h"
#include "hardware/metallurgy/command/StartHeating.h"
#include "hardware/metallurgy/command/StopHeating.h"
#include "hardware/metallurgy/data/InductorDriverCalculationConstants.h"
#include "hardware/metallurgy/data/InductorDriverData.h"
#include "hardware/metallurgy/data/InductorDriverDataInput.h"
#include "hardware/metallurgy/data/InductorModbus.h"
#include "hardware/metallurgy/proc/InductionMeltingProcess.h"
#include "hardware/power/EnergyAccumulator.h"
#include "hardware/power/EnergyNetwork.h"
#include "hardware/power/EnergySource.h"
#include "hardware/power/EnergySourceInterface.h"
#include "hardware/power/PowerBus.h"
#include "hardware/power/command/GetPowerLineState.h"
#include "hardware/power/command/SetPowerLineSettings.h"
#include "hardware/power/command/StopPowerLine.h"
#include "hardware/power/data/PowerLineDriverCalculationConstants.h"
#include "hardware/power/data/PowerLineDriverData.h"
#include "hardware/power/data/PowerLineDriverDataInput.h"
#include "hardware/power/data/PowerLineModbus.h"
#include "hardware/power/proc/PowerLineProcess.h"
#include "hardware/welding/data/WeldingDriverDataInput.h"
#include "hardware/welding/data/WeldingDriverData.h"
#include "hardware/welding/data/WeldingDriverCalculationConstants.h"
#include "hardware/welding/data/WeldingModbus.h"
#include "hardware/welding/WeldingPowerSourceSettings.h"
#include "hardware/welding/WeldingPowerSourceMode.h"
#include "hardware/welding/WeldingPowerSource.h"
#include "hardware/welding/command/GetWeldingState.h"
#include "hardware/welding/command/StartWelding.h"
#include "hardware/welding/command/StopWelding.h"
#include "hardware/welding/proc/WeldingProcess.h"
#include "network/ConfigurationLoader.h"
#include "network/Network.h"
#include "network/NetworkClock.h"
#include "network/NetworkController.h"
#include "network/command/DeviceIDReport.h"
#include "network/command/DeviceStateReport.h"
#include "network/command/NetworkTimeSynchronization.h"
#include "network/command/ReadAndClearLog.h"
#include "network/command/scheduled/ScheduledCommandRequest.h"
#include "network/command/scheduled/ScheduledCommandResult.h"
#include "network/command/scheduled/ScheduledDeviceCommandQueue.h"
#include "network/modbus/ModbusMessagePair.h"
#include "network/modbus/ModbusMessageWrapper.h"
#include "network/modbus/SerialPortSettings.h"
#include "network/modbus/ModbusNetworkSettings.h"
#include "network/modbus/ModbusNetworkController.h"
#include "network/modbus/ModbusSerialRTUNetworkController.h"
#include "network/modbus/TCPIPAddressSettings.h"
#include "network/modbus/ModbusTCPIPNetworkController.h"
#include "scheduler/LocalConfiguration.h"
#include "scheduler/Project.h"
#include "scheduler/ProjectTemplate.h"
#include "scheduler/Scheduler.h"
#include "scheduler/Task.h"
#include "scheduler/TaskLogMessage.h"


// global members
namespace oldportal 
{
namespace fc 
{
// global variables declaration
extern log4cxx::LoggerPtr logger;
}// namespace fc
}// namespace oldportal


// global methods
namespace oldportal 
{
namespace fc 
{
// global methods declaration
}// namespace fc
}// namespace oldportal


#define OBJECTS_BUILDER_PROJECT_INLINES
// Inline functions:


// Include classes again, for inline implementation:
#include "erpconnector/_group_erpconnector.h"
#include "factory/_group_factory.h"
#include "hardware/_group_hardware.h"
#include "network/_group_network.h"
#include "scheduler/_group_scheduler.h"
#include "erpconnector/Connector.h"
#include "erpconnector/StateProxy.h"
#include "erpconnector/TaskProxy.h"
#include "scheduler/TaskTemplate.h"
#include "factory/cnc/ChangeToolOperation.h"
#include "factory/cnc/MashineCenterInterface.h"
#include "scheduler/Resource.h"
#include "factory/cnc/Tool.h"
#include "factory/cnc/ToolSet.h"
#include "factory/cnc/edm/RepairToolOperation.h"
#include "scheduler/ExecutorInterface.h"
#include "factory/cnc/proc/CNCExecutor.h"
#include "factory/cnc/toolpath/ToolPath.h"
#include "factory/cnc/wood/FixPartOperation.h"
#include "factory/cnc/wood/UnfixPartOperation.h"
#include "factory/handlerobot/HandleRobotExecutor.h"
#include "factory/handlerobot/MovePartOperation.h"
#include "factory/manufacturing/Factory.h"
#include "factory/manufacturing/FactoryLoader.h"
#include "factory/manufacturing/proc/ConfigurationLoaderTagHandler.h"
#include "factory/manufacturing/proc/DefaultTagHandler.h"
#include "factory/manufacturing/proc/FactoryConfigurationFileLoader.h"
#include "factory/manufacturing/proc/FactoryPureProgramLoader.h"
#include "factory/printer3d/Printer3DExecutor.h"
#include "factory/printer3d/Printer3DOperation.h"
#include "factory/warehouse/StorageManager.h"
#include "factory/warehouse/StoragePallet.h"
#include "factory/warehouse/StoragePalletPlace.h"
#include "network/NetworkDevice.h"
#include "network/modbus/ModbusDevice.h"
#include "hardware/HardwareDevice.h"
#include "hardware/HardwareDeviceProcess.h"
#include "hardware/HardwarePlugin.h"
#include "hardware/edm/EDMWorkMode.h"
#include "hardware/edm/EDMPowerSource.h"
#include "network/DeviceCommand.h"
#include "network/modbus/ModbusDeviceCommand.h"
#include "hardware/edm/command/GetEDMState.h"
#include "hardware/edm/command/StartEDM.h"
#include "hardware/edm/command/StopEDM.h"
#include "network/modbus/data/ModbusRegistersMapping.h"
#include "hardware/edm/data/EDMDriverCalculationConstants.h"
#include "hardware/edm/data/EDMDriverData.h"
#include "hardware/edm/data/EDMDriverDataInput.h"
#include "network/modbus/data/SystemLogReport.h"
#include "network/modbus/data/InterfaceSettings.h"
#include "network/modbus/data/ControllerData.h"
#include "hardware/edm/data/EDMModbus.h"
#include "hardware/edm/proc/EDMProcess.h"
#include "hardware/mechatronics/data/StepMotorDriverDataInput.h"
#include "hardware/mechatronics/data/StepMotorDriverData.h"
#include "hardware/mechatronics/data/StepMotorDriverCalculationConstants.h"
#include "hardware/mechatronics/data/StepMotorModbus.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorProperties.h"
#include "hardware/mechatronics/Motor.h"
#include "hardware/mechatronics/command/AccelerationMotion.h"
#include "hardware/mechatronics/command/CurveMotion.h"
#include "hardware/mechatronics/command/GetMotionState.h"
#include "hardware/mechatronics/command/LinearMotion.h"
#include "hardware/mechatronics/command/StepMotion.h"
#include "hardware/mechatronics/command/StopMotion.h"
#include "hardware/mechatronics/command/ToEndPositionMotion.h"
#include "hardware/mechatronics/proc/Motion.h"
#include "hardware/mechatronics/proc/AccelerationMotion.h"
#include "hardware/mechatronics/proc/ConstantSpeedMotion.h"
#include "hardware/mechatronics/proc/CurveMotion.h"
#include "hardware/mechatronics/proc/LinearMotion.h"
#include "hardware/mechatronics/proc/StepMotion.h"
#include "hardware/metallurgy/InductionHeaterSettings.h"
#include "hardware/metallurgy/InductionHeater.h"
#include "hardware/metallurgy/command/GetInductorState.h"
#include "hardware/metallurgy/command/StartHeating.h"
#include "hardware/metallurgy/command/StopHeating.h"
#include "hardware/metallurgy/data/InductorDriverCalculationConstants.h"
#include "hardware/metallurgy/data/InductorDriverData.h"
#include "hardware/metallurgy/data/InductorDriverDataInput.h"
#include "hardware/metallurgy/data/InductorModbus.h"
#include "hardware/metallurgy/proc/InductionMeltingProcess.h"
#include "hardware/power/EnergyAccumulator.h"
#include "hardware/power/EnergyNetwork.h"
#include "hardware/power/EnergySource.h"
#include "hardware/power/EnergySourceInterface.h"
#include "hardware/power/PowerBus.h"
#include "hardware/power/command/GetPowerLineState.h"
#include "hardware/power/command/SetPowerLineSettings.h"
#include "hardware/power/command/StopPowerLine.h"
#include "hardware/power/data/PowerLineDriverCalculationConstants.h"
#include "hardware/power/data/PowerLineDriverData.h"
#include "hardware/power/data/PowerLineDriverDataInput.h"
#include "hardware/power/data/PowerLineModbus.h"
#include "hardware/power/proc/PowerLineProcess.h"
#include "hardware/welding/data/WeldingDriverDataInput.h"
#include "hardware/welding/data/WeldingDriverData.h"
#include "hardware/welding/data/WeldingDriverCalculationConstants.h"
#include "hardware/welding/data/WeldingModbus.h"
#include "hardware/welding/WeldingPowerSourceSettings.h"
#include "hardware/welding/WeldingPowerSourceMode.h"
#include "hardware/welding/WeldingPowerSource.h"
#include "hardware/welding/command/GetWeldingState.h"
#include "hardware/welding/command/StartWelding.h"
#include "hardware/welding/command/StopWelding.h"
#include "hardware/welding/proc/WeldingProcess.h"
#include "network/ConfigurationLoader.h"
#include "network/Network.h"
#include "network/NetworkClock.h"
#include "network/NetworkController.h"
#include "network/command/DeviceIDReport.h"
#include "network/command/DeviceStateReport.h"
#include "network/command/NetworkTimeSynchronization.h"
#include "network/command/ReadAndClearLog.h"
#include "network/command/scheduled/ScheduledCommandRequest.h"
#include "network/command/scheduled/ScheduledCommandResult.h"
#include "network/command/scheduled/ScheduledDeviceCommandQueue.h"
#include "network/modbus/ModbusMessagePair.h"
#include "network/modbus/ModbusMessageWrapper.h"
#include "network/modbus/SerialPortSettings.h"
#include "network/modbus/ModbusNetworkSettings.h"
#include "network/modbus/ModbusNetworkController.h"
#include "network/modbus/ModbusSerialRTUNetworkController.h"
#include "network/modbus/TCPIPAddressSettings.h"
#include "network/modbus/ModbusTCPIPNetworkController.h"
#include "scheduler/LocalConfiguration.h"
#include "scheduler/Project.h"
#include "scheduler/ProjectTemplate.h"
#include "scheduler/Scheduler.h"
#include "scheduler/Task.h"
#include "scheduler/TaskLogMessage.h"




//BEGIN_USER_SECTION_1
#ifndef FACTORY_HARDWARE_EMULATOR_HEADER_ADDED
#include "../factory-hardware-emulator/factory-hardware-emulator.h"
#define FACTORY_HARDWARE_EMULATOR_HEADER_ADDED
#endif
//END_USER_SECTION_1

#endif // H_4908f413ff81a4c0be5d32ee281f9ae6_H