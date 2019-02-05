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
        id: mainMenuBar
    }

    StackView {
        anchors.fill: parent
        initialItem: ComponentEditorScreen {
        }
    }

    MainStore {
        id: mainStore
    }
}
