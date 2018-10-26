import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12

import protomorph.sizelistmodel 1.0

import "../custom_controls"

Page {
    id: root

    header: ToolBar {
        RowLayout
        {
            ComboBox {
                id: cardSizes
                width: 110
                height: 40
                textRole: "sizeAsString"
                model: SizesListModel {
                    id: sizesListModel
                }
                onCurrentIndexChanged: {
                    var cardSize = sizesListModel.sizeByIndex(currentIndex);
                    card.width = cardSize.width
                    card.height = cardSize.height
                }
            }
        }
    }

    RowLayout {
        anchors.fill: parent

        SidePanel {
            id: instrumentsPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
        }

        ComponentEasel {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                anchors.centerIn: parent
                id: card
                color: "purple"
                radius: 20
            }
        }

        SidePanel {
            id: templatesPanel
            Layout.fillHeight: true
            Layout.preferredWidth: internal.sidePanelInitialWidth
        }
    }

    QtObject {
        id: internal
        readonly property int sidePanelInitialWidth: Math.round(Screen.width * 0.2)
    }
}
