import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5

import "components"
import "screens"

ApplicationWindow {
    title: qsTr("Protomorph BG")

    visible: true
    width: 1024
    height: 768

    Material.theme: Material.Dark
    Material.accent: Material.Grey

    menuBar: MainMenuBar {
        id: mainToolBar
    }

    ComponentEditorScreen {
        anchors.fill: parent
    }
}
