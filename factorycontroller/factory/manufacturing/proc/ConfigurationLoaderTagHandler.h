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
#ifndef H_5fa4f3e1d51742ab66420451f9b3230d_H
#define H_5fa4f3e1d51742ab66420451f9b3230d_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
TagHandler can process set of input configuration file tags (keys) and load parsed objects to ConfigurationLoader model.
*/
namespace oldportal 
{
namespace fc 
{
namespace factory 
{
namespace manufacturing 
{
namespace proc 
{

class ConfigurationLoaderTagHandler
{
// constructors:
public:
ConfigurationLoaderTagHandler();


public:
virtual ~ConfigurationLoaderTagHandler();

// members:


//methods:

/**
Get list of configuration tags (keys), which can be processed with this Handler.
*/
public:
virtual std::vector< std::string > getTagList() = 0;

public:
virtual void processElement(std::string tag_name, boost::property_tree::ptree& root_ptree, boost::property_tree::ptree& element_ptree, oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader* loader, void* parentModelObject) = 0;



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace factory
}// namespace manufacturing
}// namespace proc


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_5fa4f3e1d51742ab66420451f9b3230d_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_5fa4f3e1d51742ab66420451f9b3230d_INLINES_H
#define H_5fa4f3e1d51742ab66420451f9b3230d_INLINES_H

#endif // H_5fa4f3e1d51742ab66420451f9b3230d_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES