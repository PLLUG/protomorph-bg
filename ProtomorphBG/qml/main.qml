import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Window 2.12

import "qrc:/components"
import "qrc:/screens"

ApplicationWindow {
    title: Qt.application.name

    visible: true
    visibility: ApplicationWindow.Maximized

    width: Screen.width
    height: Screen.height

    menuBar: MainMenuBar {
        id: mainToolBar
    }

    ComponentEditorScreen {
        anchors.fill: parent
    }
}
