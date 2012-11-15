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
*    Copyright (C) Dmitry Ognyannikov, 2012
*/
#ifndef H_4908f413ff81a4c0be5d32ee281f9ae6_H
#define H_4908f413ff81a4c0be5d32ee281f9ae6_H




//BEGIN_PROJECT_COMMENT
/**
OldPortal Factory Controller project.
*/
//END_PROJECT_COMMENT


//BEGIN_USER_SECTION_0
#include <QtCore>
//END_USER_SECTION_0




// class predeclarations:
namespace oldportal 
{
namespace fc 
{

namespace connector 
{
class ConfigurationProxy;
class Connector;
class StateProxy;
class TaskProxy;

}// namespace connector
namespace executor 
{
class Configuration;
class ConfigurationLoader;
class ExecutorApplication;
class ExecutorInterface;
class LocalConfiguration;
class Resource;
class Task;

}// namespace executor
namespace hardware 
{
class HardwareDevice;

namespace mechatronics 
{
class Motor;
struct MotorProperties;
class MotorSettings;

}// namespace mechatronics
}// namespace hardware
namespace network 
{
class ConfigurationLoader;
class DeviceCommand;
class Network;
class NetworkController;
class NetworkDevice;

namespace modbus 
{
class ModbusDevice;
class ModbusMessagePair;

}// namespace modbus
}// namespace network
namespace storage 
{
class LocalResources;
class LocalStorage;

}// namespace storage
namespace util 
{

}// namespace util
}// namespace fc
}// namespace oldportal


// Make sure the inline implementations are skipped
#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#undef OBJECTS_BUILDER_PROJECT_INLINES
#endif

// Include project classes, for declarations
#include "connector/ConfigurationProxy.h"
#include "connector/Connector.h"
#include "connector/StateProxy.h"
#include "connector/TaskProxy.h"
#include "executor/Configuration.h"
#include "executor/ConfigurationLoader.h"
#include "executor/ExecutorApplication.h"
#include "executor/ExecutorInterface.h"
#include "executor/LocalConfiguration.h"
#include "executor/Resource.h"
#include "executor/Task.h"
#include "network/NetworkDevice.h"
#include "network/modbus/ModbusDevice.h"
#include "hardware/HardwareDevice.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorProperties.h"
#include "hardware/mechatronics/Motor.h"
#include "network/ConfigurationLoader.h"
#include "network/DeviceCommand.h"
#include "network/Network.h"
#include "network/NetworkController.h"
#include "network/modbus/ModbusMessagePair.h"
#include "storage/LocalResources.h"
#include "storage/LocalStorage.h"
#include "connector/Connector.h"
#include "executor/Executor.h"
#include "hardware/Hardware.h"
#include "network/Network.h"
#include "storage/Storage.h"
#include "util/Util.h"


// global members
namespace oldportal 
{
namespace fc 
{

}// namespace fc
}// namespace oldportal


// global methods
namespace oldportal 
{
namespace fc 
{

}// namespace fc
}// namespace oldportal


#define OBJECTS_BUILDER_PROJECT_INLINES
// Inline functions:


// Include classes again, for inline implementation:
#include "connector/ConfigurationProxy.h"
#include "connector/Connector.h"
#include "connector/StateProxy.h"
#include "connector/TaskProxy.h"
#include "executor/Configuration.h"
#include "executor/ConfigurationLoader.h"
#include "executor/ExecutorApplication.h"
#include "executor/ExecutorInterface.h"
#include "executor/LocalConfiguration.h"
#include "executor/Resource.h"
#include "executor/Task.h"
#include "network/NetworkDevice.h"
#include "network/modbus/ModbusDevice.h"
#include "hardware/HardwareDevice.h"
#include "hardware/mechatronics/MotorSettings.h"
#include "hardware/mechatronics/MotorProperties.h"
#include "hardware/mechatronics/Motor.h"
#include "network/ConfigurationLoader.h"
#include "network/DeviceCommand.h"
#include "network/Network.h"
#include "network/NetworkController.h"
#include "network/modbus/ModbusMessagePair.h"
#include "storage/LocalResources.h"
#include "storage/LocalStorage.h"
#include "connector/Connector.h"
#include "executor/Executor.h"
#include "hardware/Hardware.h"
#include "network/Network.h"
#include "storage/Storage.h"
#include "util/Util.h"




//BEGIN_USER_SECTION_1

//END_USER_SECTION_1

#endif // H_4908f413ff81a4c0be5d32ee281f9ae6_H