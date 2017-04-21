#ifndef DOMAIN_FACADE_H
#define DOMAIN_FACADE_H

// Qt
#include <QScopedPointer>

namespace domain
{
    class CommunicationManager;
    class VehicleService;
    class ProxyManager;

    class DomainFacade
    {
    public:
        DomainFacade();
        ~DomainFacade();

        CommunicationManager* communicationManager() const;
        VehicleService* vehicleService() const;
        ProxyManager* proxyManager() const;

    private:
        class Impl;
        QScopedPointer<Impl> const d;
    };
}

#endif // DOMAIN_FACADE_H
