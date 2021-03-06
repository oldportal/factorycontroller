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


const char* const  oldportal::fc::hardware::mechatronics::proc::CurveMotion::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::proc::CurveMotion";


oldportal::fc::hardware::mechatronics::proc::CurveMotion::CurveMotion()

{//BEGIN_182294aeb9f2778d6b09b2ff9c7576c2

}//END_182294aeb9f2778d6b09b2ff9c7576c2


void oldportal::fc::hardware::mechatronics::proc::CurveMotion::onProcessed()
{//BEGIN_dce4295ab48a1df8db85cf8fd1191374
    // empty
}//END_dce4295ab48a1df8db85cf8fd1191374

void oldportal::fc::hardware::mechatronics::proc::CurveMotion::start()
{//BEGIN_3a38be042fe7ee827916d7f7300734a8
    oldportal::fc::hardware::mechatronics::proc::Motion::start();

    LOG4CXX_DEBUG(logger, "Process CurveMotion start() call");
}//END_3a38be042fe7ee827916d7f7300734a8

void oldportal::fc::hardware::mechatronics::proc::CurveMotion::step()
{//BEGIN_dd62f42a8a9b0b0096af2cc7d4b0bdf9
    oldportal::fc::hardware::HardwareDeviceProcess::step();

    //TODO: step()
}//END_dd62f42a8a9b0b0096af2cc7d4b0bdf9


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE