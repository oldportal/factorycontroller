#include "factorycontroller/factorycontroller.h"

// command line argument parser
#include <boost/program_options/cmdline.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    //TODO: command line parser

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
