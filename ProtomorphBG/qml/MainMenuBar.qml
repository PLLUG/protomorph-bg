import QtQuick 2.12

import QtQuick.Controls 2.5

import "qrc:/actions"

MenuBar {
    Menu {
        title: qsTr("&File")
        MenuSeparator {
        }
        Action {
            text: qsTr("&Quit")
            onTriggered:  ApplicationActions.quitApp()
        }
    }
    Menu {
        title: qsTr("&Help")
        Action {
            text: qsTr("&About")
        }
    }
}
