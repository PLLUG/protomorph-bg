import QtQuick 2.12

import QtQml.Models 2.12
import QtQuick.Layouts 1.4
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5

import "qrc:/actions"

Page {
    id: root

    padding: 0

    property alias panelsModel: tabsRepeater.model

    header: TabBar {
        id: tabBar

        Repeater {
            id: tabsRepeater

            TabButton {
                enabled: tabEnabled
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

                        Rectangle { color: Material.background }
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
            }
        }
    }

    function createTabJsonObject(contentItemUrl, descriptionText, fontAwesomeSymbol, fontAwesomeFamily, fontAwesomeStyleName, tabEnabled) {
        return {
            "contentItemUrl" : contentItemUrl,
            "fontAwesome": {
                "symbol": fontAwesomeSymbol,
                "family": fontAwesomeFamily,
                "styleName": fontAwesomeStyleName },
            "descriptionText": descriptionText,
            "tabEnabled": tabEnabled
        }
    }
}
