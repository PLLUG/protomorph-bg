import QtQuick 2.12
import QtQuick.Controls.Material 2.4

import protomorph.uisizeadapter 1.0
import protomorph.qmlhelper 1.0

Item {
    id: root
    property alias contentItem: itemLoader.sourceComponent

    Loader {
        anchors.fill: parent
        id: itemLoader
    }

    Rectangle {
        id: borderRect
        color: "transparent"
        anchors.fill: parent
        anchors.margins: -internal.borderWidth
        border{
            color: internal.borderColor
            width: internal.borderWidth
        }

        MouseArea {
            anchors{
                margins: internal.borderWidth
                fill: parent
            }
            drag.target: root
            onEntered: cursorShape = Qt.SizeAllCursor
        }
    }


    Repeater {
        model: internal.resizeSpots

        Rectangle {
            id: spotRect

            anchors {
                top: modelData.anchors.top
                bottom: modelData.anchors.bottom
                left: modelData.anchors.left
                right: modelData.anchors.right
                verticalCenter: modelData.anchors.verticalCenter
                horizontalCenter: modelData.anchors.horizontalCenter
            }

            property point previousCoordinates

            color: internal.borderColor
            width: internal.spotSideSize; height: internal.spotSideSize
            radius: internal.spotRadius

            MouseArea {
                property string spotType: modelData.type
                anchors.fill: parent
                cursorShape: modelData.cursorType
                drag.target: spotRect
                drag.threshold: 0
                onPressed: spotRect.previousCoordinates = Qt.point(mouseX, mouseY)

                onPositionChanged: {
                    if(!drag.active)
                        return

                    var displacementY = mouseY - spotRect.previousCoordinates.y
                    var displacementX = mouseX - spotRect.previousCoordinates.x

                    switch(spotType) {
                    case "topLeft":
                        root.y += displacementY
                        root.height -= displacementY
                        root.x += displacementX
                        root.width -= displacementX
                        break;
                    case "topMid":
                        root.y += displacementY
                        root.height -= displacementY
                        break;
                    case "topRight":
                        root.y += displacementY
                        root.height -= displacementY
                        root.width += displacementX
                        break;
                    case "leftMid":
                        root.x += displacementX
                        root.width -= displacementX
                        break;
                    case "rightMid":
                        root.width += displacementX
                        break;
                    case "bottomLeft":
                        root.height += displacementY
                        root.x += displacementX
                        root.width -= displacementX
                        break;
                    case "bottomMid":
                        root.height += displacementY
                        break;
                    case "bottomRight":
                        root.width += displacementX
                        root.height += displacementY
                        break;
                    }
                }
            }
        }
    }


    QtObject {
        id: internal
        readonly property color borderColor: Material.background
        readonly property real borderWidth: UISizeAdapter.calculateSize(3)
        readonly property real spotSideSize: borderWidth * 3.0
        readonly property real spotRadius: borderWidth / 1.5

        property var resizeSpots: [
            {type: "topLeft", anchors: {bottom: root.top, right: root.left}, cursorType: Qt.SizeFDiagCursor},
            {type: "topMid", anchors: {bottom: root.top, horizontalCenter: root.horizontalCenter}, cursorType: Qt.SizeVerCursor},
            {type: "topRight",  anchors: {bottom: root.top, left: root.right}, cursorType: Qt.SizeBDiagCursor},
            {type: "leftMid", anchors: {right: root.left, verticalCenter: root.verticalCenter}, cursorType: Qt.SizeHorCursor},
            {type: "rightMid", anchors: {left: root.right, verticalCenter: root.verticalCenter}, cursorType: Qt.SizeHorCursor},
            {type: "bottomLeft", anchors: {top: root.bottom, right: root.left}, cursorType: Qt.SizeBDiagCursor},
            {type: "bottomMid", anchors: {top: root.bottom, horizontalCenter: root.horizontalCenter}, cursorType: Qt.SizeVerCursor},
            {type: "bottomRight", anchors: {top: root.bottom, left: root.right}, cursorType: Qt.SizeFDiagCursor}
        ]
    }
}
