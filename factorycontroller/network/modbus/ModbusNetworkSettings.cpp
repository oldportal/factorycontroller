/*
*    This file is part of FactoryController project.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
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
*    Copyright (C) Dmitry Ognyannikov, 2012-2016
*    dmogn@mail.ru
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::network::modbus::ModbusNetworkSettings::ModbusNetworkSettings()

{//BEGIN_31e83a27a778e7434be11dc010d2e8a0
    // modbus general settings
    _response_timeout_usec = 150000;
    _byte_timeout_usec = 50000;

    // network options
    _network_time_sync_interval_msec = 10000;
    _device_update_state_interval_msec = 30000;
}//END_31e83a27a778e7434be11dc010d2e8a0



oldportal::fc::network::modbus::ModbusNetworkSettings::~ModbusNetworkSettings()
{//BEGIN_7da5f632f1178313548474e504d13d4f

}//END_7da5f632f1178313548474e504d13d4f


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE