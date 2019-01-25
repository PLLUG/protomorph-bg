import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import protomorph.uisizeadapter 1.0

import "qrc:/actions"
import "qrc:/custom_controls"
import "qrc:/stores"

ColumnLayout {
    id: root

    Slider {
        id: borderWidthSpinbox
        Layout.fillWidth: true
        Layout.preferredHeight: internal.componentsDefaultHeight

        from: 0
        to: internal.sliderMaxValue

        onValueChanged: internal.notifyBordersChanged()
    }

    ColorPickerButton {
        id: borderColorPicker
        Layout.fillWidth: true
        Layout.preferredHeight: internal.componentsDefaultHeight
        showAlphaChannel: true
        onPickedColorChanged: internal.notifyBordersChanged()
    }

    QtObject {
        id: internal
        readonly property real componentsDefaultHeight: UISizeAdapter.calculateSize(30)
        readonly property real sliderMaxValue: MainStore.componentEditorStore.width / 2.0

        function notifyBordersChanged() {
            ApplicationActions.changeComponentBorders({"borderWidthInPixels": borderWidthSpinbox.value, "borderColor": borderColorPicker.pickedColor})
        }
    }
}
