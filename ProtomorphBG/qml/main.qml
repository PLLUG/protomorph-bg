import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Window 2.12

import "qrc:/adapters"
import "qrc:/components"
import "qrc:/screens"

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

    StoreAdapter {
        id: storeAdapter
    }
}
