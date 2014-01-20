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
#ifndef H_05ad12c1924072c4f513f05ccdcc1e00_H
#define H_05ad12c1924072c4f513f05ccdcc1e00_H



//BEGIN_USER_SECTION_BEFORE_CLASS_DECLARATION
typedef enum
{
    CTRLR_MODE_IDLE = 0,                /* Idle (minimal power consumption, all power circuits disabled). Idle is default mode. */
    CTRLR_MODE_EMERGENCY_STOP,                /* Emergency stop (brake and stop all motion, disable power circuits). Caused by master command. The mode can be leaved only with reset. */
	CTRLR_MODE_STOP_KEEP_STATE,                /* Stop and keep state (force keep current state or servodrive position, wait for commands). Default mode after mode DIRECT_CONTROL (4) and NC_COMMANDS_FLOW (5). */
	CTRLR_MODE_DIRECT_CONTROL,                /* Direct control (direct realtime control with change force, speed, etc. control parameters). General register and coil read/write commands are used. Switch to mode STOP_KEEP_STATE (3) with timeout without any register read or write commands. */
	CTRLR_MODE_NC_COMMANDS_FLOW,                /* NC commands flow execution. Switch to mode STOP_KEEP_STATE (3) after command queue execution end. */
	CTRLR_MODE_RESET,                /* Reset (stop all motion, disable power circuits, hardware reset). */
	CTRLR_MODE_HARDWARE_ERROR,                /* Hardware error (mechanical faults, etc.). The mode can be leaved only with reset. */
	CTRLR_MODE_HEAT_MOTOR                /* Heat motor (heat motor with 1% of nominal power) for prevention of wet condensation and corrosion inside motor and driver. */
} cntrMode;

typedef enum
{
	CTRLR_NO_ERRORS = 0,
	CTRLR_OTHER_ERROR,
	CTRLR_HARDWARE_SOFTWARE_FAILURE_DETECTED,
	CTRLR_HARDWARE_FIRMWARE_CHECKSUM_FAILURE,
	CTRLR_HARDWARE_RADIATOR_TEMPERATURE_OVERHEAT,
	CTRLR_HARDWARE_POWER_LINE_OVERVOLTAGE,
	CTRLR_HARDWARE_LOW_VOLTAGE_LINE_UNDERVOLTAGE,
	CTRLR_HARDWARE_DIRECT_CONTROL_INTERFACE_TIMEOUT,
	CTRLR_HARDWARE_DRIVER_SPECIFIC_ERROR,
	CTRLR_SOFTWARE_ILLEGAL_ARGUMENT_DETECTED,
	PWM_SOFTWARE_CHANNEL_NUMBER_OUT_OF_RANGE,
	CTRLR_SOFTWARE_ILLEGAL_PIN_PORT_NUMER,
	MODBUS_INTERFACE_FRAME_PROCESSING_ERROR
} cntrHardwareErrorType;
//END_USER_SECTION_BEFORE_CLASS_DECLARATION


/**

*/
namespace oldportal 
{
namespace fc 
{
namespace network 
{

class NetworkDevice
{
// constructors:
public:
NetworkDevice();
public:
NetworkDevice(std::weak_ptr< oldportal::fc::network::Network > network);


public:
virtual ~NetworkDevice();

// members:

public:
int64_t _id;
public:
oldportal::fc::network::NetworkErrorStatistics _error_statistics;
public:
std::weak_ptr< oldportal::fc::network::Network > _network;
public:
std::wstring _description;


//methods:


//child groups:


//child classes:


};
}// namespace oldportal
}// namespace fc
}// namespace network


//BEGIN_USER_SECTION_AFTER_CLASS_DECLARATION

//END_USER_SECTION_AFTER_CLASS_DECLARATION


#endif // H_05ad12c1924072c4f513f05ccdcc1e00_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_05ad12c1924072c4f513f05ccdcc1e00_INLINES_H
#define H_05ad12c1924072c4f513f05ccdcc1e00_INLINES_H

#endif // H_05ad12c1924072c4f513f05ccdcc1e00_INLINES_H
#endif //OBJECTS_BUILDER_PROJECT_INLINES