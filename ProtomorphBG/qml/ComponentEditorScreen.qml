import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12

import protomorph.uisizeadapter 1.0

import "qrc:/actions"
import "qrc:/components"
import "qrc:/custom_controls"

Page {
    id: root

    header: ToolBar {
        RowLayout {
            anchors{
                fill: parent
                leftMargin: UISizeAdapter.calculateSize(10)
                rightMargin: UISizeAdapter.calculateSize(10)
            }

            ComponentSizePanel {
                id: sizePanel
                Layout.fillHeight: true
            }

            ToolSeparator {}

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            ZoomLabel {
                id: zoomLabel
                Layout.fillHeight: true
                zoomValue: easel.currentScaleInPercent
            }
        }
    }

    RowLayout {
        anchors.fill: parent

        ComponentEasel {
            id: easel
            Layout.fillHeight: true
            Layout.fillWidth: true
            z: 0

            ToolsPanel {
                id: propertiesPanel
                actions: ComponentPropertyActions.actions
                orientation: Qt.Horizontal

                anchors {
                    horizontalCenter: easel.horizontalCenter
                    bottom: easel.bottom
                }
            }
        }

        SidePanel {
            id: templatesPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
            z: 1
        }
    }

    ToolsPanel {
        id: instrumentsPanel
        actions: ComponentDecorationActions.actions
        orientation: Qt.Vertical
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
        }
    }

    QtObject {
        id: internal
        readonly property int sidePanelInitialWidth: Math.round(
                                                         Screen.width * 0.2)
    }
}
