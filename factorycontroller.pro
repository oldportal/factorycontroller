#-------------------------------------------------
#
# Project created by QtCreator 2012-11-13T23:49:24
#
#-------------------------------------------------

#QT       += core
#QT       += serialport

QT       -= gui

TARGET = factorycontroller
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += boost

LIBS	+= -lboost_system

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

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
    factorycontroller/hardware/mechatronics/command/ConstantSpeedMotion.cpp \
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
    factorycontroller/network/command/StateReport.cpp \
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
    factorycontroller/network/NetworkErrorStatistics.cpp

HEADERS += \
    factorycontroller/factorycontroller.h 
