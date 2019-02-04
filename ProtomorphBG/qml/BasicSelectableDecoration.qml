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

        anchors{
            fill: parent
            margins: -internal.borderWidth
        }

        border {
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

            readonly property string spotType: modelData.type
            property point previousCoordinates

            color: internal.borderColor
            width: internal.spotSideSize; height: internal.spotSideSize
            radius: internal.spotRadius

            Rectangle {
                anchors{
                    margins: UISizeAdapter.calculateSize(1)
                    fill: parent
                }
                color: Material.accent
            }

            MouseArea {

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

                    var newDecorationRect = internal.getNewSizeFromResizeSpot(spotRect.spotType, displacementX, displacementY)

                    if(newDecorationRect.height > internal.minDecorationSideize) {
                        root.y = newDecorationRect.y
                        root.height = newDecorationRect.height
                    }

                    if(newDecorationRect.width > internal.minDecorationSideize) {
                        root.x = newDecorationRect.x
                        root.width = newDecorationRect.width
                    }
                }
            }
        }
    }

    QtObject {
        id: internal
        readonly property color borderColor: Qt.darker(Material.background)
        readonly property real borderWidth: UISizeAdapter.calculateSize(3)
        readonly property real spotSideSize: borderWidth * 1.5
        readonly property real spotRadius: spotSideSize / 4.0

        readonly property real minDecorationSideize: UISizeAdapter.calculateSize(15)

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

        function getNewSizeFromResizeSpot(resizeSpotType, displacementX, displacementY) {
            var newX = root.x; var newY = root.y;
            var newWidth = root.width; var newHeight = root.height;

            switch(resizeSpotType) {
            case "topLeft":
                newY += displacementY
                newHeight -= displacementY
                newX += displacementX
                newWidth -= displacementX
                break;
            case "topMid":
                newY += displacementY
                newHeight -= displacementY
                break;
            case "topRight":
                newY += displacementY
                newHeight -= displacementY
                newWidth += displacementX
                break;
            case "leftMid":
                newX += displacementX
                newWidth -= displacementX
                break;
            case "rightMid":
                newWidth += displacementX
                break;
            case "bottomLeft":
                newHeight += displacementY
                newX += displacementX
                newWidth -= displacementX
                break;
            case "bottomMid":
                newHeight += displacementY
                break;
            case "bottomRight":
                newWidth += displacementX
                newHeight += displacementY
                break;
            }

            return Qt.rect(newX, newY, newWidth, newHeight);
        }
    }
}
