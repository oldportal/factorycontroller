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


const char* const  oldportal::fc::hardware::mechatronics::proc::ConstantSpeedMotion::_CLASSNAME_FULL = "oldportal::fc::hardware::mechatronics::proc::ConstantSpeedMotion";


oldportal::fc::hardware::mechatronics::proc::ConstantSpeedMotion::ConstantSpeedMotion()

{//BEGIN_150a27487f29df9b45aae3c693753a51

}//END_150a27487f29df9b45aae3c693753a51


void oldportal::fc::hardware::mechatronics::proc::ConstantSpeedMotion::onProcessed()
{//BEGIN_aeda3764f871dabde4fea692226b31de
    // empty
}//END_aeda3764f871dabde4fea692226b31de

void oldportal::fc::hardware::mechatronics::proc::ConstantSpeedMotion::start()
{//BEGIN_17a13889d94b63d574b39913db6e8be9
    oldportal::fc::hardware::mechatronics::proc::Motion::start();

    LOG4CXX_DEBUG(logger, "Process ConstantSpeedMotion start() call");
}//END_17a13889d94b63d574b39913db6e8be9

void oldportal::fc::hardware::mechatronics::proc::ConstantSpeedMotion::step()
{//BEGIN_61ef43fca923b1d48c5463a7909cdbf6
    oldportal::fc::hardware::HardwareDeviceProcess::step();

    //TODO: step()
}//END_61ef43fca923b1d48c5463a7909cdbf6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE