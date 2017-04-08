#ifndef COMMUNICATION_MANAGER_H
#define COMMUNICATION_MANAGER_H

// Qt
#include <QObject>

// Internal
#include "db_traits.h"

namespace data_source
{
    class DbEntry;
}

namespace domain
{
    class ICommunicatorFactory;

    class CommunicationManager: public QObject
    {
        Q_OBJECT

    public:
        CommunicationManager(ICommunicatorFactory* commFactory,
                             data_source::DbEntry* entry,
                             QObject* parent = nullptr);
        ~CommunicationManager() override;

        data_source::LinkDescriptionPtrList links() const;

    public slots:
        void saveLink(const data_source::LinkDescriptionPtr& description);
        void removeLink(const data_source::LinkDescriptionPtr& description);

    signals:
        void linksChanged(const data_source::LinkDescriptionPtrList& links);

    private:
        class Impl;
        QScopedPointer<Impl> const d;
    };
}

#endif // COMMUNICATION_MANAGER_H
