pragma Singleton
import QtQuick 2.12

import protomorph.enums 1.0

QtObject {
    id: root

    readonly property var backgroundTypes: [
        createBackgroundTypeObject(Enums.BACKGROUND_COLOR, qsTr("Color")),
        createBackgroundTypeObject(Enums.BACKGROUND_GRADIENT, qsTr("Gradient")),
        createBackgroundTypeObject(Enums.BACKGROUND_IMAGE, qsTr("Image")),
    ]

    function createBackgroundTypeObject(type, translatedLabel) {
        return {"type" : type, "translated" : translatedLabel}
    }

    function createBackgroundPropertiesObject(selectedType, selectedValue) {
        return {"type": selectedType, "value": selectedValue}
    }
}
