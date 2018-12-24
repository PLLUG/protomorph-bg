import QtQuick 2.12

import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12

ZoomArea {
    id: root

    property alias component: internalComponent

    Rectangle {
        id: internalComponent
        color: "#7a8ad7"
        anchors.centerIn: parent
        scale: root.currentScale
    }
}
