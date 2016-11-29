/*
*    This file is part of factory-hardware-emulator program and part of FactoryController project.
*    
*    factory-hardware-emulator is free software; you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) version 3.
*    
*    factory-hardware-emulator is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*    
*    You should have received a copy of the GNU Lesser General Public License
*    along with factory-hardware-emulator; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*    
*    Copyright (C) Dmitry Ognyannikov, 2014-2016
*    dmogn@mail.ru
*/
#ifndef H_c11a0df9b25f3410b75e4464ca339c2c_H
#define H_c11a0df9b25f3410b75e4464ca339c2c_H




//BEGIN_GROUP_COMMENT
/**
*/
//END_GROUP_COMMENT


//BEGIN_USER_SECTION_0

//END_USER_SECTION_0


namespace oldportal 
{
namespace fhe 
{
namespace network 
{
// global variables declaration
extern log4cxx::LoggerPtr logger;
}// namespace network
}// namespace fhe
}// namespace oldportal


namespace oldportal 
{
namespace fhe 
{
namespace network 
{
// global methods declaration
uint32_t CalculateTimeInterval(uint32_t current_clock, uint32_t last_clock);

uint32_t GetSystemTime();

}// namespace network
}// namespace fhe
}// namespace oldportal


#include "scheduled/_group_scheduled.h"



#endif // H_c11a0df9b25f3410b75e4464ca339c2c_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_c11a0df9b25f3410b75e4464ca339c2c_INLINES_H
#define H_c11a0df9b25f3410b75e4464ca339c2c_INLINES_H
//BEGIN_USER_SECTION_1

//END_USER_SECTION_1

#include "scheduled/_group_scheduled.h"


#endif // H_c11a0df9b25f3410b75e4464ca339c2c_INLINES_H

#endif //OBJECTS_BUILDER_PROJECT_INLINES