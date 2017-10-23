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
#ifndef H_173716840f37fdc672027c3172b1071d_H
#define H_173716840f37fdc672027c3172b1071d_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Resource which is avaliable for executor to process task.
*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class Resource
{
// constructors:
public:
Resource();


public:
virtual ~Resource();

// members:

public:
bool _isLocked;
public:
boost::uuids::uuid _id;
public:
boost::uuids::uuid _lockedForTask;
public:
std::string _description;
public:
std::string _name;
public:
std::weak_ptr< oldportal::fc::scheduler::ExecutorInterface > _lockedBy;


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


#endif // H_173716840f37fdc672027c3172b1071d_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_173716840f37fdc672027c3172b1071d_INLINES_H
#define H_173716840f37fdc672027c3172b1071d_INLINES_H

#endif // H_173716840f37fdc672027c3172b1071d_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES