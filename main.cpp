#include "factorycontroller/factorycontroller.h"

// command line argument parser
#include <boost/program_options.hpp>
#include <boost/program_options/cmdline.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    //TODO: command line parser

    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("version", "print program version")
    ;

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << "factorycontroller - Manufacturing Execution System" << std::endl;
        std::cout << desc << std::endl;
        return 1;
    }
    if (vm.count("version"))
    {
        std::cout << "factorycontroller - Manufacturing Execution System" << std::endl;
        std::cout << "version 0.1 alpha" << std::endl;
        return 1;
    }

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
