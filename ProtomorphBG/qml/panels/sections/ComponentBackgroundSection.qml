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
        id: backgroundType

        Layout.fillWidth: true
        Layout.minimumHeight: UISizeAdapter.calculateSize(30)

        textRole: "translated"
        model: BackgroundConstants.backgroundTypes
    }

    Loader {
        Layout.fillWidth: true

        sourceComponent: {
            switch(BackgroundConstants.backgroundTypes[backgroundType.currentIndex].type) {
            case Enums.BACKGROUND_COLOR:
                return colorPickerComponent
            case Enums.BACKGROUND_GRADIENT:
                return gradientPickerComponent
            case Enums.BACKGROUND_IMAGE:
                return imagePickerComponent
            }
        }

        Component {
            id: colorPickerComponent
            ColorPickerButton {
                onBackgroundColorChanged: ApplicationActions.changeComponentBackgroundColor (backgroundColor)
            }
        }

        Component {
            id: gradientPickerComponent
            GradientPresetsPicker {
                onGradientChanged: ApplicationActions.changeComponentBackgroundGradient(gradient)
            }
        }

        Component {
            id: imagePickerComponent
            ImagePicker {
                onImagePathChanged: ApplicationActions.changeComponentBackgroundImage(imagePath)
            }
        }
    }
}
