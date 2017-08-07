#include "mission_item.h"

// Qt
#include <QMetaEnum>
#include <QDebug>

// Internal
#include "mission.h"

using namespace dao;

int MissionItem::missionId() const
{
    return m_missionId;
}

void MissionItem::setMissionId(int missionId)
{
    m_missionId = missionId;
}

int MissionItem::sequence() const
{
    return m_sequence;
}

void MissionItem::setSequence(int sequence)
{
    m_sequence = sequence;
}

MissionItem::Command MissionItem::command() const
{
    return m_command;
}

void MissionItem::setCommand(Command command)
{
    m_command = command;
}

float MissionItem::altitude() const
{
    return m_altitude;
}

void MissionItem::setAltitude(float altitude)
{
    m_altitude = altitude;
}

bool MissionItem::isAltitudeRelative() const
{
    return m_altitudeRelative;
}

void MissionItem::setAltitudeRelative(bool altitudeRelative)
{
    m_altitudeRelative = altitudeRelative;
}

double MissionItem::latitude() const
{
    return m_latitude;
}

void MissionItem::setLatitude(double latitude)
{
    m_latitude = latitude;
}

double MissionItem::longitude() const
{
    return m_longitude;
}

void MissionItem::setLongitude(double longitude)
{
    m_longitude = longitude;
}

MissionItem::Status MissionItem::status() const
{
    return m_status;
}

void MissionItem::setStatus(Status status)
{
    m_status = status;
}

bool MissionItem::isReached() const
{
    return m_reached;
}

void MissionItem::setReached(bool reached)
{
    m_reached = reached;
}

QString MissionItem::parameters() const
{
    QStringList list;
    int enumIndex = MissionItem::staticMetaObject.indexOfEnumerator("Parameter");
    QMetaEnum enumerator = MissionItem::staticMetaObject.enumerator(enumIndex);

    for (Parameter parameter: m_parameters.keys())
    {
        list.append(QString(enumerator.valueToKey(parameter)) + ":" + m_parameters.value(parameter).toString());
    }

    return list.join(";");
}

void MissionItem::setParameters(const QString& arguments)
{
    int enumIndex = MissionItem::staticMetaObject.indexOfEnumerator("Parameter");
    QMetaEnum enumerator = MissionItem::staticMetaObject.enumerator(enumIndex);

    m_parameters.clear();
    for (const QString& pairs: arguments.split(";"))
    {
        QStringList pairList = pairs.split(":");
        if (pairList.count() < 2) continue;

        Parameter param = static_cast<Parameter>(enumerator.keyToValue(qPrintable(pairList.at(0))));
        if (param != UnknownParameter) m_parameters[param] = pairList.at(1);
    }
}

QVariant MissionItem::parameter(Parameter key)
{
    return m_parameters.value(key);
}

void MissionItem::setParameter(MissionItem::Parameter key, const QVariant& parameter)
{
    m_parameters[key] = parameter;
}
