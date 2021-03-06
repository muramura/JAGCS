import QtQuick 2.6

import "../Controls" as Controls
import "qrc:/JS/helper.js" as Helper

Item {
    id: root

    property real rssi: minRssiValue
    property real minRssiValue: -120

    implicitWidth: palette.controlBaseSize
    implicitHeight: implicitWidth

    Row {
        id: row
        spacing: root.width / 20
        layoutDirection: Qt.RightToLeft
        anchors.centerIn: parent

        Repeater {
            id: repeater
            model: 5

            Rectangle {
                anchors.bottom: parent.bottom
                width: root.width / repeater.count - row.spacing
                height: (repeater.count - index) * root.height / (repeater.count + 1)
                color: rssi >= Helper.mapToRange(index, 0, 5, minRssiValue) ?
                           palette.selectionColor : palette.sunkenColor
            }
        }
    }
}

