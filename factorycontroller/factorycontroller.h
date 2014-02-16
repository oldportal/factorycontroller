/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*    
*    factorycontroller is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factorycontroller; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/
#ifndef H_4908f413ff81a4c0be5d32ee281f9ae6_H
#define H_4908f413ff81a4c0be5d32ee281f9ae6_H




//BEGIN_PROJECT_COMMENT
/**
OldPortal Factory Controller project.
*/
//END_PROJECT_COMMENT


//BEGIN_USER_SECTION_0
#define __STDC_LIMIT_MACROS
#include <cstdint>
#include <cassert>

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

#include <boost/date_time/posix_time/posix_time.hpp>

#include <boost/crc.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>
//END_USER_SECTION_0


//BEGIN_TYPE_DECLARATION_10e882b2ea715e905fcda554861a73bf NETWORK_TIME
typedef uint64_t NETWORK_TIME;
//END_TYPE_DECLARATION_10e882b2ea715e905fcda554861a73bf NETWORK_TIME
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

namespace edm 
{
class EDMPowerSource;
class EDMWorkMode;

}// namespace edm
namespace mechatronics 
{
class Motor;
struct MotorProperties;
class MotorSettings;

namespace command 
{
class AccelerationMotion;
class ConstantSpeedMotion;
class CurveMotion;
class LinearMotion;
class StepMotion;

}// namespace command
}// namespace mechatronics
namespace metallurgy 
{
class InductionHeater;
class InductionHeaterSettings;

}// namespace metallurgy
namespace power 
{
class EnergyAccumulator;
class EnergyNetwork;
class EnergySource;
class EnergySourceInterface;
class PowerBus;

}// namespace power
namespace welding 
{
class WeldingPowerSource;
class WeldingPowerSourceMode;
class WeldingPowerSourceSettings;

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
class NetworkErrorStatistics;

namespace command 
{
class NetworkTimeSynchronization;
class StateReport;

}// namespace command
namespace modbus 
{
class ModbusDevice;
class ModbusDeviceCommand;
struct ModbusMessagePair;
class ModbusMessageWrapper;
class ModbusNetworkController;

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
namespace system 
{

namespace logger 
{

}// namespace logger
namespace serialization 
{
class Archive;
class Serializable;

}// namespace serialization
namespace storage 
{
class LocalResources;
class LocalStorage;

}// namespace storage
namespace util 
{
class StepCounter;

}// namespace util
}// namespace system
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
#include "system/_group_system.h"
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
#include "system/util/StepCounter.h"
#include "factory/manufacturing/Factory.h"
#include "factory/manufacturing/FactoryLoader.h"
#include "factory/manufacturing/proc/FactoryPureProgramLoader.h"
#include "factory/printer3d/Printer3DExecutor.h"
#include "factory/printer3d/Printer3DOperation.h"
#include "factory/warehouse/StorageManager.h"
#include "factory/warehouse/StoragePallet.h"
#include "factory/warehouse/StoragePalletPlace.h"
#include "network/NetworkErrorStatistics.h"
#include "network/NetworkDevice.h"
#include "network/modbus/ModbusDevice.h"
#include "hardware/HardwareDevice.h"
#include "hardware/edm/EDMWorkMode.h"
#include "hardware/edm/EDMPowerSource.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorProperties.h"
#include "hardware/mechatronics/Motor.h"
#include "network/DeviceCommand.h"
#include "network/modbus/ModbusDeviceCommand.h"
#include "hardware/mechatronics/command/AccelerationMotion.h"
#include "hardware/mechatronics/command/ConstantSpeedMotion.h"
#include "hardware/mechatronics/command/CurveMotion.h"
#include "hardware/mechatronics/command/LinearMotion.h"
#include "hardware/mechatronics/command/StepMotion.h"
#include "hardware/metallurgy/InductionHeaterSettings.h"
#include "hardware/metallurgy/InductionHeater.h"
#include "hardware/power/EnergyAccumulator.h"
#include "hardware/power/EnergyNetwork.h"
#include "hardware/power/EnergySource.h"
#include "hardware/power/EnergySourceInterface.h"
#include "hardware/power/PowerBus.h"
#include "hardware/welding/WeldingPowerSourceSettings.h"
#include "hardware/welding/WeldingPowerSourceMode.h"
#include "hardware/welding/WeldingPowerSource.h"
#include "network/ConfigurationLoader.h"
#include "network/Network.h"
#include "network/NetworkClock.h"
#include "network/NetworkController.h"
#include "network/command/NetworkTimeSynchronization.h"
#include "network/command/StateReport.h"
#include "network/modbus/ModbusMessagePair.h"
#include "network/modbus/ModbusMessageWrapper.h"
#include "network/modbus/ModbusNetworkController.h"
#include "scheduler/LocalConfiguration.h"
#include "scheduler/Project.h"
#include "scheduler/ProjectTemplate.h"
#include "scheduler/Scheduler.h"
#include "scheduler/Task.h"
#include "scheduler/TaskLogMessage.h"
#include "system/serialization/Archive.h"
#include "system/serialization/Serializable.h"
#include "system/storage/LocalResources.h"
#include "system/storage/LocalStorage.h"


// global members
namespace oldportal 
{
namespace fc 
{
// global variables declaration
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
#include "system/_group_system.h"
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
#include "system/util/StepCounter.h"
#include "factory/manufacturing/Factory.h"
#include "factory/manufacturing/FactoryLoader.h"
#include "factory/manufacturing/proc/FactoryPureProgramLoader.h"
#include "factory/printer3d/Printer3DExecutor.h"
#include "factory/printer3d/Printer3DOperation.h"
#include "factory/warehouse/StorageManager.h"
#include "factory/warehouse/StoragePallet.h"
#include "factory/warehouse/StoragePalletPlace.h"
#include "network/NetworkErrorStatistics.h"
#include "network/NetworkDevice.h"
#include "network/modbus/ModbusDevice.h"
#include "hardware/HardwareDevice.h"
#include "hardware/edm/EDMWorkMode.h"
#include "hardware/edm/EDMPowerSource.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorProperties.h"
#include "hardware/mechatronics/Motor.h"
#include "network/DeviceCommand.h"
#include "network/modbus/ModbusDeviceCommand.h"
#include "hardware/mechatronics/command/AccelerationMotion.h"
#include "hardware/mechatronics/command/ConstantSpeedMotion.h"
#include "hardware/mechatronics/command/CurveMotion.h"
#include "hardware/mechatronics/command/LinearMotion.h"
#include "hardware/mechatronics/command/StepMotion.h"
#include "hardware/metallurgy/InductionHeaterSettings.h"
#include "hardware/metallurgy/InductionHeater.h"
#include "hardware/power/EnergyAccumulator.h"
#include "hardware/power/EnergyNetwork.h"
#include "hardware/power/EnergySource.h"
#include "hardware/power/EnergySourceInterface.h"
#include "hardware/power/PowerBus.h"
#include "hardware/welding/WeldingPowerSourceSettings.h"
#include "hardware/welding/WeldingPowerSourceMode.h"
#include "hardware/welding/WeldingPowerSource.h"
#include "network/ConfigurationLoader.h"
#include "network/Network.h"
#include "network/NetworkClock.h"
#include "network/NetworkController.h"
#include "network/command/NetworkTimeSynchronization.h"
#include "network/command/StateReport.h"
#include "network/modbus/ModbusMessagePair.h"
#include "network/modbus/ModbusMessageWrapper.h"
#include "network/modbus/ModbusNetworkController.h"
#include "scheduler/LocalConfiguration.h"
#include "scheduler/Project.h"
#include "scheduler/ProjectTemplate.h"
#include "scheduler/Scheduler.h"
#include "scheduler/Task.h"
#include "scheduler/TaskLogMessage.h"
#include "system/serialization/Archive.h"
#include "system/serialization/Serializable.h"
#include "system/storage/LocalResources.h"
#include "system/storage/LocalStorage.h"




//BEGIN_USER_SECTION_1

//END_USER_SECTION_1

#endif // H_4908f413ff81a4c0be5d32ee281f9ae6_H