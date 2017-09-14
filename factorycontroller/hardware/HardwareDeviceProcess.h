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
#ifndef H_d767bf182dff08c9ac2ec9a10b9c3297_H
#define H_d767bf182dff08c9ac2ec9a10b9c3297_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**
Specific hardware mode & process controller class.

For example: Linear motion for motor, motion with acceleration, break process, heating or constant temperature for heater, etc.

Could exist different modes with different process controller for each hardware device.
*/
namespace oldportal 
{
namespace fc 
{
namespace hardware 
{

class HardwareDeviceProcess
{
// constructors:
public:
HardwareDeviceProcess();


public:
virtual ~HardwareDeviceProcess();

// members:

protected:
bool _hardware_initialized;
protected:
std::vector< std::weak_ptr< oldportal::fc::hardware::HardwareDevice > > _hardware_devices;
/**
Parent scheduler Task.

Empty if the process is not associated with a scheduler task
(manual control, for example).
*/
public:
std::weak_ptr< oldportal::fc::scheduler::Task > _parent_task;


//methods:

/**
Attach process to hardware device.

The device can be attached only once.
*/
public:
virtual void attach_device(std::weak_ptr< oldportal::fc::hardware::HardwareDevice > hardware_device);

/**
Attach process to hardware devices.

Devices can be attached only once.
*/
public:
virtual void attach_devices(std::vector< std::weak_ptr< oldportal::fc::hardware::HardwareDevice > > hardware_devices);

public:
virtual void detach_devices();

/**
Emergency/safety stop process execution on the hardware,
*/
public:
virtual void forceStop() = 0;

public:
std::vector< std::weak_ptr< oldportal::fc::hardware::HardwareDevice > > get_hardware_devices();

public:
bool is_hardware_initialized();

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

/**
Update state.
Logic processes step.
*/
public:
virtual void step();

public:
virtual std::string toString();



//child groups:


//child classes:


//BEGIN_USER_SECTION_INSIDE_CLASS_DECLARATION
public:

/**
 * @brief The PROCESS_STATE enum
 *
 * Phase of the process execution (state machine).
 */
enum PROCESS_STATE {
    START,
    INITIALIZATION,
    INITIALIZED,
    PROCESS,
    PROCESSED,
    CANCELED,
    FAILURED
};

/**
 * @brief _process_state
 *
 * Track process state in hardware or software.
 * If process execution is driven by hardware controller - then this field value should be received from hardware state.
 * If process execution is driven by software - then this field value should be updated by software.
 */
PROCESS_STATE _process_state;
//END_USER_SECTION_INSIDE_CLASS_DECLARATION


};
}// namespace oldportal
}// namespace fc
}// namespace hardware


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_d767bf182dff08c9ac2ec9a10b9c3297_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_d767bf182dff08c9ac2ec9a10b9c3297_INLINES_H
#define H_d767bf182dff08c9ac2ec9a10b9c3297_INLINES_H

#endif // H_d767bf182dff08c9ac2ec9a10b9c3297_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES