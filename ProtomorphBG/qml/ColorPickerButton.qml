import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.4

import Qt.labs.platform 1.0

ToolButton{
    id: root

    property alias backgroundColor: buttonColor.color

    background: Rectangle {
        id: buttonColor
        border.width: 2
    }

    onClicked: {
        var dialog = colorPickerDialogComponent.createObject(mainWindow)
        dialog.color = buttonColor.color
        dialog.open()
    }

    Component {
        id: colorPickerDialogComponent

        ColorDialog {
            title: qsTr("Choose color")
            modality: Qt.WindowModal
            onAccepted: {
                root.background.color = color
                destroy()
            }
            onRejected: destroy()
        }
    }
}
