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


oldportal::fc::connector::TaskProxy::TaskProxy(QSharedPointer< oldportal::fc::connector::Connector > connector)

{//BEGIN_0ea35633f1ee3014d4c2fba31c8fd9c4
_connector = connector;
}//END_0ea35633f1ee3014d4c2fba31c8fd9c4


void oldportal::fc::connector::TaskProxy::addTaskLogMesage(__int64 taskId)
{//BEGIN_fb2b7603cda0b2676ee81bc26a3f1886
    //TODO: addTaskLogMesage()
}//END_fb2b7603cda0b2676ee81bc26a3f1886

bool oldportal::fc::connector::TaskProxy::allocateTask(__int64 taskId)
{//BEGIN_cc669e1aab8f99eebd68743a607223dd
    bool ret = false;
    //TODO: allocateTask()
    return ret;
}//END_cc669e1aab8f99eebd68743a607223dd

QVector<  QSharedPointer<oldportal::fc::executor::Task> > oldportal::fc::connector::TaskProxy::getTasksForExecutor()
{//BEGIN_c9f573532340bbf20795f8a55ae6ce76
    QVector< QSharedPointer<oldportal::fc::executor::Task> > ret;
    //TODO: getAvailableTasks()
    return ret;
}//END_c9f573532340bbf20795f8a55ae6ce76

bool oldportal::fc::connector::TaskProxy::lockResources(__int64 taskId, QVector< oldportal::fc::executor::Resource >& resources)
{//BEGIN_8ce23fc915340ca5233fc11c3345147a
    //TODO: lockResources()
    return false;
}//END_8ce23fc915340ca5233fc11c3345147a

void oldportal::fc::connector::TaskProxy::reportTaskProgress(__int64 taskId)
{//BEGIN_b4c002bbba02f25763ad512f70ac566c
    //TODO: reportTaskProgress()
}//END_b4c002bbba02f25763ad512f70ac566c

void oldportal::fc::connector::TaskProxy::setTaskCompleted(__int64 taskId)
{//BEGIN_0dd7bcc199ed2d4d2cc16493f96b50d4
    //TODO: setTaskCompleted()
}//END_0dd7bcc199ed2d4d2cc16493f96b50d4

void oldportal::fc::connector::TaskProxy::taskExecutionException(__int64 taskId)
{//BEGIN_1b425a0a38c630d3b4016df68f77e323
    //TODO: taskExecutionException()
}//END_1b425a0a38c630d3b4016df68f77e323

void oldportal::fc::connector::TaskProxy::unlockResources(__int64 taskId, QVector< oldportal::fc::executor::Resource >& resources)
{//BEGIN_ac09fec621b41f541eb692290208758c
    //TODO: lockResources()
}//END_ac09fec621b41f541eb692290208758c


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE