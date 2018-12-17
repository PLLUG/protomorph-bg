import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import protomorph.sizelistmodel 1.0

RowLayout {
    id: root

    readonly property alias componentHeight: heightSpinbox.value
    readonly property alias componentWidth: widthSpinbox.value

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

    SizeSpinBox {
        id: widthSpinbox
        Layout.fillHeight: true
    }

    SizeSpinBox {
        id: heightSpinbox
        Layout.fillHeight: true
    }
}
