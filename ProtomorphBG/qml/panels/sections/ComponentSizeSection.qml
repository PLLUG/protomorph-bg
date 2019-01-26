import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import protomorph.sizelistmodel 1.0
import protomorph.uisizeadapter 1.0

import "qrc:/actions"
import "qrc:/custom_controls"

ColumnLayout {
    id: root

    ComboBox {
        id: cardSizes
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight

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
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        onValueChanged: ApplicationActions.changeComponentWidth(widthSpinbox.value)
    }

    SizeSpinBox {
        id: heightSpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        onValueChanged: ApplicationActions.changeComponentHeight(heightSpinbox.value)
    }

    QtObject {
        id: internal
        readonly property real componentsDefaultHeight: UISizeAdapter.calculateSize(30)
    }
}
