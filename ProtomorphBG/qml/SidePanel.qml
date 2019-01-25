import QtQuick 2.12

import QtQml.Models 2.12
import QtQuick.Layouts 1.4
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5

import "qrc:/actions"

Page {
    id: root
    padding: 0

    function addPanelContentItem(contentItemUrl, descriptionText, fontAwesomeSymbol, fontAwesomeFamily, fontAwesomeStyleName) {
        panelsModel.append({"contentItemUrl" : contentItemUrl
                               , "fontAwesome": {
                                   "symbol": fontAwesomeSymbol,
                                   "family": fontAwesomeFamily,
                                   "styleName": fontAwesomeStyleName
                               }
                               , "descriptionText": descriptionText
                           })
    }

    header: TabBar {
        id: tabBar

        Repeater {
            model: ListModel{
                id: panelsModel
                dynamicRoles: true
            }

            TabButton {
                text: fontAwesome.symbol
                font{
                    family: fontAwesome.family
                    styleName: fontAwesome.styleName
                }

                ToolTip {
                    text: descriptionText
                    visible: text.length > 0 && hovered

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
                source: contentItemUrl
                anchors.fill: parent
            }
        }
    }
}
