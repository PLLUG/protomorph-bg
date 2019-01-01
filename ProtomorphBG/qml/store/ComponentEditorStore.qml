import QtQuick 2.12

import QuickFlux 1.1

import protomorph.componenteditorstoretemplate 1.0

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
}
