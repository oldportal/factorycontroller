#include "factorycontroller/factorycontroller.h"
#include <QCoreApplication>
#include <QThread>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader *loader = new oldportal::fc::factory::manufacturing::proc::FactoryPureProgramLoader();
    QSharedPointer<oldportal::fc::factory::manufacturing::Factory> factory(new oldportal::fc::factory::manufacturing::Factory((oldportal::fc::factory::manufacturing::FactoryLoader*)loader));
    delete loader;

    factory->start();

    return a.exec();
}
