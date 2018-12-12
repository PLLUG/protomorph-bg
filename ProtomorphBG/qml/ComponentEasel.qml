import QtQuick 2.12

import QtQuick.Controls 2.5

MouseArea {
    id: root

    property alias component: internalComponent

    QtObject {
        id: internal
        readonly property int zoomFactor: 10
    }

    Rectangle {
        id: internalComponent
        color: "#7a8ad7"
        anchors.centerIn: parent
    }

    onWheel: {
        if (internalComponent.scale >= 1.0 && internalComponent.scale <= 2.0)
        {
            var pixelDelta =  wheel.angleDelta.y / 8;
            internalComponent.scale += (pixelDelta / 15) * 0.1
            if (internalComponent.scale < 1.0)
                internalComponent.scale = 1.0
            if (internalComponent.scale > 2.0)
                internalComponent.scale = 2.0
        }
    }
}
