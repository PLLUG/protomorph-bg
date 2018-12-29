import QtQuick 2.12
import QtQuick.Controls 2.5
import QuickFlux 1.0

import "qrc:/actions"

StoreWorker {
    id: worker

    Filter {
        type: ActionTypes.startApp
        onDispatched: {
            mainWindow.visibility = ApplicationWindow.Maximized
        }
    }

    Filter {
        type: ActionTypes.quitApp
        onDispatched: {
            Qt.quit();
        }
    }
}
