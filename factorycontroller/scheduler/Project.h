/*
*    This file is part of FactoryController project.
*    
*    FactoryController is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    FactoryController is distributed in the hope that it will be useful,
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
#ifndef H_486108abcfb6940d0227e72b66d8fa65_H
#define H_486108abcfb6940d0227e72b66d8fa65_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Manufacturing project
*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class Project
{
// constructors:
public:
Project();


public:
virtual ~Project();

// members:

public:
boost::posix_time::ptime _created;
public:
boost::posix_time::ptime _finished;
public:
boost::posix_time::ptime _started;
public:
boost::uuids::uuid _id;
public:
boost::uuids::uuid _templateId;
public:
static const char* const  _CLASSNAME_FULL;
public:
std::vector< std::shared_ptr<Task> > _tasks;


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


#endif // H_486108abcfb6940d0227e72b66d8fa65_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_486108abcfb6940d0227e72b66d8fa65_INLINES_H
#define H_486108abcfb6940d0227e72b66d8fa65_INLINES_H

#endif // H_486108abcfb6940d0227e72b66d8fa65_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES