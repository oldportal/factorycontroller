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


//BEGIN_USER_SECTION_BEFORE_MASTER_INCLUDE

//END_USER_SECTION_BEFORE_MASTER_INCLUDE


#include "../factory-hardware-emulator.h"

//BEGIN_USER_SECTION_AFTER_MASTER_INCLUDE

//END_USER_SECTION_AFTER_MASTER_INCLUDE


oldportal::fhe::network::ModbusNetworkController::ModbusNetworkController(std::weak_ptr< oldportal::fhe::EmulatorApplication > application)

{//BEGIN_2019c5510015ad3d8d2bcd7e203ed210
    assert(!application.expired());
    _application = application;

    _modbus_ctx = nullptr;
    _query = nullptr;
    _socket = -1;

    _run_thread_cycle_flag = false;
}//END_2019c5510015ad3d8d2bcd7e203ed210



oldportal::fhe::network::ModbusNetworkController::~ModbusNetworkController()
{//BEGIN_3b0b6e57a9ab008d2eb65c6395d8f01e
    if (_query != nullptr)
        free(_query);

    if (_socket != -1) {
        ::close(_socket);
        _socket = -1;
    }

    if (_modbus_ctx != nullptr)
    {
        modbus_close(_modbus_ctx);
        modbus_free(_modbus_ctx);
    }
}//END_3b0b6e57a9ab008d2eb65c6395d8f01e


void oldportal::fhe::network::ModbusNetworkController::close()
{//BEGIN_084e72aff6e40ff9eba26970b1bd916f
    _run_thread_cycle_flag = false;

    if (_socket != -1) {
        ::close(_socket);
        _socket = -1;
    }
}//END_084e72aff6e40ff9eba26970b1bd916f

modbus_t* oldportal::fhe::network::ModbusNetworkController::getModbusContext()
{//BEGIN_c3936de45fe67828981a96162531f82b
    return _modbus_ctx;
}//END_c3936de45fe67828981a96162531f82b

void oldportal::fhe::network::ModbusNetworkController::init()
{//BEGIN_3b09a28375be1e7d2d8a78eaea0d11a9
    assert(_modbus_ctx == nullptr);
    assert(_query == nullptr);
    
    LOG4CXX_INFO(logger, "ModbusNetworkController::init() call. Bind to 127.0.0.1:1502.");

    _modbus_ctx = modbus_new_tcp_pi("127.0.0.1", "1502");
    modbus_set_debug(_modbus_ctx, TRUE);

    _query = (uint8_t*)malloc(MODBUS_TCP_MAX_ADU_LENGTH);

    _socket = modbus_tcp_pi_listen(_modbus_ctx, 1);
    if (_socket == -1)
    {
        fprintf(stderr, "modbus_tcp_pi_listen error: %s\n", modbus_strerror(errno));
        return;
    }

    //modbus_set_slave(_modbus_ctx, 1);

}//END_3b09a28375be1e7d2d8a78eaea0d11a9

void oldportal::fhe::network::ModbusNetworkController::run()
{//BEGIN_8e94675d1917f794cd825b81ee5da0b1
    assert(_modbus_ctx);
    assert(_query);
    assert(_socket != -1);
    assert(!_run_thread_cycle_flag);


    if (modbus_tcp_pi_accept(_modbus_ctx, &_socket) == -1)
    {
        fprintf(stderr, "Receive request error: %s\n", modbus_strerror(errno));
        LOG4CXX_ERROR(logger, std::string("Receive request error: ") + modbus_strerror(errno));
        return;
    }

    LOG4CXX_INFO(logger, "ModbusNetworkController::run() - start main request receiving cycle");
    
    _run_thread_cycle_flag = true;
    while (_run_thread_cycle_flag)
    {
        // clear error register
        errno = 0;

        // bytes received:
        const int received_length = modbus_receive(_modbus_ctx, _query);

        if (received_length > 0) {
            fprintf(stdout, "Request received, length: %i\n", received_length);

            // process device address

            const int header_length = modbus_get_header_length(_modbus_ctx);
            // slave device address
            const uint8_t slave_address = _query[header_length - 1];
            // Modbus function
            const uint8_t function = _query[header_length];
            // Starting Address
            //const uint16_t starting_address = (_query[header_length + 1] << 8) + _query[header_length + 2];
            // Quantity of Registers
            //const uint16_t quantity_of_registers = (_query[header_length + 3] << 8) + _query[header_length + 4];

            std::shared_ptr<oldportal::fhe::EmulatorApplication> application = _application.lock();
            assert(application);

            for (auto device : application->_devices)
            {
                assert(device);
                if (slave_address == MODBUS_BROADCAST_ADDRESS || slave_address == device->_modbus_address)
                {
                    // send request to device
                    device->process_request(_query, received_length, slave_address, function, _modbus_ctx);

                    if (slave_address != MODBUS_BROADCAST_ADDRESS)
                        break;
                }
            }
        } else if (received_length == -1) {
            /* Connection closed by the client or error */
            if (errno != 0)
            {
                // out error description:
                fprintf(stderr, "Receive request error: %s\n", modbus_strerror(errno));
                LOG4CXX_ERROR(logger, std::string("Receive request error: ") + modbus_strerror(errno));
            }

            close();
            break;
        }
    }
}//END_8e94675d1917f794cd825b81ee5da0b1


//BEGIN_USER_SECTION_AFTER_GENERATED_CODE

//END_USER_SECTION_AFTER_GENERATED_CODE