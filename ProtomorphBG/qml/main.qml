import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5

import "qrc:/components"
import "qrc:/screens"

ApplicationWindow {
    title: Qt.application.name

    visible: true
    width: 1024
    height: 768

    menuBar: MainMenuBar {
        id: mainToolBar
    }

    ComponentEditorScreen {
        anchors.fill: parent
    }
}
