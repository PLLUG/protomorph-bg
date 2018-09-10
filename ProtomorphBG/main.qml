import QtQuick 2.11
import QtQuick.Window 2.11

import QtQuick.Controls 2.4

import protomorph.sizelistmodel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Protomorph BG")

    Grid {
        id: grid
        anchors.fill: parent

        ComboBox {
            id: comboBox
            width: 110
            height: 40
            textRole: "sizeAsString"
            model: SizesListModel {
                id: sizesListModel
            }
            onCurrentIndexChanged: {
                var cardSize = sizesListModel.sizeByIndex(currentIndex);
                print(cardSize)
                card.width = cardSize.width
                card.height = cardSize.height
            }
        }

        Pane {
            id: pane
            width: 300
            height: 300


            Rectangle {
                id: card
                color: "red"
                radius: 20
            }
        }
    }
}
