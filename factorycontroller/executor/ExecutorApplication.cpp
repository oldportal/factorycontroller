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


oldportal::fc::executor::ExecutorApplication* oldportal::fc::executor::ExecutorApplication::_executorApplication;


oldportal::fc::executor::ExecutorApplication::ExecutorApplication()

{//BEGIN_184bd12b122db374cac8b7195c4e72b7

}//END_184bd12b122db374cac8b7195c4e72b7


QSharedPointer< oldportal::fc::executor::Configuration > oldportal::fc::executor::ExecutorApplication::getConfiguration()
{//BEGIN_44dafaa3733323a5641ab544f58df452
    QSharedPointer<oldportal::fc::executor::Configuration> ret;
    //TODO: getConfiguration()
    return ret;
}//END_44dafaa3733323a5641ab544f58df452

QSharedPointer< oldportal::fc::connector::Connector > oldportal::fc::executor::ExecutorApplication::getConnector()
{//BEGIN_bd54e9df3aafb5e03f84d307df5a5ea2
    QSharedPointer<oldportal::fc::connector::Connector> ret;
    //TODO: getConnector()
    return ret;
}//END_bd54e9df3aafb5e03f84d307df5a5ea2

oldportal::fc::executor::ExecutorApplication* oldportal::fc::executor::ExecutorApplication::getExecutorApplication()
{//BEGIN_2ebf3b21c68f249bf61280c788675dc2
    ExecutorApplication *ret = 0;
    //TODO: getExecutorApplication()
    return ret;
}//END_2ebf3b21c68f249bf61280c788675dc2

QSharedPointer< oldportal::fc::network::NetworkController > oldportal::fc::executor::ExecutorApplication::getNetworkController()
{//BEGIN_c16952d5adbd7323df252c8337cd30bf
    QSharedPointer<oldportal::fc::network::NetworkController> ret;
    //TODO: getNetworkCotroller()
    return ret;
}//END_c16952d5adbd7323df252c8337cd30bf

void oldportal::fc::executor::ExecutorApplication::run()
{//BEGIN_f0f36d61f6dc3813fd7f28ed4bf4c597

}//END_f0f36d61f6dc3813fd7f28ed4bf4c597

void oldportal::fc::executor::ExecutorApplication::setExecutorApplication(oldportal::fc::executor::ExecutorApplication* executorApplication)
{//BEGIN_4d3230bb4a3eeb39f36d9a264f4e646a
    //TODO: setExecutorApplication()
}//END_4d3230bb4a3eeb39f36d9a264f4e646a


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE