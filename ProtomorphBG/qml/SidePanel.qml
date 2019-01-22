import QtQuick 2.12

import QtQml.Models 2.12
import QtQuick.Layouts 1.4
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5

import "qrc:/actions"
import "qrc:/panels"

Page {
    id: root
    padding: 0

    property ListModel panelsModel: ListModel{
        dynamicRoles: true
    }

    header: TabBar {
        id: tabBar

        Repeater {
            model: panelsModel

            TabButton {
                text: fontAwesome.symbol
                font{
                    pointSize: 20
                    family: fontAwesome.family
                    styleName: fontAwesome.styleName
                }

                ToolTip {
                    text: toolTipText
                    visible: toolTipText && hovered

                    background: Pane {
                        Material.elevation: 3

                        Rectangle {
                            color: Material.background
                        }
                    }
                }
            }
        }
    }

    contentItem: StackLayout {
        id: stackLayout
        currentIndex: tabBar.currentIndex

        Repeater {
            model: panelsModel

            Loader {
                source: url
                anchors.fill: parent
            }
        }
    }
}
