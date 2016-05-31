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
#ifndef H_6c10399c2872c18eaa62ada245ae34aa_H
#define H_6c10399c2872c18eaa62ada245ae34aa_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Workflow Engine.

General Projects and Tasks execution manager.

Implement logic for Project execution, Task execution, Resources allocation and locking, priority, rules, troubleshooting processing ("physical exception" handling), state save & restore, state change history logging, etc.

Extraordinal capabilities:
- Physical resource schedule (TODO).
- Energy consumption schedule (TODO).
*/
namespace oldportal 
{
namespace fc 
{
namespace scheduler 
{

class Scheduler
{
// constructors:
public:
Scheduler();


public:
virtual ~Scheduler();

// members:

public:
std::vector< std::shared_ptr<Project> > _activeProjects;
public:
std::vector< std::shared_ptr<Resource> > _resources;
public:
std::vector< std::shared_ptr<Task> > _activeTasks;


//methods:

/**
Update state.
Logic processes step.
*/
public:
virtual void step();



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


#endif // H_6c10399c2872c18eaa62ada245ae34aa_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_6c10399c2872c18eaa62ada245ae34aa_INLINES_H
#define H_6c10399c2872c18eaa62ada245ae34aa_INLINES_H

#endif // H_6c10399c2872c18eaa62ada245ae34aa_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES