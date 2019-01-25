import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4

import Qt.labs.platform 1.0

import protomorph.uisizeadapter 1.0

ToolButton{
    id: root

    property alias backgroundColor: buttonColor.color
    implicitHeight: UISizeAdapter.calculateSize(30)

    background: Rectangle {
        id: buttonColor
        border{
            color: Material.background
            width: UISizeAdapter.calculateSize(2)
        }
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
