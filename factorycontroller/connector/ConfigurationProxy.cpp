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


#include "..\factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::connector::ConfigurationProxy::ConfigurationProxy(QSharedPointer< oldportal::fc::connector::Connector > connector)

{//BEGIN_7fdcb6e1638962cb356b96a08e27b009
_connector = connector;
}//END_7fdcb6e1638962cb356b96a08e27b009

oldportal::fc::connector::ConfigurationProxy::ConfigurationProxy(QSharedPointer< oldportal::fc::connector::Connector > connector, QSharedPointer< oldportal::fc::executor::ConfigurationLoader > configurationLoader)

{//BEGIN_7497c9d6afe07f5f340a797323ad89d9
_connector = connector;
_configurationLoader = configurationLoader;
}//END_7497c9d6afe07f5f340a797323ad89d9


QSharedPointer< oldportal::fc::executor::Configuration > oldportal::fc::connector::ConfigurationProxy::getExecutorConfiguration()
{//BEGIN_eeddd0e3e4a0753d6dc262df50c5c0c9
    QSharedPointer<oldportal::fc::executor::Configuration> ret;
    //TODO: getExecutorConfiguration()
    return ret;
}//END_eeddd0e3e4a0753d6dc262df50c5c0c9


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE