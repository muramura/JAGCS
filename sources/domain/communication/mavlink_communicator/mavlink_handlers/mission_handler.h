#ifndef MISSION_HANDLER_H
#define MISSION_HANDLER_H

#include "abstract_mavlink_handler.h"

namespace domain
{
    class MissionService;

    class MissionHandler: public AbstractMavLinkHandler
    {
    public:
        MissionHandler(MissionService* missionService,
                       MavLinkCommunicator* communicator);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

        void requestMission(uint8_t id);
        void requestMissionItem(uint8_t id, uint16_t item);

    private:
        MissionService* m_missionService;
    };
}

#endif // MISSION_HANDLER_H