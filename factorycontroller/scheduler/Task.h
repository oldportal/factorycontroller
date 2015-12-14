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
#ifndef H_8285c27a5bfd40507cf7ba61f4774fd2_H
#define H_8285c27a5bfd40507cf7ba61f4774fd2_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class Task
{
// constructors:
public:
Task();


public:
virtual ~Task();

// members:

public:
boost::uuids::uuid _id;
public:
boost::uuids::uuid _templateId;
public:
std::chrono::high_resolution_clock::time_point _assigned;
public:
std::chrono::high_resolution_clock::time_point _created;
public:
std::chrono::high_resolution_clock::time_point _finished;
public:
std::chrono::high_resolution_clock::time_point _started;
public:
std::u16string _name;
public:
std::vector< std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > > _device_processes;
public:
std::vector< std::shared_ptr<Task> > _subtasks;


//methods:


//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace scheduler


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_8285c27a5bfd40507cf7ba61f4774fd2_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_8285c27a5bfd40507cf7ba61f4774fd2_INLINES_H
#define H_8285c27a5bfd40507cf7ba61f4774fd2_INLINES_H

#endif // H_8285c27a5bfd40507cf7ba61f4774fd2_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES