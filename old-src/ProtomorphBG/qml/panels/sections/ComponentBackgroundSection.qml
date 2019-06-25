import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import protomorph.enums 1.0
import protomorph.uisizeadapter 1.0

import "qrc:/actions"
import "qrc:/constants"
import "qrc:/custom_controls"

ColumnLayout {
    id: root

    ComboBox {
        id: backgroundTypeCombobox

        readonly property int backgroundType: model[currentIndex].type

        Layout.fillWidth: true
        Layout.minimumHeight: UISizeAdapter.calculateSize(30)

        textRole: "translated"
        model: BackgroundConstants.backgroundTypes
    }

    Loader {
        Layout.fillWidth: true

        sourceComponent: {
            switch(backgroundTypeCombobox.backgroundType) {
            case Enums.BACKGROUND_COLOR:
                return colorPickerComponent
            case Enums.BACKGROUND_GRADIENT:
                return gradientPickerComponent
            case Enums.BACKGROUND_IMAGE:
                return imagePickerComponent
            }
        }
    }

    Component {
        id: colorPickerComponent
        ColorPickerButton {
            onPickedColorChanged: internal.notifyBackgroundChanged(backgroundTypeCombobox.backgroundType, pickedColor)
        }
    }

    Component {
        id: gradientPickerComponent
        GradientPresetsPicker {
            onGradientChanged: internal.notifyBackgroundChanged(backgroundTypeCombobox.backgroundType, gradient)
        }
    }

    Component {
        id: imagePickerComponent
        ImagePicker {
            onImagePathChanged: internal.notifyBackgroundChanged(backgroundTypeCombobox.backgroundType, imagePath)
        }
    }

    QtObject {
        id: internal
        function notifyBackgroundChanged(backgroundType, backgroundValue) {
            var backgroundPropertiesObj = BackgroundConstants.createBackgroundPropertiesObject(backgroundType, backgroundValue)
            ApplicationActions.changeComponentBackground(backgroundPropertiesObj)
        }
    }
}
