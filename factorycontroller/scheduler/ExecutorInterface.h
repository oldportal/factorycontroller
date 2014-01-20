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
#ifndef H_ac53b4ab45b11e2c9488ca056f14b3e4_H
#define H_ac53b4ab45b11e2c9488ca056f14b3e4_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Interface of executor class.
*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class ExecutorInterface
{
// constructors:


// members:


//methods:

public:
virtual void executeTask(std::shared_ptr< oldportal::fc::scheduler::Task > task) = 0;

public:
virtual std::shared_ptr< oldportal::fc::scheduler::Task > getCurrentTask() = 0;

public:
std::shared_ptr< oldportal::fc::scheduler::Resource > getLockedResources();

/**
The function must select preferred and available task from list.
*/
public:
virtual std::shared_ptr< oldportal::fc::scheduler::Task > selectTask(std::vector< std::shared_ptr<oldportal::fc::scheduler::Task> >& tasks) = 0;



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace scheduler


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_ac53b4ab45b11e2c9488ca056f14b3e4_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_ac53b4ab45b11e2c9488ca056f14b3e4_INLINES_H
#define H_ac53b4ab45b11e2c9488ca056f14b3e4_INLINES_H

#endif // H_ac53b4ab45b11e2c9488ca056f14b3e4_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES