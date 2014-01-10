#include "factorycontroller/factorycontroller.h"

using namespace std;

int main(int argc, char *argv[])
{
    auto loader = std::make_shared<oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader>();
    loader->init();
    auto factory = std::make_shared<oldportal::fc::factory::manufacturing::Factory>
            (std::static_pointer_cast<oldportal::fc::factory::manufacturing::FactoryLoader>(loader));
    loader.reset();

    factory->start();

    return 0;
}
