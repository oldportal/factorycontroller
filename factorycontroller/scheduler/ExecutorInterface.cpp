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


const char* const  oldportal::fc::scheduler::ExecutorInterface::_CLASSNAME_FULL = "oldportal::fc::scheduler::ExecutorInterface";


oldportal::fc::scheduler::ExecutorInterface::~ExecutorInterface()
{//BEGIN_21a9e663f6e779884a26e7bfb836e4b9

}//END_21a9e663f6e779884a26e7bfb836e4b9


std::shared_ptr< oldportal::fc::scheduler::Resource > oldportal::fc::scheduler::ExecutorInterface::getLockedResources()
{//BEGIN_f60a964f51d60ae382cfe97cc42532df
    std::shared_ptr< oldportal::fc::scheduler::Resource > ret;
    //TODO: getLockedResources()
    return ret;
}//END_f60a964f51d60ae382cfe97cc42532df


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE