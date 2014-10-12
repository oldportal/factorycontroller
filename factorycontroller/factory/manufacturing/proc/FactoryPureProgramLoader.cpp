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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::FactoryPureProgramLoader()
    :   oldportal::fc::factory::manufacturing::FactoryLoader()
{//BEGIN_e0a5d0495f08716c756e3e993ca14893

}//END_e0a5d0495f08716c756e3e993ca14893



oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::~FactoryPureProgramLoader()
{//BEGIN_7a0e75b80e41e26bb0eaf042f0d9d94b

}//END_7a0e75b80e41e26bb0eaf042f0d9d94b


std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getExecutors()
{//BEGIN_d44041889adcd6e97e834f3d5ef839aa
    return _executors;
}//END_d44041889adcd6e97e834f3d5ef839aa

std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getNetworkControllers()
{//BEGIN_33fc9b3c9a65d8482e0a49fff8af996f
    return _network_controllers;
}//END_33fc9b3c9a65d8482e0a49fff8af996f

std::vector< std::shared_ptr<oldportal::fc::network::Network> > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getNetworks()
{//BEGIN_43e79750f9c2f923afbc63d883c85398
    return _networks;
}//END_43e79750f9c2f923afbc63d883c85398

std::shared_ptr< oldportal::fc::scheduler::Scheduler > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getScheduler()
{//BEGIN_7021c2722148304bc5672bb6c7f6df42
    return _scheduler;
}//END_7021c2722148304bc5672bb6c7f6df42

std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::getStorageManager()
{//BEGIN_2aa240c8065342c9824468454a0e68e6
    return _storage_manager;
}//END_2aa240c8065342c9824468454a0e68e6

void oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader::init()
{//BEGIN_5b0594ae28e0d5ff4cbae77b275fda91
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
        _network_controller = QSharedPointer< oldportal::fc::network::NetworkController >(new oldportal::fc::network::modbus::ModbusSerialRTUNetworkController(network));

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
        //_network_controllers = std::make_shared< oldportal::fc::network::NetworkController >();
    }

    _scheduler = std::make_shared< oldportal::fc::scheduler::Scheduler >();
    _storage_manager = std::make_shared< oldportal::fc::factory::warehouse::StorageManager >();
}//END_5b0594ae28e0d5ff4cbae77b275fda91


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE