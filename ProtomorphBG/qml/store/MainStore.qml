pragma Singleton
import QtQuick 2.12

import QuickFlux 1.1

Store {
    id: root
    bindSource: AppDispatcher

    property Store systemStore: null
    property alias componentEditorStore: componentEditorStore

    ComponentEditorStore {
        id: componentEditorStore
    }
}
