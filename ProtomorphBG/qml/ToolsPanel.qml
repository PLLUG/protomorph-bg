import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5
import QtQuick.Layouts 1.4

ToolBar {
    id: root

    property var actions: []
    property int orientation: Qt.Horizontal
    property bool enableTooltips: true
    Material.elevation: 3

    contentItem: Loader {
        active: root.visible
        sourceComponent: orientation === Qt.Horizontal ? rowLayoutComponent : columnLayoutComponent
    }

    Component{
        id: rowLayoutComponent
        RowLayout {
            id: rowLayout
            Component.onCompleted: iconsListComponent.createObject(rowLayout)
        }
    }

    Component{
        id: columnLayoutComponent
        ColumnLayout {
            id: columnLayout
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
                    styleName: modelData.styleName
                }

                Loader {
                    active: enableTooltips && toolButton.hovered
                    sourceComponent: ToolTip {
                        parent: toolButton
                        anchors.centerIn: parent
                        bottomMargin: orientation === Qt.Horizontal ? 1.25 * parent.height : 0
                        leftMargin: orientation === Qt.Vertical ? 1.25 * parent.width : 0
                        topMargin: orientation === Qt.Horizontal ? 1.25 * parent.height : 0
                        rightMargin: orientation === Qt.Vertical ? 1.25 * parent.width : 0
                        visible: modelData.descriptionText && toolButton.hovered
                        text: modelData.descriptionText ? modelData.descriptionText : ""
                    }
                }
            }
        }
    }
}
