import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4

import protomorph.uisizeadapter 1.0
import protomorph.qmlhelper 1.0

GridView {
    id: root

    property string gradient

    cellWidth: internal.cellSideSize; cellHeight: internal.cellSideSize;
    implicitHeight: internal.gridViewDefaultHeight

    boundsMovement: Flickable.StopAtBounds
    snapMode: GridView.SnapToRow
    clip: true

    model: QmlHelper.getPreseteGradientsList()

    highlight: Rectangle {
        width: root.cellWidth; height: root.cellHeight
        color: "transparent"
        border{
            width: internal.selectionBorderWidth
            color: Material.accent
        }
    }

    delegate: Page {
        width: root.cellWidth; height: root.cellHeight
        padding: internal.defaultMargin

        background: Item {}

        contentItem: Rectangle {
            gradient: modelData
        }

        footer: Label {
            id: gradientName
            text: modelData
            horizontalAlignment: Label.AlignHCenter; verticalAlignment: Label.AlignVCenter;
            bottomPadding: internal.defaultMargin
            font.weight: Font.DemiBold
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.gradient = modelData
                root.currentIndex = index
            }
        }
    }

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AsNeeded
    }

    QtObject {
        id: internal
        readonly property real cellSideSize: root.width / 2.0
        readonly property real gridViewDefaultHeight: cellSideSize * 2.0
        readonly property real defaultMargin: UISizeAdapter.calculateSize(5)
        readonly property real selectionBorderWidth: UISizeAdapter.calculateSize(2)
    }
}
