/*
*    This file is part of FactoryController project.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
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
*    Copyright (C) Dmitry Ognyannikov, 2012-2016
*    dmogn@mail.ru
*/
#ifndef H_b29da838ce905b7d6dc7c0e0fd0f8c43_H
#define H_b29da838ce905b7d6dc7c0e0fd0f8c43_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Manufacturing operation description.
*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class TaskTemplate
{
// constructors:


public:
virtual ~TaskTemplate();

// members:

public:
boost::uuids::uuid _id;
public:
std::u16string _name;
public:
std::vector< std::shared_ptr<TaskTemplate> > _subtasks;


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


#endif // H_b29da838ce905b7d6dc7c0e0fd0f8c43_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_b29da838ce905b7d6dc7c0e0fd0f8c43_INLINES_H
#define H_b29da838ce905b7d6dc7c0e0fd0f8c43_INLINES_H

#endif // H_b29da838ce905b7d6dc7c0e0fd0f8c43_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES