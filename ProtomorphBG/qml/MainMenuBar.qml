import QtQuick 2.12

import QtQuick.Controls 2.5

MenuBar {
    Menu {
        title: qsTr("&File")
        MenuSeparator {
        }
        Action {
            text: qsTr("&Quit")
        }
    }
    Menu {
        title: qsTr("&Help")
        Action {
            text: qsTr("&About")
        }
    }
}
