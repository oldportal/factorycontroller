/*
*    This file is part of FactoryController project.
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
*    Copyright (C) Dmitry Ognyannikov, 2012-2017
*    dmogn@mail.ru
*/

#include "factorycontroller/factorycontroller.h"
#include "factory-hardware-emulator/factory-hardware-emulator.h"

// command line argument parser
#include <boost/program_options.hpp>
#include <boost/program_options/cmdline.hpp>

#include <stdlib.h>

#include <log4cxx/logstring.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/simplelayout.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/ndc.h>

using namespace std;

void init_logging()
{
    // BasicConfigurator replaced with PropertyConfigurator.
    //PropertyConfigurator::configure("log4cxx.properties");

    log4cxx::BasicConfigurator::configure();
    //log4cxx::LoggerPtr logger = log4cxx::Logger::getRootLogger();
}

void factorycontroller_exit_handler(void) {
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "normal program exit");
}

void factorycontroller_terminate_handler(void) {
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "terminate event");
}

void factorycontroller_unexpected_exception_handler(void) {
    LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "unexpected exception");
}

int main(int argc, char *argv[])
{
    // command line parser

    boost::program_options::options_description desc("General options");
    desc.add_options()
    ("help,h", "produce help message")
    ("version", "print program version")
    ("config,c", boost::program_options::value<std::string>(), "initialize with configuration file")
    ("emulation,e", "validate input and emulate without hardware")
    ("test,t", "run internal tests")
    ("project,p", boost::program_options::value<std::vector< std::string > >(), "project configuration file(s), by default test hardware if empty")
    ("reset,r", "reset all active projects and project tasks (or continue last projects otherwise)")
    ;

    // without unnamed parameters
    //boost::program_options::variables_map vm;
    //boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    //boost::program_options::notify(vm);

    // with unnamed parameters
    boost::program_options::positional_options_description p;
    p.add("project", -1);

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).
              options(desc).positional(p).run(), vm);
    boost::program_options::notify(vm);

    // init log
    init_logging();

    // event handlers
    atexit(factorycontroller_exit_handler);
    set_terminate(factorycontroller_terminate_handler);
    set_unexpected(factorycontroller_unexpected_exception_handler);

    // print general program description
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "factorycontroller - Manufacturing Execution System");
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "Copyright (C) Dmitry Ognyannikov, 2012-2017");

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 1;
    }
    if (vm.count("version"))
    {
        std::cout << "version 0.1 alpha" << std::endl;
        return 1;
    }

    // Global Factory object
    std::shared_ptr<oldportal::fc::factory::manufacturing::Factory> factory;

    // Global EmulatorApplication object
    std::shared_ptr<oldportal::fhe::EmulatorApplication> emulatorApplication;

    // init hardware modbus network emulator
    if (vm.count("emulation"))
    {
        emulatorApplication = std::make_shared<oldportal::fhe::EmulatorApplication>();
        emulatorApplication->_network = std::make_shared<oldportal::fhe::network::ModbusNetworkController>(emulatorApplication);
        std::shared_ptr<oldportal::fhe::device::Device> device = std::make_shared<oldportal::fhe::hardware::mechatronics::StepMotor>();
        device->_modbus_address = 18;
        emulatorApplication->_devices.push_back(device);
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "StepMotor emulated device added, modbus_address: 18");

        emulatorApplication->_network->init();

        // start emulator thread
        emulatorApplication->_network->start();
    }

    // init factory
    if (vm.count("config"))
    {
        // file configuration loader
        
        std::string config_filename = vm["config"].as<std::string>();
        std::cout << "Initialize with configuration file: " << config_filename << std::endl;

        // init loader
        auto loader = std::make_shared<oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader>(config_filename);
        loader->init();
        factory = std::make_shared<oldportal::fc::factory::manufacturing::Factory>
                (std::static_pointer_cast<oldportal::fc::factory::manufacturing::FactoryLoader>(loader));
        // free loader
        loader.reset();
    }
    else
    {
        // pure program loader as default
      
        std::cout << "Initialize with default configuration (pure program loader)" << std::endl;
      
        // init loader
        auto loader = std::make_shared<oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader>();
        factory = std::make_shared<oldportal::fc::factory::manufacturing::Factory>
                (std::static_pointer_cast<oldportal::fc::factory::manufacturing::FactoryLoader>(loader));
        loader->start_test_processes();

        // free loader
        loader.reset();
    }
    if (vm.count("test"))
    {
        std::cerr << "test mode is not supported yet" << std::endl;
        //TODO: run tests mode
        return 1;
    }
    if (vm.count("project"))
    {
        std::vector<std::string> project_filenames = vm["project"].as< std::vector<std::string> >();

        //TODO: add and run projects

        std::cerr << "project mode is not supported yet" << std::endl;
        return 1;
    }
    if (vm.count("reset"))
    {
        //TODO: clear running projects

        std::cerr << "reset mode is not supported yet" << std::endl;
        return 1;
    }

    // start the Factory cycle
    factory->start();

    return 0;
}
