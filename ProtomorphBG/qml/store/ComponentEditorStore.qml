import QtQuick 2.12

import QuickFlux 1.1

import protomorph.componenteditorstoretemplate 1.0
import protomorph.enums 1.0

import "qrc:/actions"
import "qrc:/components"

ComponentEditorStoreTemplate {
    id: root

    property var mainWindow

    Filter {
        type: ActionTypes.changeComponentHeight
        onDispatched: root.height = message.height
    }

    Filter {
        type: ActionTypes.changeComponentWidth
        onDispatched: root.width = message.width
    }

    Filter {
        type: ActionTypes.changeComponentBackground
        onDispatched: root.background = message.backgroundPropertiesObj
    }

    Filter {
        type: ActionTypes.changeComponentBorders
        onDispatched: root.borders = message.bordersPropertiesObj
    }

    Filter {
        type: ActionTypes.addIcon
        onDispatched: {
            var gameIconsView = gameIconsViewComponent.createObject(mainWindow)
            gameIconsView.open()
        }
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

    Component {
        id: gameIconsViewComponent
        GameIconsView {
            anchors.centerIn: parent
            width: parent.width/2; height: width

        }
    }
}
