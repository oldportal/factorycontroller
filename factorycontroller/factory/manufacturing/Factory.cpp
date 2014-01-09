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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::factory::manufacturing::Factory::Factory(oldportal::fc::factory::manufacturing::FactoryLoader* loader)

{//BEGIN_0af1b742578141e3955f1e87dc8b67fd
    loader->init();

    // get Factory members
    _network_controller = loader->getNetworkController();
    _network_controller->setParent(this);
    _scheduler = loader->getScheduler();
    _scheduler->setParent(this);
    _storage_manager = loader->getStorageManager();
    _storage_manager->setParent(this);
}//END_0af1b742578141e3955f1e87dc8b67fd



oldportal::fc::factory::manufacturing::Factory::~Factory()
{//BEGIN_506a49cbc48747ee89440ccc4e8cea86

}//END_506a49cbc48747ee89440ccc4e8cea86


QSharedPointer< oldportal::fc::network::NetworkController > oldportal::fc::factory::manufacturing::Factory::getNetworkController()
{//BEGIN_179de6362c47a40e33c6288e6377995c
    return _network_controller;
}//END_179de6362c47a40e33c6288e6377995c

QSharedPointer< oldportal::fc::scheduler::Scheduler > oldportal::fc::factory::manufacturing::Factory::getScheduler()
{//BEGIN_84acbfb64dde43ce2689549162ba5b53
    return _scheduler;
}//END_84acbfb64dde43ce2689549162ba5b53

QSharedPointer< oldportal::fc::factory::warehouse::StorageManager > oldportal::fc::factory::manufacturing::Factory::getStorageManager()
{//BEGIN_0a256b3ec66070b7dae5847fce12b292
    return _storage_manager;
}//END_0a256b3ec66070b7dae5847fce12b292

void oldportal::fc::factory::manufacturing::Factory::run()
{//BEGIN_a4ad6d027289a8b7eff52dd5cd9626b6

}//END_a4ad6d027289a8b7eff52dd5cd9626b6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE