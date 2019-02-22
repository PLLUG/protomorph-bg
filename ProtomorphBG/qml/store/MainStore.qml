import QtQuick 2.12

import QuickFlux 1.1

import protomorph.componenteditorstore 1.0

Store {
    id: root
    bindSource: AppDispatcher

    property Store componentEditorStore: ComponentEditorStore
    property alias systemStore: systemStore

    SystemStore {
        id: systemStore
    }
}
