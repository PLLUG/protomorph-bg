import QtQuick 2.12
import QtQuick.Controls.Material 2.4

import protomorph.uisizeadapter 1.0

Item {
    id: root
    anchors.margins: -borderRect.border.width

    Repeater {
        model: internal.resizeSpots

        Rectangle {
            color: internal.borderColor
            width: internal.borderWidth * 2; height: width
            x: modelData.point.x; y: modelData.point.y
            radius: internal.borderWidth

            MouseArea {
                property string spotType: modelData.type
                anchors.fill: parent
                cursorShape: modelData.cursorType
                onPositionChanged: {
                    var rootParent = root.parent;
                    print("parent: ", rootParent.x, rootParent.y, rootParent.width, rootParent.height)
                    print("mouse: ", rootParent.x, rootParent.y)
                    switch(spotType) {
                    case "topLeft":
                        break;
                    case "topMid":
                        break;
                    case "topRight":
                        break;
                    case "leftMid":
                        break;
                    case "rightMid":
                        break;
                    case "bottomLeft":
                        break;
                    case "bottomMide":
                        break;
                    case "bottomRight":
                        break;
                    }
                }
            }
        }
    }

    Rectangle {
        id: borderRect
        color: "transparent"
        anchors.fill: parent
        border{
            color: internal.borderColor
            width: internal.borderWidth
        }

        MouseArea {
            anchors{
                margins: internal.borderWidth
                fill: parent
            }
            drag.target: root.parent
            onEntered: cursorShape = Qt.SizeAllCursor
        }
    }

    QtObject {
        id: internal
        readonly property color borderColor: Material.background
        readonly property real borderWidth: UISizeAdapter.calculateSize(3)

        readonly property real horizontalMid: root.x + root.width / 2
        readonly property real verticalMid: root.y + root.height / 2
        readonly property real right: root.x + root.width
        readonly property real bottom: root.y + root.height

        readonly property point topLeft: Qt.point(root.x, root.y)
        readonly property point topMid: Qt.point(internal.horizontalMid, root.y)
        readonly property point topRight: Qt.point(internal.right, root.y)
        readonly property point leftMid: Qt.point(root.x, internal.verticalMid)
        readonly property point rightMid: Qt.point(internal.right, internal.verticalMid)
        readonly property point bottomLeft: Qt.point(root.x, internal.bottom)
        readonly property point bottomMid: Qt.point(internal.horizontalMid, internal.bottom)
        readonly property point bottomRight: Qt.point(internal.right, internal.bottom)

        property var resizeSpots: [
            {type: "topLeft", point: topLeft, cursorType: Qt.SizeFDiagCursor},
            {type: "topMid", point: topMid, cursorType: Qt.SizeVerCursor},
            {type: "topRight", point: topRight, cursorType: Qt.SizeBDiagCursor},
            {type: "leftMid", point: leftMid, cursorType: Qt.SizeHorCursor},
            {type: "rightMid", point: rightMid, cursorType: Qt.SizeHorCursor},
            {type: "bottomLeft", point: bottomLeft, cursorType: Qt.SizeBDiagCursor},
            {type: "bottomMid", point: bottomMid, cursorType: Qt.SizeVerCursor},
            {type: "bottomRight", point: bottomRight, cursorType: Qt.SizeFDiagCursor}
        ]
    }
}
