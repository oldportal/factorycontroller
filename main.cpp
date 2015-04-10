#include "factorycontroller/factorycontroller.h"

// command line argument parser
#include <boost/program_options.hpp>
#include <boost/program_options/cmdline.hpp>

#include <log4cxx/logstring.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/simplelayout.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/ndc.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

using namespace std;

void init_logging()
{
    // BasicConfigurator replaced with PropertyConfigurator.
    //PropertyConfigurator::configure("log4cxx.properties");

    BasicConfigurator::configure();
    oldportal::fc::system::logger::root_logger = Logger::getRootLogger();
}

// static log example:
namespace oldportal {
log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("oldportal.fc.network.modbus.ModbusSerialRTUNetworkController"));
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

    // print general program description
    LOG4CXX_INFO(oldportal::fc::system::logger::root_logger, "factorycontroller - Manufacturing Execution System");
    //std::cout << "factorycontroller - Manufacturing Execution System" << std::endl;

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
      
        std::cout << "Initialize with default configuration" << std::endl;
      
        // init loader
        auto loader = std::make_shared<oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader>();
        loader->init();
        factory = std::make_shared<oldportal::fc::factory::manufacturing::Factory>
                (std::static_pointer_cast<oldportal::fc::factory::manufacturing::FactoryLoader>(loader));
        // free loader
        loader.reset();
    }

    // load factory options
    if (vm.count("emulation"))
    {
        std::cerr << "emulation mode is not supported yet" << std::endl;
        //TODO: emulation mode
        return 1;
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
    }
    if (vm.count("reset"))
    {
        //TODO: clear running projects
    }

    // start the Factory cycle
    factory->start();

    return 0;
}
