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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::system::util::StepCounter::StepCounter()

{//BEGIN_c892946fc38d8ac211be905fcd313059
    _counter = ATOMIC_VAR_INIT(0);
}//END_c892946fc38d8ac211be905fcd313059


bool oldportal::fc::system::util::StepCounter::checkDivider(const uint32_t divider) const
{//BEGIN_bc69dbcda4573a1639d53a65c25f0fb4
    return _counter % divider == 0;
}//END_bc69dbcda4573a1639d53a65c25f0fb4

bool oldportal::fc::system::util::StepCounter::checkDivider(const uint32_t divider, const uint32_t add) const
{//BEGIN_359c1d81ab7282712cc89487cd77134b
    return _counter % divider == add;
}//END_359c1d81ab7282712cc89487cd77134b

void oldportal::fc::system::util::StepCounter::clear()
{//BEGIN_b4f28bfe162814b332c856552c02d190
    _counter = ATOMIC_VAR_INIT(0);
}//END_b4f28bfe162814b332c856552c02d190

uint64_t oldportal::fc::system::util::StepCounter::get() const
{//BEGIN_e47dffaf68e63849d185447130e4cc12
    return _counter;
}//END_e47dffaf68e63849d185447130e4cc12

void oldportal::fc::system::util::StepCounter::increment()
{//BEGIN_51a5299fc8d39e1ab2397963902605a6
    _counter++;

    // value overflow check, (not true atomic)
    if (_counter >= UINT64_MAX-1001)
        _counter = ATOMIC_VAR_INIT(0);
}//END_51a5299fc8d39e1ab2397963902605a6


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
