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
#ifndef H_6070802b2a373d2af0c42fc697692278_H
#define H_6070802b2a373d2af0c42fc697692278_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Manufacturing project description.

BPMN-like operation sequence.
*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class ProjectTemplate
{
// constructors:
public:
ProjectTemplate();


public:
virtual ~ProjectTemplate();

// members:

public:
boost::uuids::uuid _id;
public:
int32_t _version;
public:
static const char* const  _CLASSNAME_FULL;
public:
std::string _description;
public:
std::string _name;
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


#endif // H_6070802b2a373d2af0c42fc697692278_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_6070802b2a373d2af0c42fc697692278_INLINES_H
#define H_6070802b2a373d2af0c42fc697692278_INLINES_H

#endif // H_6070802b2a373d2af0c42fc697692278_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES