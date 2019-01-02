import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12

import FontAwesome 1.0

import "qrc:/actions"
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
            id: templatesPanel
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
            id: instrumentsPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
            z: 1

            ListView {
                anchors.fill: parent
                model: ComponentDecorationActions.actions

                delegate: Button {
                    action: modelData
                    font.family: FontAwesome.fontFamily
                    font.pointSize: 20
                    ToolTip.visible: hovered
                    ToolTip.text: modelData.tooltipText
                }
            }
        }
    }

    QtObject {
        id: internal
        readonly property int sidePanelInitialWidth: Math.round(
                                                         Screen.width * 0.2)
    }
}
