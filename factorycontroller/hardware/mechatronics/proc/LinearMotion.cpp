/*
*    This file is part of factorycontroller.
*    
*    factorycontroller is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
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
*    Copyright (C) Dmitry Ognyannikov, 2012-2014
*/


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::hardware::mechatronics::proc::LinearMotion::LinearMotion()

{//BEGIN_88c48fa45a4810f1275e31c51d5281d3

}//END_88c48fa45a4810f1275e31c51d5281d3


void oldportal::fc::hardware::mechatronics::proc::LinearMotion::onProcessed()
{//BEGIN_97e29e5b2637a120da1ee1492336e9c4
    // empty
}//END_97e29e5b2637a120da1ee1492336e9c4

void oldportal::fc::hardware::mechatronics::proc::LinearMotion::start()
{//BEGIN_84d3ab554b9e52aefa0b7f598c73162f
    oldportal::fc::hardware::mechatronics::proc::Motion::start();
}//END_84d3ab554b9e52aefa0b7f598c73162f

void oldportal::fc::hardware::mechatronics::proc::LinearMotion::step()
{//BEGIN_9f3fb12afa693ca925a2a5dab2ad5102
    oldportal::fc::hardware::HardwareDeviceProcess::step();

    // is hardware initialized?
    if (!is_hardware_initialized())
    {
        //TODO: initialize hardware
    }

    switch (_hardware_state)
    {
        case HARDWARE_STATE::START:
            break;
        case HARDWARE_STATE::INITIALIZATION:
            break;
        case HARDWARE_STATE::INITIALIZED:
            break;
        case HARDWARE_STATE::PROCESS:
            break;
        case HARDWARE_STATE::PROCESSED:
            break;
        case HARDWARE_STATE::CANCELED:
            break;
        case HARDWARE_STATE::FAILURED:
            break;
        default:
        ;
    }


    //TODO: is hardware switched to command mode?
    //TODO: estimate next hardware check
    //TODO: check and correct harware
    //TODO: process process (task) end
}//END_9f3fb12afa693ca925a2a5dab2ad5102


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
