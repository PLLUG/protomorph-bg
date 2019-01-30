import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.12

import QtGraphicalEffects 1.0

import protomorph.uisizeadapter 1.0
import protomorph.gameiconsmodel 1.0
import protomorph.svgimage 1.0

import "qrc:/actions"

Dialog {
    id: root

    property string currentIconUrl: ""

    modal: true; focus: true;
    standardButtons: Dialog.Ok | Dialog.Cancel
    parent: Overlay.overlay

//    width: parent.width/2; height: width
    anchors.centerIn: parent

    closePolicy: Popup.NoAutoClose

    onAccepted: {
        ApplicationActions.iconSelected({iconUrl: root.currentIconUrl})
        GameIconsFilterModel.searchPattern = ""
        destroy()
    }
    onRejected: {
        GameIconsFilterModel.searchPattern = ""
        destroy()
    }

    title: qsTr("Game Icons")

    header: Page {
        background: Item {
            visible: false
        }
        padding: 10
        contentItem: TextField {
            id: searchField
            Layout.fillHeight: true
            Layout.fillWidth: true
            autoScroll: true
            placeholderText: qsTr("Search game icons by name")
            onTextChanged: GameIconsFilterModel.searchPattern = text
        }

        footer: ToolSeparator {
            orientation: Qt.Horizontal
            horizontalPadding: 0
            verticalPadding: 0
        }
    }

    contentItem: GridView {
        id: gridView
        clip: true
        cellWidth: internal.cellWidth; cellHeight: internal.cellHeight;
        implicitHeight: internal.gridViewDefaultHeight
        cacheBuffer: 2 * (gridView.width * gridView.height)

        boundsMovement: Flickable.StopAtBounds
        snapMode: GridView.SnapToRow

        model: GameIconsFilterModel

        highlight: Rectangle {
            width: gridView.cellWidth; height: gridView.cellHeight
            color: "transparent"
            border{
                width: internal.selectionBorderWidth
                color: Material.accent
            }
        }

        delegate: Page {
            width: gridView.cellWidth; height: gridView.cellHeight
            padding: internal.defaultMargin

            background: Item {
                visible: false
            }

            contentItem: SvgPainter {
                content: iconDataRole
                imageColor: Material.accent
            }

            footer: Label {
                id: iconName
                text: iconNameRole
                horizontalAlignment: Label.AlignHCenter; verticalAlignment: Label.AlignVCenter;
                bottomPadding: internal.defaultMargin
                font.weight: Font.DemiBold
                elide: Label.ElideRight
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.currentIconUrl = iconUrlRole
                    gridView.currentIndex = index
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AsNeeded
            size: 0.4
        }

        QtObject {
            id: internal
            readonly property int nofRows: 5
            readonly property int nofColumns: 6
            readonly property real cellHeight: gridView.height / nofRows
            readonly property real cellWidth: gridView.width / nofColumns
            readonly property real gridViewDefaultHeight: gridView.width
            readonly property real defaultMargin: UISizeAdapter.calculateSize(5)
            readonly property real selectionBorderWidth: UISizeAdapter.calculateSize(3)
        }
    }
}
