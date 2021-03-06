#ifndef BATTERY_PRESENTER_H
#define BATTERY_PRESENTER_H

#include "abstract_telemetry_presenter.h"

namespace presentation
{
    class BatteryPresenter: public AbstractTelemetryPresenter
    {
        Q_OBJECT

    public:
        explicit BatteryPresenter(domain::Telemetry* node, QObject* parent = nullptr);

    public slots:
        void onParametersChanged(const domain::Telemetry::TelemetryMap& parameters) override;
    };
}

#endif // BATTERY_PRESENTER_H
