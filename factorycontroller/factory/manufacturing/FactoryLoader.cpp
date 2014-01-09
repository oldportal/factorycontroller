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


oldportal::fc::factory::manufacturing::FactoryLoader::FactoryLoader()

{//BEGIN_16f187066a23428c655a30fd116d170c

}//END_16f187066a23428c655a30fd116d170c



oldportal::fc::factory::manufacturing::FactoryLoader::~FactoryLoader()
{//BEGIN_cb83b8b73db87af298a2208ece486b78

}//END_cb83b8b73db87af298a2208ece486b78


QSharedPointer< oldportal::fc::network::NetworkController > oldportal::fc::factory::manufacturing::FactoryLoader::getNetworkController()
{//BEGIN_cd2f45bcd30e024c9b559fef514b9ed7
    QSharedPointer<oldportal::fc::network::NetworkController> ret;

    return ret;
}//END_cd2f45bcd30e024c9b559fef514b9ed7

QSharedPointer< oldportal::fc::scheduler::Scheduler > oldportal::fc::factory::manufacturing::FactoryLoader::getScheduler()
{//BEGIN_c1af0a30f2cdcb800ae61ef7078516e3
    QSharedPointer<oldportal::fc::scheduler::Scheduler> ret;

    return ret;
}//END_c1af0a30f2cdcb800ae61ef7078516e3

QSharedPointer< oldportal::fc::factory::warehouse::StorageManager > oldportal::fc::factory::manufacturing::FactoryLoader::getStorageManager()
{//BEGIN_0f587d81b1b7649975deacd2cda84610
    QSharedPointer<oldportal::fc::factory::warehouse::StorageManager> ret;

    return ret;
}//END_0f587d81b1b7649975deacd2cda84610

void oldportal::fc::factory::manufacturing::FactoryLoader::init()
{//BEGIN_3783c3414e6c5523d53e6fb4dc24ad15

}//END_3783c3414e6c5523d53e6fb4dc24ad15


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE