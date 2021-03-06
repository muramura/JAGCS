#ifndef ATTITUDE_HANDLER_H
#define ATTITUDE_HANDLER_H

#include "abstract_mavlink_handler.h"

namespace domain
{
    class TelemetryService;
}

namespace comm
{
    class AttitudeHandler: public AbstractMavLinkHandler
    {
        Q_OBJECT

    public:
        explicit AttitudeHandler(MavLinkCommunicator* communicator);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    private:
        domain::TelemetryService* m_telemetryService;
    };
}

#endif // ATTITUDE_HANDLER_H
