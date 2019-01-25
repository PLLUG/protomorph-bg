import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12
import QtQml.Models 2.12

import protomorph.uisizeadapter 1.0
import FontAwesome 1.0

import "qrc:/actions"
import "qrc:/components"
import "qrc:/custom_controls"

Pane {
    id: root
    padding: 0

    contentItem: OldControls.SplitView {
        resizing: false

        handleDelegate: ToolSeparator {
            horizontalPadding: 0
            verticalPadding: 0
        }

        ComponentEasel {
            id: easel
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        SidePanel {
            id: templatesPanel
            Layout.fillHeight: true
            Layout.minimumWidth: internal.sidePanelInitialWidth
            Layout.maximumWidth: internal.sidePanelInitialWidth
            Layout.alignment: Qt.AlignTop

            Component.onCompleted: templatesPanel.addPanelContentItem("qrc:/panels/ComponentBasicPropertiesPanel.qml"
                                                                      , qsTr("Component properties")
                                                                      , FontAwesome.icon.cogs
                                                                      , FontAwesome.fontAwesomeFreeSolid
                                                                      , FontAwesome.fontAwesomeStyleNameSolid)
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
