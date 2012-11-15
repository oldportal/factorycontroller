#-------------------------------------------------
#
# Project created by QtCreator 2012-11-13T23:49:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = factorycontroller
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    factorycontroller/factorycontroller.cpp \
    factorycontroller/connector/ConfigurationProxy.cpp \
    factorycontroller/connector/TaskProxy.cpp \
    factorycontroller/connector/StateProxy.cpp \
    factorycontroller/connector/Connector.cpp \
    factorycontroller/connector/ConfigurationProxy.cpp \
    factorycontroller/executor/Task.cpp \
    factorycontroller/executor/Resource.cpp \
    factorycontroller/executor/LocalConfiguration.cpp \
    factorycontroller/executor/ExecutorInterface.cpp \
    factorycontroller/executor/ExecutorApplication.cpp \
    factorycontroller/executor/Executor.cpp \
    factorycontroller/executor/ConfigurationLoader.cpp \
    factorycontroller/executor/Configuration.cpp \
    factorycontroller/network/NetworkDevice.cpp \
    factorycontroller/network/NetworkController.cpp \
    factorycontroller/network/Network.cpp \
    factorycontroller/network/DeviceCommand.cpp \
    factorycontroller/network/ConfigurationLoader.cpp \
    factorycontroller/network/modbus/Modbus.cpp \
    factorycontroller/storage/Storage.cpp \
    factorycontroller/storage/LocalStorage.cpp \
    factorycontroller/storage/LocalResources.cpp \
    factorycontroller/util/Util.cpp \
    factorycontroller/hardware/HardwareDevice.cpp \
    factorycontroller/hardware/Hardware.cpp \
    factorycontroller/hardware/mechatronics/MotorSettings.cpp \
    factorycontroller/hardware/mechatronics/MotorProperties.cpp \
    factorycontroller/hardware/mechatronics/Motor.cpp \
    factorycontroller/hardware/mechatronics/Mechatronics.cpp \
    factorycontroller/network/modbus/ModbusMessagePair.cpp \
    factorycontroller/network/modbus/ModbusDevice.cpp \
    factorycontroller/network/modbus/Modbus.cpp

HEADERS += \
    factorycontroller/factorycontroller.h
