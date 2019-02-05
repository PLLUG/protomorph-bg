import QtQuick 2.12

import QuickFlux 1.1

import protomorph.componenteditorstore 1.0

Store {
    id: root
    bindSource: AppDispatcher

    property alias componentEditorStore: componentEditorStore
    property alias systemStore: systemStore

    ComponentEditorStore{
        id: componentEditorStore
    }

    SystemStore {
        id: systemStore
    }
}
