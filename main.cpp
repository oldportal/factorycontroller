#include "factorycontroller/factorycontroller.h"

// command line argument parser
#include <boost/program_options.hpp>
#include <boost/program_options/cmdline.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    // command line parser

    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
    ("help,h", "produce help message")
    ("version", "print program version")
    ("config,c", boost::program_options::value<std::string>(), "initialize with configuration file")
    ("emulation,e", "emulate hardware")
    ("test,t", "run internal tests")
    ("project,p", boost::program_options::value<std::vector< std::string > >(), "project configuration file(s), by default test hardware if empty")
    ("reset,r", "reset all active projects and project tasks (or continue last projects otherwise)")
    ;

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    std::cout << "factorycontroller - Manufacturing Execution System" << std::endl;

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
    if (vm.count("emulation"))
    {
        std::cout << "emulation mode is not supported yet" << std::endl;
        //TODO: emulation mode
    }
    if (vm.count("test"))
    {
        std::cout << "test mode is not supported yet" << std::endl;
        //TODO: run tests mode
        return 1;
    }
    if (vm.count("config"))
    {
        std::string config_filename = vm["config"].as<std::string>();
        std::cout << "factorycontroller - Manufacturing Execution System" << std::endl;
        std::cout << "Initialize with configuration file: " << config_filename << std::endl;

        // init loader
        auto loader = std::make_shared<oldportal::fc::factory::manufacturing::proc::FactoryConfigurationFileLoader>(config_filename);
        loader->init();
        auto factory = std::make_shared<oldportal::fc::factory::manufacturing::Factory>
                (std::static_pointer_cast<oldportal::fc::factory::manufacturing::FactoryLoader>(loader));
        // free loader
        loader.reset();

        // start the Factory cycle
        factory->start();

        return 0;
    }
    if (vm.count("project"))
    {
        //TODO: run projects
    }
    if (vm.count("reset"))
    {
        //TODO: reset projects
    }

    // pure program loader as default
    // init loader
    auto loader = std::make_shared<oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader>();
    loader->init();
    auto factory = std::make_shared<oldportal::fc::factory::manufacturing::Factory>
            (std::static_pointer_cast<oldportal::fc::factory::manufacturing::FactoryLoader>(loader));
    // free loader
    loader.reset();

    // start the Factory cycle
    factory->start();

    return 0;
}
