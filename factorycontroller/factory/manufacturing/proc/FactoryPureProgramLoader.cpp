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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE
#include <QtSerialPort/QSerialPortInfo>
//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::FactoryPureProgramLoader()
    :   oldportal::fc::factory::manufacturing::FactoryLoader()
{//BEGIN_c037b730f87c52811d3fd00dd6c2693f

}//END_c037b730f87c52811d3fd00dd6c2693f



oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::~FactoryPureProgramLoader()
{//BEGIN_1f0482e3d3ea6c7bd98d13887ab3eeeb

}//END_1f0482e3d3ea6c7bd98d13887ab3eeeb


std::shared_ptr< oldportal::fc::network::NetworkController > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getNetworkController()
{//BEGIN_da6b61af649cc75b8183359d2f5c8233
    return _network_controller;
}//END_da6b61af649cc75b8183359d2f5c8233

std::shared_ptr< oldportal::fc::scheduler::Scheduler > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getScheduler()
{//BEGIN_4b75b4b3ddcdee4f1789bedef5c37859
    return _scheduler;
}//END_4b75b4b3ddcdee4f1789bedef5c37859

std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getStorageManager()
{//BEGIN_5cb2dba24094466df65e1a9f1d8bf118
    return _storage_manager;
}//END_5cb2dba24094466df65e1a9f1d8bf118

void oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::init()
{//BEGIN_5110e6763784e4dbb95a3c8e4ca572d3
    // init members:

    // find port:
    /*QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    if (ports.size() > 0)
    {
        QSerialPortInfo info = ports.at(0);
        QSharedPointer< oldportal::fc::network::Network > network(new oldportal::fc::network::Network());
        network->_id = 1;
        network->_name = "default network";
        network->_serialPortPath = info.portName();
        _network_controller = QSharedPointer< oldportal::fc::network::NetworkController >(new oldportal::fc::network::modbus::ModbusNetworkController(network));

        QSharedPointer<oldportal::fc::network::modbus::ModbusDevice> networkDevice(new oldportal::fc::network::modbus::ModbusDevice());
        networkDevice->_id = 4;
        networkDevice->_description = "test device";
        networkDevice->_address = 119;
        network->_devices.append(networkDevice);

        // start controller thread
        _network_controller->thread()->start(QThread::TimeCriticalPriority);
    }
    else */
    {
        //TODO: report error
        _network_controller = std::make_shared< oldportal::fc::network::NetworkController >();
    }

    _scheduler = std::make_shared< oldportal::fc::scheduler::Scheduler >();
    _storage_manager = std::make_shared< oldportal::fc::factory::warehouse::StorageManager >();
}//END_5110e6763784e4dbb95a3c8e4ca572d3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE