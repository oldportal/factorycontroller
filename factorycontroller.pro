#-------------------------------------------------
#
# Project created by QtCreator 2012-11-13T23:49:24
#
#-------------------------------------------------

#QT       += core

QT       -= gui core

TARGET = factory_controller
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += boost
CONFIG   += thread
CONFIG   +=object_parallel_to_source

LIBS	+= -lboost_system -lpthread -lmodbus -lboost_program_options -llog4cxx 

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

PRECOMPILED_HEADER = factorycontroller/factorycontroller.h 

SOURCES += main.cpp \
    factorycontroller/_group_factorycontroller.cpp \ 
    factorycontroller/erpconnector/StateProxy.cpp \
    factorycontroller/erpconnector/_group_erpconnector.cpp \
    factorycontroller/erpconnector/Connector.cpp \
    factorycontroller/erpconnector/TaskProxy.cpp \
    factorycontroller/factory/cnc/Tool.cpp \
    factorycontroller/factory/cnc/MashineCenterInterface.cpp \
    factorycontroller/factory/cnc/_group_cnc.cpp \
    factorycontroller/factory/cnc/ChangeToolOperation.cpp \
    factorycontroller/factory/cnc/ToolSet.cpp \
    factorycontroller/factory/cnc/edm/RepairToolOperation.cpp \
    factorycontroller/factory/cnc/proc/CNCExecutor.cpp \
    factorycontroller/factory/cnc/proc/_group_proc.cpp \
    factorycontroller/factory/cnc/toolpath/_group_toolpath.cpp \
    factorycontroller/factory/cnc/wood/UnfixPartOperation.cpp \
    factorycontroller/factory/cnc/wood/FixPartOperation.cpp \
    factorycontroller/factory/cnc/wood/_group_wood.cpp \
    factorycontroller/factory/handlerobot/HandleRobotExecutor.cpp \
    factorycontroller/factory/handlerobot/_group_handlerobot.cpp \
    factorycontroller/factory/handlerobot/MovePartOperation.cpp \
    factorycontroller/factory/manufacturing/FactoryLoader.cpp \
    factorycontroller/factory/manufacturing/Factory.cpp \
    factorycontroller/factory/manufacturing/_group_manufacturing.cpp \
    factorycontroller/factory/manufacturing/proc/FactoryPureProgramLoader.cpp \
    factorycontroller/factory/manufacturing/proc/_group_proc.cpp \
    factorycontroller/factory/printer3d/Printer3DExecutor.cpp \
    factorycontroller/factory/printer3d/_group_printer3d.cpp \
    factorycontroller/factory/printer3d/Printer3DOperation.cpp \
    factorycontroller/factory/warehouse/StoragePalletPlace.cpp \
    factorycontroller/factory/warehouse/StoragePallet.cpp \
    factorycontroller/factory/warehouse/StorageManager.cpp \
    factorycontroller/factory/warehouse/_group_warehouse.cpp \
    factorycontroller/hardware/_group_hardware.cpp \
    factorycontroller/hardware/HardwareDevice.cpp \
    factorycontroller/hardware/edm/EDMPowerSource.cpp \
    factorycontroller/hardware/edm/_group_edm.cpp \
    factorycontroller/hardware/edm/EDMWorkMode.cpp \
    factorycontroller/hardware/mechatronics/MotorProperties.cpp \
    factorycontroller/hardware/mechatronics/Motor.cpp \
    factorycontroller/hardware/mechatronics/_group_mechatronics.cpp \
    factorycontroller/hardware/mechatronics/MotorSettings.cpp \
    factorycontroller/hardware/mechatronics/command/LinearMotion.cpp \
    factorycontroller/hardware/mechatronics/command/CurveMotion.cpp \
    factorycontroller/hardware/mechatronics/command/_group_command.cpp \
    factorycontroller/hardware/mechatronics/command/AccelerationMotion.cpp \
    factorycontroller/hardware/mechatronics/command/StepMotion.cpp \
    factorycontroller/hardware/metallurgy/InductionHeaterSettings.cpp \
    factorycontroller/hardware/metallurgy/InductionHeater.cpp \
    factorycontroller/hardware/metallurgy/_group_metallurgy.cpp \
    factorycontroller/hardware/power/_group_power.cpp \
    factorycontroller/hardware/power/EnergySourceInterface.cpp \
    factorycontroller/hardware/power/EnergySource.cpp \
    factorycontroller/hardware/power/EnergyNetwork.cpp \
    factorycontroller/hardware/power/EnergyAccumulator.cpp \
    factorycontroller/hardware/power/PowerBus.cpp \
    factorycontroller/hardware/welding/WeldingPowerSourceMode.cpp \
    factorycontroller/hardware/welding/WeldingPowerSource.cpp \
    factorycontroller/hardware/welding/_group_welding.cpp \
    factorycontroller/hardware/welding/WeldingPowerSourceSettings.cpp \
    factorycontroller/network/NetworkDevice.cpp \
    factorycontroller/network/NetworkController.cpp \
    factorycontroller/network/_group_network.cpp \
    factorycontroller/network/DeviceCommand.cpp \
    factorycontroller/network/ConfigurationLoader.cpp \
    factorycontroller/network/NetworkClock.cpp \
    factorycontroller/network/command/NetworkTimeSynchronization.cpp \
    factorycontroller/network/command/_group_command.cpp \
    factorycontroller/network/modbus/ModbusDevice.cpp \
    factorycontroller/network/modbus/_group_modbus.cpp \
    factorycontroller/network/modbus/ModbusMessagePair.cpp \
    factorycontroller/scheduler/Task.cpp \
    factorycontroller/scheduler/_group_scheduler.cpp \
    factorycontroller/scheduler/Resource.cpp \
    factorycontroller/scheduler/ProjectTemplate.cpp \
    factorycontroller/scheduler/Project.cpp \
    factorycontroller/scheduler/LocalConfiguration.cpp \
    factorycontroller/scheduler/ExecutorInterface.cpp \
    factorycontroller/scheduler/TaskTemplate.cpp \
    factorycontroller/system/_group_system.cpp \
    factorycontroller/system/storage/LocalStorage.cpp \
    factorycontroller/system/storage/LocalResources.cpp \
    factorycontroller/system/storage/_group_storage.cpp \
    factorycontroller/system/util/_group_util.cpp \
    factorycontroller/scheduler/Scheduler.cpp \
    factorycontroller/network/Network.cpp \
    factorycontroller/network/modbus/ModbusNetworkController.cpp \
    factorycontroller/scheduler/TaskLogMessage.cpp \
    factorycontroller/network/modbus/ModbusMessageWrapper.cpp \
    factorycontroller/network/modbus/ModbusDeviceCommand.cpp \
    factorycontroller/system/util/StepCounter.cpp \
    factorycontroller/network/modbus/SerialPortSettings.cpp \
    factorycontroller/network/modbus/ModbusNetworkSettings.cpp \
    factorycontroller/network/command/DeviceStateReport.cpp \
    factorycontroller/factory/manufacturing/proc/FactoryConfigurationFileLoader.cpp \
    factorycontroller/factory/manufacturing/proc/ConfigurationLoaderTagHandler.cpp \
    factorycontroller/factory/manufacturing/proc/DefaultTagHandler.cpp \
    factorycontroller/network/modbus/ModbusSerialRTUNetworkController.cpp \
    factorycontroller/network/modbus/ModbusTCPIPNetworkController.cpp \
    factorycontroller/network/modbus/TCPIPAddressSettings.cpp \
    factorycontroller/hardware/HardwareDeviceProcess.cpp \
    factorycontroller/network/command/scheduled/_group_scheduled.cpp \
    factorycontroller/network/command/scheduled/ScheduledCommandRequest.cpp \
    factorycontroller/network/command/scheduled/ScheduledCommandResult.cpp \
    factorycontroller/network/command/scheduled/ScheduledDeviceCommandQueue.cpp \
    factorycontroller/system/log/_group_log.cpp \
    factorycontroller/hardware/mechatronics/proc/_group_proc.cpp \
    factorycontroller/hardware/mechatronics/proc/StepMotion.cpp \
    factorycontroller/hardware/mechatronics/proc/Motion.cpp \
    factorycontroller/hardware/mechatronics/proc/LinearMotion.cpp \
    factorycontroller/hardware/mechatronics/proc/CurveMotion.cpp \
    factorycontroller/hardware/mechatronics/proc/ConstantSpeedMotion.cpp \
    factorycontroller/hardware/mechatronics/proc/AccelerationMotion.cpp \
    factorycontroller/system/util/Counter.cpp \
    factory-hardware-emulator/EmulatorApplication.cpp \
    factory-hardware-emulator/_group_factory-hardware-emulator.cpp \
    factory-hardware-emulator/device/_group_device.cpp \
    factory-hardware-emulator/device/Device.cpp \
    factory-hardware-emulator/hardware/_group_hardware.cpp \
    factory-hardware-emulator/hardware/HardwareDevice.cpp \
    factory-hardware-emulator/hardware/mechatronics/_group_mechatronics.cpp \
    factory-hardware-emulator/hardware/mechatronics/Motor.cpp \
    factory-hardware-emulator/hardware/mechatronics/MotorSettings.cpp \
    factory-hardware-emulator/hardware/mechatronics/StepMotor.cpp \
    factory-hardware-emulator/network/_group_network.cpp \
    factory-hardware-emulator/network/ModbusNetworkController.cpp \
    factory-hardware-emulator/network/NetworkClock.cpp \
    factory-hardware-emulator/network/scheduled/_group_scheduled.cpp \
    factory-hardware-emulator/network/scheduled/ScheduledCommandRequest.cpp \
    factory-hardware-emulator/network/scheduled/ScheduledCommandResult.cpp \
    factory-hardware-emulator/network/scheduled/ScheduledDeviceCommandQueue.cpp \
    factory-hardware-emulator/system/_group_system.cpp \
    factorycontroller/network/modbus/data/_group_data.cpp \
    factorycontroller/network/modbus/data/ControllerData.cpp \
    factorycontroller/network/modbus/data/InterfaceSettings.cpp \
    factorycontroller/network/modbus/data/ModbusRegistersMapping.cpp \
    factorycontroller/network/modbus/data/SystemLogReport.cpp \
    factorycontroller/hardware/mechatronics/data/_group_data.cpp \
    factorycontroller/hardware/mechatronics/data/StepMotorDriverCalculationConstants.cpp \
    factorycontroller/hardware/mechatronics/data/StepMotorDriverData.cpp \
    factorycontroller/hardware/mechatronics/data/StepMotorDriverDataInput.cpp \
    factorycontroller/hardware/edm/command/_group_command.cpp \
    factorycontroller/hardware/edm/data/_group_data.cpp \
    factorycontroller/hardware/edm/proc/_group_proc.cpp \
    factorycontroller/hardware/metallurgy/command/_group_command.cpp \
    factorycontroller/hardware/metallurgy/data/_group_data.cpp \
    factorycontroller/hardware/metallurgy/proc/_group_proc.cpp \
    factorycontroller/hardware/power/command/_group_command.cpp \
    factorycontroller/hardware/power/data/_group_data.cpp \
    factorycontroller/hardware/power/proc/_group_proc.cpp \
    factorycontroller/hardware/welding/command/_group_command.cpp \
    factorycontroller/hardware/welding/data/_group_data.cpp \
    factorycontroller/hardware/welding/proc/_group_proc.cpp \
    factorycontroller/hardware/mechatronics/command/GetMotionState.cpp \
    factorycontroller/hardware/mechatronics/command/StopMotion.cpp \
    factorycontroller/network/command/DeviceIDReport.cpp \
    factorycontroller/hardware/mechatronics/data/StepMotorModbus.cpp \
    factorycontroller/network/command/ReadAndClearLog.cpp \
    factorycontroller/hardware/mechatronics/command/ToEndPositionMotion.cpp \
    factorycontroller/hardware/welding/command/GetWeldingState.cpp \
    factorycontroller/hardware/welding/command/StartWelding.cpp \
    factorycontroller/hardware/welding/command/StopWelding.cpp \
    factorycontroller/hardware/welding/proc/WeldingProcess.cpp \
    factorycontroller/hardware/welding/data/WeldingModbus.cpp \
    factorycontroller/hardware/welding/data/WeldingDriverData.cpp \
    factorycontroller/hardware/welding/data/WeldingDriverDataInput.cpp \
    factorycontroller/hardware/welding/data/WeldingDriverCalculationConstants.cpp \
    factorycontroller/hardware/edm/command/GetEDMState.cpp \
    factorycontroller/hardware/edm/command/StartEDM.cpp \
    factorycontroller/hardware/edm/command/StopEDM.cpp \
    factorycontroller/hardware/edm/data/EDMDriverCalculationConstants.cpp \
    factorycontroller/hardware/edm/data/EDMDriverData.cpp \
    factorycontroller/hardware/edm/data/EDMDriverDataInput.cpp \
    factorycontroller/hardware/edm/data/EDMModbus.cpp \
    factorycontroller/hardware/edm/proc/EDMProcess.cpp \
    factorycontroller/hardware/metallurgy/command/GetInductorState.cpp \
    factorycontroller/hardware/metallurgy/command/StartHeating.cpp \
    factorycontroller/hardware/metallurgy/command/StopHeating.cpp \
    factorycontroller/hardware/metallurgy/data/InductorDriverCalculationConstants.cpp \
    factorycontroller/hardware/metallurgy/data/InductorDriverData.cpp \
    factorycontroller/hardware/metallurgy/data/InductorDriverDataInput.cpp \
    factorycontroller/hardware/metallurgy/data/InductorModbus.cpp \
    factorycontroller/hardware/metallurgy/proc/InductionMeltingProcess.cpp \
    factorycontroller/hardware/power/command/GetPowerLineState.cpp \
    factorycontroller/hardware/power/command/SetPowerLineSettings.cpp \
    factorycontroller/hardware/power/command/StopPowerLine.cpp \
    factorycontroller/hardware/power/data/PowerLineDriverCalculationConstants.cpp \
    factorycontroller/hardware/power/data/PowerLineDriverData.cpp \
    factorycontroller/hardware/power/data/PowerLineDriverDataInput.cpp \
    factorycontroller/hardware/power/data/PowerLineModbus.cpp \
    factorycontroller/hardware/power/proc/PowerLineProcess.cpp
    

HEADERS += factorycontroller/factorycontroller.h \ 
    factory-hardware-emulator/factory-hardware-emulator.h

