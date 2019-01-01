import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Window 2.12

import QuickFlux 1.0

import "qrc:/components"
import "qrc:/screens"

import "qrc:/stores"

ApplicationWindow {
    id: mainWindow
    title: Qt.application.name

    width: Screen.width
    height: Screen.height

    menuBar: MainMenuBar {
        id: mainToolBar
    }

    ComponentEditorScreen {
        anchors.fill: parent
    }

    SystemStore {
        id: systemStore
        bindSource: AppDispatcher
        Component.onCompleted: MainStore.systemStore = systemStore
    }
}
