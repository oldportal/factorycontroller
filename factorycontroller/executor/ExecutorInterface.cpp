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


void oldportal::fc::executor::ExecutorInterface::executeTask(QSharedPointer< oldportal::fc::executor::Task > task)
{//BEGIN_78da14d811f9fe1464cbeed3408ec13e
    //TODO: executeTask()
}//END_78da14d811f9fe1464cbeed3408ec13e

QSharedPointer< oldportal::fc::executor::Task > oldportal::fc::executor::ExecutorInterface::getCurrentTask()
{//BEGIN_6a343962ffad9432333c7960f6a2ec16
    QSharedPointer<oldportal::fc::executor::Task> ret;
    //TODO: getCurrentTask()
    return ret;
}//END_6a343962ffad9432333c7960f6a2ec16

QSharedPointer< oldportal::fc::executor::Resource > oldportal::fc::executor::ExecutorInterface::getLockedResources()
{//BEGIN_f60a964f51d60ae382cfe97cc42532df
    QSharedPointer<oldportal::fc::executor::Resource> ret;
    //TODO: getLockedResources()
    return ret;
}//END_f60a964f51d60ae382cfe97cc42532df

QSharedPointer< oldportal::fc::executor::Task > oldportal::fc::executor::ExecutorInterface::selectTask(std::vector<  QSharedPointer<oldportal::fc::executor::Task> >& tasks)
{//BEGIN_ee25b13195a998845b49887b658ee4c3
    QSharedPointer<oldportal::fc::executor::Task> ret;
    //TODO: selectTask()
    return ret;
}//END_ee25b13195a998845b49887b658ee4c3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE