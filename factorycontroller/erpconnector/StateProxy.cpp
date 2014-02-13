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


#include "../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::erpconnector::StateProxy::StateProxy(std::shared_ptr< oldportal::fc::erpconnector::Connector > connector)

{//BEGIN_a9adfe47c216d93d795ca30d29cc833e
_connector = connector;
}//END_a9adfe47c216d93d795ca30d29cc833e


void oldportal::fc::erpconnector::StateProxy::reportExecutorState()
{//BEGIN_003ad6c3b6dff8dc9465f277fa733f15
    //TODO: reportExecutorState()
}//END_003ad6c3b6dff8dc9465f277fa733f15

void oldportal::fc::erpconnector::StateProxy::reportNetworkDeviceState()
{//BEGIN_4f75ece2c258618025ef08129a5d80e0
    //TODO: reportNetworkDeviceState()
}//END_4f75ece2c258618025ef08129a5d80e0


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE