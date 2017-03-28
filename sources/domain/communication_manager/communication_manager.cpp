#include "communication_manager.h"

// Internal
#include "abstract_communicator.h"
#include "udp_link.h"
#include "serial_link.h"

#include "settings_provider.h"

#include "i_communicator_factory.h"

using namespace data_source;
using namespace domain;

class CommunicationManager::Impl
{
public:
    AbstractCommunicator* communicator;
};

CommunicationManager::CommunicationManager(ICommunicatorFactory* factory,
                                           QObject* parent):
    QObject(parent),
    d(new Impl())
{
    d->communicator = factory->create();
}

CommunicationManager::~CommunicationManager()
{
    delete d;
}

void CommunicationManager::addUdpLonk()
{
    d->communicator->addLink(new UdpLink(SettingsProvider::value(
                                     connection_settings::port).toInt()));
}

void CommunicationManager::addSerialLink()
{
    d->communicator->addLink(new SerialLink(SettingsProvider::value(
                                  connection_settings::serialDevice).toString(),
                                            SettingsProvider::value(
                                  connection_settings::baudRate).toInt()));
}
