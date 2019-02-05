import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.12

import "qrc:/custom_controls"
import "qrc:/stores"

Page {
    id: root
    padding: 0

    background: Rectangle {
        color: Material.color(Material.BlueGrey, Material.Shade100)
    }

    contentItem: ZoomArea {
        id: easel

        ComponentCanvas {
            anchors.centerIn: parent
            height: mainStore.componentEditorStore.height
            width: mainStore.componentEditorStore.width

            scale: easel.currentScale
        }
    }

    footer: Page {
        id: statusBar
        padding: 0

        header: ToolSeparator {
            orientation: Qt.Horizontal
            horizontalPadding: 0
            verticalPadding: 0
        }

        contentItem: RowLayout {
            id: statusBarLayout
            spacing: 0

            Item {
                Layout.fillWidth: true
            }

            ZoomLabel {
                id: zoomLabel
                zoomValue: easel.currentScaleInPercent
                Layout.fillHeight: true
                Layout.minimumWidth: zoomLabel.implicitWidth
                Layout.margins: 10
            }
        }
    }
}
