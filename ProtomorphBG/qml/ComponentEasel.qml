import QtQuick 2.12

import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12
import QtQuick.Controls.Material 2.5

import "qrc:/custom_controls"
import "qrc:/stores"

ZoomArea {
    id: root

    Rectangle {
        id: internalComponent
        readonly property var componentEditorStore: MainStore.componentEditorStore
        color: componentEditorStore.backgroundColor
        anchors.centerIn: parent
        scale: root.currentScale
        height: componentEditorStore.height
        width: componentEditorStore.width
    }
}
