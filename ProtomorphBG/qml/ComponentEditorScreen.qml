import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12

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
            visible: false
        }

        ComponentEasel {
            id: easel
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        SidePanel {
            id: templatesPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
            visible: false
        }
    }

    QtObject {
        id: internal
        readonly property int sidePanelInitialWidth: Math.round(
                                                         Screen.width * 0.2)
    }
}