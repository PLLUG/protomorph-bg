import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5
import QtQuick.Layouts 1.4

import protomorph.uisizeadapter 1.0

import FontAwesome 1.0

ToolBar {
    id: root

    property var actions: []
    property int orientation: Qt.Horizontal

    background: Rectangle {
        color: Material.accent
        opacity: 0.5
    }

    contentItem: Loader {
        active: root.visible
        sourceComponent: orientation === Qt.Horizontal ? rowLayoutComponent : columnLayoutComponent
    }

    Component{
        id: rowLayoutComponent
        RowLayout {
            id: rowLayout
            anchors.fill: parent
            Component.onCompleted: iconsListComponent.createObject(rowLayout)
        }
    }

    Component{
        id: columnLayoutComponent
        ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            Component.onCompleted: iconsListComponent.createObject(columnLayout)
        }
    }

    Component {
        id: iconsListComponent

        Repeater {
            id: iconsList
            model: actions

            ToolButton {
                id: toolButton
                action: modelData
                font {
                    family: modelData.fontFamily
                    pointSize: 20
                }

                ToolTip {
                    parent: toolButton
                    anchors.centerIn: parent
                    bottomMargin: orientation === Qt.Horizontal ? parent.height : 0
                    leftMargin: orientation === Qt.Vertical ? parent.width : 0
                    visible: modelData.tooltipText && hovered
                    text: modelData.tooltipText ? modelData.tooltipText : ""

                    background: Rectangle {
                        color: Material.background
                        border.width: 1
                        border.color: Material.primary
                    }
                }
            }
        }
    }
}
