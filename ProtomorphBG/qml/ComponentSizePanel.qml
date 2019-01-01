import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import protomorph.sizelistmodel 1.0

import "qrc:/actions"
import "qrc:/custom_controls"

RowLayout {
    id: root

    ComboBox {
        id: cardSizes

        Layout.fillWidth: true
        Layout.fillHeight: true

        textRole: "sizeAsString"
        displayText: currentText + " mm"

        model: SizesListModel {
            id: sizesListModel
        }

        onCurrentIndexChanged: {
            var cardSize = sizesListModel.sizeByIndex(cardSizes.currentIndex)
            widthSpinbox.value = cardSize.width
            heightSpinbox.value = cardSize.height
        }
    }

    ToolSeparator {}

    SizeSpinBox {
        id: widthSpinbox
        Layout.fillHeight: true
        onValueChanged: ApplicationActions.changeComponentWidth(widthSpinbox.value)
    }

    ToolSeparator {}

    SizeSpinBox {
        id: heightSpinbox
        Layout.fillHeight: true
        onValueChanged: ApplicationActions.changeComponentHeight(heightSpinbox.value)
    }
}
