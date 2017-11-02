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
#ifndef H_8b9eeb611af1c791c3eb8c870239dd67_H
#define H_8b9eeb611af1c791c3eb8c870239dd67_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Global refistry of available plugins.
*/
namespace oldportal 
{
namespace fc 
{
namespace system 
{
namespace plugin 
{

class PluginRegistry
{
// constructors:


// members:


//methods:

/**
Add plugin.
*/
public:
void add(std::shared_ptr< oldportal::fc::system::plugin::Plugin > plugin);

/**
Is class supported check.
*/
public:
bool is_class_supported(std::string class_name);

public:
std::shared_ptr< oldportal::fc::system::serialization::Serializable > load_class(std::string class_name);

/**
Remove plugin.
*/
public:
void remove(std::shared_ptr< oldportal::fc::system::plugin::Plugin > plugin);



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace system
}// namespace plugin


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_8b9eeb611af1c791c3eb8c870239dd67_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_8b9eeb611af1c791c3eb8c870239dd67_INLINES_H
#define H_8b9eeb611af1c791c3eb8c870239dd67_INLINES_H

#endif // H_8b9eeb611af1c791c3eb8c870239dd67_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES