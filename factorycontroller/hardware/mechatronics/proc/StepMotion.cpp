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


oldportal::fc::hardware::mechatronics::proc::StepMotion::StepMotion()

{//BEGIN_516f588b66c7ce108bd6c69cdda7ca73

}//END_516f588b66c7ce108bd6c69cdda7ca73


void oldportal::fc::hardware::mechatronics::proc::StepMotion::onProcessed()
{//BEGIN_71164158692f3964e4a3f6198b967191
    // empty
}//END_71164158692f3964e4a3f6198b967191

void oldportal::fc::hardware::mechatronics::proc::StepMotion::start()
{//BEGIN_c4c9496a37517a7ce742c67a058eaefd
    oldportal::fc::hardware::mechatronics::proc::Motion::start();

    LOG4CXX_DEBUG(logger, "Process StepMotion start() call");
}//END_c4c9496a37517a7ce742c67a058eaefd

void oldportal::fc::hardware::mechatronics::proc::StepMotion::step()
{//BEGIN_736dec86a6c5d20723840f0be52c4cf3
    oldportal::fc::hardware::HardwareDeviceProcess::step();

    //TODO: is hardware initialized?
    //TODO: is hardware switched to command mode?
    //TODO: estimate next hardware check
    //TODO: check and correct harware
    //TODO: process process (task) end
}//END_736dec86a6c5d20723840f0be52c4cf3


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
