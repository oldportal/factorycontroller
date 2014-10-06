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


oldportal::fc::network::test::TestNetworkController::~TestNetworkController()
{//BEGIN_76058ff9472a91dd56c649daea129d31

}//END_76058ff9472a91dd56c649daea129d31


void oldportal::fc::network::test::TestNetworkController::close()
{//BEGIN_82eae4bef3672100ed4503365393c1a3
    // close() : empty
}//END_82eae4bef3672100ed4503365393c1a3

void oldportal::fc::network::test::TestNetworkController::initHardware()
{//BEGIN_303b6d9cb230b23ea149795bd0d06e69
    // initHardware() : empty
}//END_303b6d9cb230b23ea149795bd0d06e69

void oldportal::fc::network::test::TestNetworkController::step()
{//BEGIN_ae97a14dc042da1bef1d2d3f62dd7c88
    oldportal::fc::network::NetworkController::step();
}//END_ae97a14dc042da1bef1d2d3f62dd7c88


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE
