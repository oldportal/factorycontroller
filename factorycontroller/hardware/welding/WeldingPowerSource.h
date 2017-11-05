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
#ifndef H_9e49d1225081d1bc954af52c447b5eaf_H
#define H_9e49d1225081d1bc954af52c447b5eaf_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{
namespace welding 
{

class WeldingPowerSource
:  public virtual oldportal::fc::hardware::HardwareDevice
{
// constructors:
public:
WeldingPowerSource();


public:
virtual ~WeldingPowerSource();

// members:

public:
oldportal::fc::hardware::welding::WeldingPowerSourceMode _mode;
public:
oldportal::fc::hardware::welding::WeldingPowerSourceSettings _settings;
/**
Modbus data (registers) structures.
*/
public:
oldportal::fc::hardware::welding::data::WeldingModbus _modbus_data;
public:
static const char* const  _CLASSNAME_FULL;


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
}// namespace hardware
}// namespace welding


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_9e49d1225081d1bc954af52c447b5eaf_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_9e49d1225081d1bc954af52c447b5eaf_INLINES_H
#define H_9e49d1225081d1bc954af52c447b5eaf_INLINES_H

#endif // H_9e49d1225081d1bc954af52c447b5eaf_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES