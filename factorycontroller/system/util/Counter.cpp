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


#include "../../factorycontroller.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fc::system::util::Counter::Counter()

{//BEGIN_43e9dd6ec2d039d1d7e51ca1c53cfb2c
    _counter = ATOMIC_VAR_INIT(0);
}//END_43e9dd6ec2d039d1d7e51ca1c53cfb2c


void oldportal::fc::system::util::Counter::clear()
{//BEGIN_d7be9ba9bdea0bffa854a09ef27df711
    _counter = ATOMIC_VAR_INIT(0);
}//END_d7be9ba9bdea0bffa854a09ef27df711

uint64_t oldportal::fc::system::util::Counter::get() const
{//BEGIN_86be2a7c94354c72fbfdcee30a5399c3
    return _counter;
}//END_86be2a7c94354c72fbfdcee30a5399c3

void oldportal::fc::system::util::Counter::increment()
{//BEGIN_334e7d39162cab49cc6e6bea6c9d704b
    _counter++;

    // value overflow check, (not true atomic)
    if (_counter >= UINT64_MAX-1001)
        _counter = ATOMIC_VAR_INIT(0);
}//END_334e7d39162cab49cc6e6bea6c9d704b


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE