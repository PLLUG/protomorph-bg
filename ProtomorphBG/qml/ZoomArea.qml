import QtQuick 2.12

import protomorph.qmlhelper 1.0

MouseArea {
    id: root

    property real currentScale: 1.0
    property real minScale: 1.0
    property real maxScale: 2.0
    property real scaleStep: 0.1

    onWheel: {
        if (root.currentScale >= root.minScale
                && root.currentScale <= root.maxScale) {
            var pixelDelta = wheel.angleDelta.y / 8
            var newScale = QmlHelper.roundToNDecimalPlaces(root.currentScale + ((pixelDelta / 15) * root.scaleStep))

            if (newScale < root.minScale)
                root.currentScale = root.minScale
            else if (newScale > root.maxScale)
                root.currentScale = root.maxScale
            else
                root.currentScale = newScale
        }
    }
}
