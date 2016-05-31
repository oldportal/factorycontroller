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


oldportal::fc::network::NetworkController::NetworkController()

{//BEGIN_108e13b6e9c79ba8ade22e512183ad53

}//END_108e13b6e9c79ba8ade22e512183ad53

oldportal::fc::network::NetworkController::NetworkController(std::shared_ptr< oldportal::fc::network::Network > network)

{//BEGIN_5ee793d28f81fe07f58fd5b2ed1b33dd
    _network = network;
}//END_5ee793d28f81fe07f58fd5b2ed1b33dd



oldportal::fc::network::NetworkController::~NetworkController()
{//BEGIN_4de2478f0423252a7abd1d53cc26ff8d

}//END_4de2478f0423252a7abd1d53cc26ff8d


void oldportal::fc::network::NetworkController::close()
{//BEGIN_72aaf2eea836be1532496923ffafeaf3
    // close() : empty
}//END_72aaf2eea836be1532496923ffafeaf3


void oldportal::fc::network::NetworkController::pushCommand(std::shared_ptr< oldportal::fc::network::DeviceCommand > command)
{//BEGIN_03ce7a06742d3023b663f24e13458d90
    std::lock_guard<std::recursive_mutex> lock(_command_queue_lock);
    _command_queue.push(command);
}//END_03ce7a06742d3023b663f24e13458d90

void oldportal::fc::network::NetworkController::step()
{//BEGIN_3033921a3e8dfcbf8411d6d9f69e8ac8
    while (!_command_back_queue.empty())
    {
        std::shared_ptr<oldportal::fc::network::DeviceCommand> command;

        {
            // pop command with mutex lock
            std::lock_guard<std::recursive_mutex> lock(_command_queue_lock);
            command = _command_back_queue.front();
            _command_back_queue.pop();
        }

        // after-process command step
        command->onProcessed();

        // clear command for avoid memory leaks:
        command->clear();
    }

    _step_counter.increment();
}//END_3033921a3e8dfcbf8411d6d9f69e8ac8


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE