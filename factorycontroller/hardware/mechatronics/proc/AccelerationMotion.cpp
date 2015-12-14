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


oldportal::fc::hardware::mechatronics::proc::AccelerationMotion::AccelerationMotion()

{//BEGIN_6e6c0d0f888b6b2830e2a3980b75b80c

}//END_6e6c0d0f888b6b2830e2a3980b75b80c


void oldportal::fc::hardware::mechatronics::proc::AccelerationMotion::onProcessed()
{//BEGIN_fd01c889eb7651a6f0b8794051972180
    // empty
}//END_fd01c889eb7651a6f0b8794051972180

void oldportal::fc::hardware::mechatronics::proc::AccelerationMotion::start()
{//BEGIN_aa1a6c3e08aa519f6eb7ea62ec98ee7b
    oldportal::fc::hardware::mechatronics::proc::Motion::start();
}//END_aa1a6c3e08aa519f6eb7ea62ec98ee7b

void oldportal::fc::hardware::mechatronics::proc::AccelerationMotion::step()
{//BEGIN_be4448ad9989f0f11a6b30f9a8056136
    // test device pointers
    for (int i=0; i<_hardware_devices.size(); i++) { assert(!_hardware_devices[i].expired()); }

    //TODO: step()
}//END_be4448ad9989f0f11a6b30f9a8056136


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE