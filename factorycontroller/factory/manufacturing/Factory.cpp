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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::factory::manufacturing::Factory::Factory(std::shared_ptr< oldportal::fc::factory::manufacturing::FactoryLoader > loader)

{//BEGIN_0af1b742578141e3955f1e87dc8b67fd
    loader->init();

    // get Factory members
    _name = loader->_name;

    _networks = loader->getNetworks();
    _network_controllers = loader->getNetworkControllers();
    _scheduler = loader->getScheduler();
    _storage_manager = loader->getStorageManager();
    _executors = loader->getExecutors();

    // main cycle not run now
    _run_thread_cycle_flag = false;
}//END_0af1b742578141e3955f1e87dc8b67fd



oldportal::fc::factory::manufacturing::Factory::~Factory()
{//BEGIN_506a49cbc48747ee89440ccc4e8cea86
    // stop main cycle
    _run_thread_cycle_flag = false;
}//END_506a49cbc48747ee89440ccc4e8cea86


std::vector< std::shared_ptr<oldportal::fc::scheduler::ExecutorInterface> > oldportal::fc::factory::manufacturing::Factory::getExecutors()
{//BEGIN_179de6362c47a40e33c6288e6377995c
    return _executors;
}//END_179de6362c47a40e33c6288e6377995c

std::vector< std::shared_ptr<oldportal::fc::network::NetworkController> > oldportal::fc::factory::manufacturing::Factory::getNetworkControllers()
{//BEGIN_cf9709af7e9634a7d7ecc8f708f6f2ed
    return _network_controllers;
}//END_cf9709af7e9634a7d7ecc8f708f6f2ed

std::vector< std::shared_ptr<oldportal::fc::network::Network> > oldportal::fc::factory::manufacturing::Factory::getNetworks()
{//BEGIN_76a1bb1eb6971f7be5a65996536540af
    return _networks;
}//END_76a1bb1eb6971f7be5a65996536540af

std::shared_ptr< oldportal::fc::scheduler::Scheduler > oldportal::fc::factory::manufacturing::Factory::getScheduler()
{//BEGIN_84acbfb64dde43ce2689549162ba5b53
    return _scheduler;
}//END_84acbfb64dde43ce2689549162ba5b53

std::shared_ptr< oldportal::fc::factory::warehouse::StorageManager > oldportal::fc::factory::manufacturing::Factory::getStorageManager()
{//BEGIN_0a256b3ec66070b7dae5847fce12b292
    return _storage_manager;
}//END_0a256b3ec66070b7dae5847fce12b292

void oldportal::fc::factory::manufacturing::Factory::run(oldportal::fc::factory::manufacturing::Factory* factory)
{//BEGIN_a4ad6d027289a8b7eff52dd5cd9626b6
    assert(factory);
    oldportal::fc::system::log::log(u8"oldportal::fc::factory::manufacturing::Factory::run() main cycle started");
    while(factory->_run_thread_cycle_flag)
    {
        factory->step();

        // sleep with chrono
        std::this_thread::sleep_for( std::chrono::milliseconds(1) );
    }
}//END_a4ad6d027289a8b7eff52dd5cd9626b6

void oldportal::fc::factory::manufacturing::Factory::start()
{//BEGIN_72e7c33dacb46addbda1cbca090efe91
    // go current thread to main cycle
    _run_thread_cycle_flag = true;
    oldportal::fc::factory::manufacturing::Factory::run(this);
}//END_72e7c33dacb46addbda1cbca090efe91

void oldportal::fc::factory::manufacturing::Factory::startInNewThread()
{//BEGIN_f429e5bc386427f537e83288357ab5e0
    // start new thread with main cycle
    _run_thread_cycle_flag = true;
    _run_thread = std::make_shared<std::thread>(oldportal::fc::factory::manufacturing::Factory::run, this);
}//END_f429e5bc386427f537e83288357ab5e0

void oldportal::fc::factory::manufacturing::Factory::step()
{//BEGIN_771bbcfbbdef24221633f30b5616553e

    for (size_t i=0; i<_network_controllers.size(); i++)
    {
        _network_controllers[i]->step();
    }

    for (size_t i=0; i<_executors.size(); i++)
    {
        _executors[i]->step();
    }

    _storage_manager->step();
    _scheduler->step();

    _step_counter.increment();
}//END_771bbcfbbdef24221633f30b5616553e

void oldportal::fc::factory::manufacturing::Factory::stop()
{//BEGIN_416fa323fc52050b30eba79d16026243
    _run_thread_cycle_flag = false;
}//END_416fa323fc52050b30eba79d16026243


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE