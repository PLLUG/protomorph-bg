import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import "qrc:/components"
import "qrc:/custom_controls"

Page {
    id: root

    header: ToolBar {
        RowLayout {
            anchors{
                fill: parent
                leftMargin: 10
                rightMargin: 10
            }

            ComponentSizePanel {
                id: sizePanel
                Layout.fillHeight: true
                Layout.fillWidth: true
                onComponentHeightChanged: easel.component.height = sizePanel.componentHeight
                onComponentWidthChanged: easel.component.width = sizePanel.componentWidth
            }

            ToolSeparator {}

            ZoomLabel {
                id: zoomLabel
                Layout.fillHeight: true
                zoomValue: easel.currentScaleInPercent
            }
        }
    }

    RowLayout {
        anchors.fill: parent

        SidePanel {
            id: instrumentsPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
            z: 1
        }

        ComponentEasel {
            id: easel
            Layout.fillHeight: true
            Layout.fillWidth: true
            z: 0
        }

        SidePanel {
            id: templatesPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
            z: 1
        }
    }

    QtObject {
        id: internal
        readonly property int sidePanelInitialWidth: Math.round(
                                                         parent.width * 0.2)
    }
}
