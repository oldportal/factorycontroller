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
#ifndef H_e2015fe689d08ff354f0e269d5488a90_H
#define H_e2015fe689d08ff354f0e269d5488a90_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace erpconnector 
{

class TaskProxy
{
// constructors:
protected:
TaskProxy(std::shared_ptr< oldportal::fc::erpconnector::Connector > connector);


// members:

protected:
std::weak_ptr< oldportal::fc::erpconnector::Connector > _connector;


//methods:

public:
virtual void addTaskLogMesage(boost::uuids::uuid taskId);

public:
virtual bool allocateTask(boost::uuids::uuid taskId);

public:
virtual std::vector< std::shared_ptr<oldportal::fc::scheduler::Task> > getTasksForExecutor();

public:
virtual bool lockResources(boost::uuids::uuid taskId, std::vector< oldportal::fc::scheduler::Resource >& resources);

public:
virtual void reportTaskProgress(boost::uuids::uuid taskId);

public:
virtual void setTaskCompleted(boost::uuids::uuid taskId);

public:
virtual void taskExecutionException(boost::uuids::uuid taskId);

public:
virtual void unlockResources(boost::uuids::uuid taskId, std::vector< oldportal::fc::scheduler::Resource >& resources);



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace erpconnector


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_e2015fe689d08ff354f0e269d5488a90_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_e2015fe689d08ff354f0e269d5488a90_INLINES_H
#define H_e2015fe689d08ff354f0e269d5488a90_INLINES_H

#endif // H_e2015fe689d08ff354f0e269d5488a90_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES