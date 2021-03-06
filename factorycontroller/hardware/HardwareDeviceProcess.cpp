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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


const char* const  oldportal::fc::hardware::HardwareDeviceProcess::_CLASSNAME_FULL = "oldportal::fc::hardware::HardwareDeviceProcess";


oldportal::fc::hardware::HardwareDeviceProcess::HardwareDeviceProcess()

{//BEGIN_1a1b39c98ef1e25edf61bdde8f3f5ab1
    _process_state = PROCESS_STATE::START;
    _hardware_initialized = false;
}//END_1a1b39c98ef1e25edf61bdde8f3f5ab1



oldportal::fc::hardware::HardwareDeviceProcess::~HardwareDeviceProcess()
{//BEGIN_db997cad34bff219b67971894976e13d

}//END_db997cad34bff219b67971894976e13d


void oldportal::fc::hardware::HardwareDeviceProcess::attach_device(std::weak_ptr< oldportal::fc::hardware::HardwareDevice > hardware_device)
{//BEGIN_5d0aaab22eaf18469624ac005f003c01
    assert(!hardware_device.expired());

    // check for existing device
    for (int i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired());
        auto device = _hardware_devices[i].lock();
        if (device ==  hardware_device.lock())
        {
            LOG4CXX_WARN(logger, "Attach second instance of hardware_device: " << device->toString());
            return;
        }
    }

    // add device
    _hardware_devices.push_back(hardware_device);
}//END_5d0aaab22eaf18469624ac005f003c01

void oldportal::fc::hardware::HardwareDeviceProcess::attach_devices(std::vector< std::weak_ptr< oldportal::fc::hardware::HardwareDevice > > hardware_devices)
{//BEGIN_a5d31c69a17f8a6416538865683d21fb
    for (int i=0; i<hardware_devices.size(); i++)
    {
        assert(!hardware_devices[i].expired());
        _hardware_devices.push_back(hardware_devices[i]);
    }
}//END_a5d31c69a17f8a6416538865683d21fb

void oldportal::fc::hardware::HardwareDeviceProcess::detach_devices()
{//BEGIN_3040b7242dcdfa439c3538de2c0e23d9
    _hardware_devices.clear();
    _hardware_initialized = false;
}//END_3040b7242dcdfa439c3538de2c0e23d9


std::vector< std::weak_ptr< oldportal::fc::hardware::HardwareDevice > > oldportal::fc::hardware::HardwareDeviceProcess::get_hardware_devices()
{//BEGIN_9adf7ce9fd924a3ef85250510dadd0c8
    return _hardware_devices;
}//END_9adf7ce9fd924a3ef85250510dadd0c8

bool oldportal::fc::hardware::HardwareDeviceProcess::is_hardware_initialized()
{//BEGIN_13229bafc3d4d020224cb19339d5996f
    return _hardware_initialized;
}//END_13229bafc3d4d020224cb19339d5996f

void oldportal::fc::hardware::HardwareDeviceProcess::onProcessed()
{//BEGIN_3838ba901573d18cfb5b15b8e80f6351
    // empty
}//END_3838ba901573d18cfb5b15b8e80f6351

void oldportal::fc::hardware::HardwareDeviceProcess::start()
{//BEGIN_f2153248dc9ac12d3f4a5acb137689d1
    // test device pointers
    for (int i=0; i<_hardware_devices.size(); i++) { assert(!_hardware_devices[i].expired()); }
}//END_f2153248dc9ac12d3f4a5acb137689d1

void oldportal::fc::hardware::HardwareDeviceProcess::step()
{//BEGIN_2a4d38af823396497afce24a0a88f964
    // test device pointers
    for (int i=0; i<_hardware_devices.size(); i++) { assert(!_hardware_devices[i].expired()); }
}//END_2a4d38af823396497afce24a0a88f964

std::string oldportal::fc::hardware::HardwareDeviceProcess::toString()
{//BEGIN_d6b3bb9dc86a5256a42cb3dc363e899f
    return (boost::format("HardwareDeviceProcess [ devices count: %i, state: %s ]") % _hardware_devices.size() % _process_state).str();
}//END_d6b3bb9dc86a5256a42cb3dc363e899f


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE