import QtQuick 2.12
import QtQuick.Controls 2.5

import QuickFlux 1.1

import "qrc:/actions"

Store {
    id: root

    Filter {
        type: ActionTypes.startApp
        onDispatched: mainWindow.visibility = ApplicationWindow.Maximized
    }

    Filter {
        type: ActionTypes.quitApp
        onDispatched: Qt.quit()
    }
}

