import QtQuick 2.12

import QuickFlux 1.1

import protomorph.componenteditorstoretemplate 1.0
import protomorph.enums 1.0

import "qrc:/actions"

ComponentEditorStoreTemplate {
    id: root

    Filter {
        type: ActionTypes.changeComponentHeight
        onDispatched: root.height = message.height
    }

    Filter {
        type: ActionTypes.changeComponentWidth
        onDispatched: root.width = message.width
    }

    Filter {
        type: ActionTypes.changeComponentBackgroundColor
        onDispatched: root.background = internal.createBackgroundProperties(Enums.BACKGROUND_COLOR, message.backgroundColor)
    }

    Filter {
        type: ActionTypes.changeComponentBackgroundGradient
        onDispatched: root.background = internal.createBackgroundProperties(Enums.BACKGROUND_GRADIENT, message.backgroundGradient)
    }

    Filter {
        type: ActionTypes.changeComponentBackgroundImage
        onDispatched: root.background = internal.createBackgroundProperties(Enums.BACKGROUND_IMAGE, message.backgroundImagePath)
    }

    Filter {
        type: ActionTypes.addIcon
        onDispatched: print("addIcon")
    }

    Filter {
        type: ActionTypes.addImage
        onDispatched: print("addImage")
    }

    Filter {
        type: ActionTypes.addShape
        onDispatched: print("addShape")
    }

    Filter {
        type: ActionTypes.addText
        onDispatched: print("addText")
    }

    QtObject {
        id: internal

        function createBackgroundProperties(selectedType, selectedValue) {
            return {"type": selectedType, "value": selectedValue}
        }
    }
}
