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


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::hardware::metallurgy::proc::InductionMeltingProcess::InductionMeltingProcess()

{//BEGIN_bb3d100e44f113d4d23b5e25561e6f34

}//END_bb3d100e44f113d4d23b5e25561e6f34



oldportal::fc::hardware::metallurgy::proc::InductionMeltingProcess::~InductionMeltingProcess()
{//BEGIN_5328fbe3cfe465e6ea6bdaf1badfc85e

}//END_5328fbe3cfe465e6ea6bdaf1badfc85e


void oldportal::fc::hardware::metallurgy::proc::InductionMeltingProcess::forceStop()
{//BEGIN_997bbf495d1ccc46ddbadbf4ea94a5aa
    // stop any mechanical motion on devices
    for (uint32_t i=0; i<_hardware_devices.size(); i++)
    {
        assert(!_hardware_devices[i].expired() && "unvalid pointer to device");
        auto device = _hardware_devices[i].lock();
        // stop device
        std::shared_ptr<oldportal::fc::hardware::HardwareDeviceProcess> process = shared_from_this();
        auto command = std::make_shared<oldportal::fc::hardware::welding::command::StopWelding>(device, process);
        device->_network.lock()->_controller.lock()->pushCommand(command);
    }
    // the process is canceled by software call
    _process_state = PROCESS_STATE::CANCELED;
}//END_997bbf495d1ccc46ddbadbf4ea94a5aa

void oldportal::fc::hardware::metallurgy::proc::InductionMeltingProcess::onProcessed()
{//BEGIN_abbf30e5fbcc1d40fd6a3a3174be5926
    // empty
}//END_abbf30e5fbcc1d40fd6a3a3174be5926

void oldportal::fc::hardware::metallurgy::proc::InductionMeltingProcess::start()
{//BEGIN_4e0e7aeec2130592188a222fec6d62e5
    oldportal::fc::hardware::HardwareDeviceProcess::start();

    LOG4CXX_DEBUG(logger, "Process Welding start() call");
}//END_4e0e7aeec2130592188a222fec6d62e5


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE