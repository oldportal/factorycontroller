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
#ifndef H_b74d03e795e3f5a9eb7ec4780b09c2eb_H
#define H_b74d03e795e3f5a9eb7ec4780b09c2eb_H



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
namespace mechatronics 
{
namespace proc 
{

class Motion
:  public virtual oldportal::fc::hardware::HardwareDeviceProcess
{
// constructors:
public:
Motion();


public:
virtual ~Motion();

// members:

public:
static const char* const  _CLASSNAME_FULL;


//methods:

/**
Emergency/safety stop process execution on the hardware,
*/
public:
virtual void forceStop();

/**
Called after task processed. For handle device parking, switch to sleep mode, etc.
*/
protected:
virtual void onProcessed();

/**
Start process. Initialize hardware and set start parameters.
*/
public:
virtual void start();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION

//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware
}// namespace mechatronics
}// namespace proc


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_b74d03e795e3f5a9eb7ec4780b09c2eb_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_b74d03e795e3f5a9eb7ec4780b09c2eb_INLINES_H
#define H_b74d03e795e3f5a9eb7ec4780b09c2eb_INLINES_H

#endif // H_b74d03e795e3f5a9eb7ec4780b09c2eb_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES