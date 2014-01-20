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
*    Copyright (C) Dmitry Ognyannikov, 2012
*/
#ifndef H_71348f18c8812d9608a169b997550a2a_H
#define H_71348f18c8812d9608a169b997550a2a_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION

//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{
namespace modbus 
{

class ModbusNetworkController
:  public virtual oldportal::fc::network::NetworkController
{
// constructors:
public:
ModbusNetworkController();
public:
ModbusNetworkController(std::shared_ptr< oldportal::fc::network::Network > network);


public:
virtual ~ModbusNetworkController();

// members:

private:
boost::asio::io_service _serial_port_io;
private:
std::shared_ptr< boost::asio::serial_port > _serial_port;
public:
std::queue< std::shared_ptr<ModbusMessagePair> > _message_queue;


//methods:

/**
1. Iniit and open Modbus port.
2. Start low-level realtime network thread.
3. Call high level NetworkContrroller function.
*/
public:
virtual void initHardware();

protected:
void processMessagePair(oldportal::fc::network::modbus::ModbusMessagePair& message);

private:
void realtime_run();



//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace network
}// namespace modbus


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_71348f18c8812d9608a169b997550a2a_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_71348f18c8812d9608a169b997550a2a_INLINES_H
#define H_71348f18c8812d9608a169b997550a2a_INLINES_H

#endif // H_71348f18c8812d9608a169b997550a2a_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES