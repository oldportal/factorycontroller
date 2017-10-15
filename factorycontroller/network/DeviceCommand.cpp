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


oldportal::fc::network::DeviceCommand::DeviceCommand()

{//BEGIN_9a4ba54f2d4c69e1e269ae077d234d34
    // set minimum priority
    _priority = 0;
    // clear flags
    _result_success = false;
    _command_completed = false;
}//END_9a4ba54f2d4c69e1e269ae077d234d34

oldportal::fc::network::DeviceCommand::DeviceCommand(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device)

{//BEGIN_e7cb70fbbe48cf2ffaeb6c07649c6601
    assert(device);

    _device = device;
}//END_e7cb70fbbe48cf2ffaeb6c07649c6601

oldportal::fc::network::DeviceCommand::DeviceCommand(std::shared_ptr< oldportal::fc::hardware::HardwareDevice > device, std::shared_ptr< oldportal::fc::hardware::HardwareDeviceProcess > device_process)

{//BEGIN_f9f9249947b243e312ec5b79da2f001a
    assert(device);
    assert(device_process);

    _device = device;
    _device_process = device_process;
}//END_f9f9249947b243e312ec5b79da2f001a



oldportal::fc::network::DeviceCommand::~DeviceCommand()
{//BEGIN_32877179041669eccee5e1d6ed563552

}//END_32877179041669eccee5e1d6ed563552


void oldportal::fc::network::DeviceCommand::clear()
{//BEGIN_713376dd3b1f502c6abb2eb2d96053e2
    // empty pointers
    _device.reset();
    _executor.reset();
    // set minimum priority
    _priority = 0;
    // clear flags
    _result_success = false;
    _command_completed = false;
}//END_713376dd3b1f502c6abb2eb2d96053e2

bool oldportal::fc::network::DeviceCommand::is_command_completed() const
{//BEGIN_4a6cfa8712f3c38808bec8c518e0f74c
    return _command_completed;
}//END_4a6cfa8712f3c38808bec8c518e0f74c

bool oldportal::fc::network::DeviceCommand::is_result_success() const
{//BEGIN_1034bd5939d51ef5c8494ff2b5fffd4e
    return _result_success;
}//END_1034bd5939d51ef5c8494ff2b5fffd4e

void oldportal::fc::network::DeviceCommand::onProcessed()
{//BEGIN_e7f23ec91fe8f785294c8480ad24677c
    // empty
}//END_e7f23ec91fe8f785294c8480ad24677c


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE