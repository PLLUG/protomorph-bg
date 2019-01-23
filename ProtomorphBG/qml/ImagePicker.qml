import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.4

import Qt.labs.platform 1.0

import FontAwesome 1.0

import protomorph.qmlhelper 1.0

ColumnLayout{
    id: root

    property alias imagePath: filePath.selectedFilePath

    RowLayout {
        Layout.fillWidth: true

        TextField {
            id: filePath
            Layout.fillHeight: true
            Layout.fillWidth: true
            rightInset: 0

            property url selectedFilePath
            property url lastOpenedFolderPath: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]

            text: selectedFilePath ? QmlHelper.urlToDisplayString(selectedFilePath) : ""
            autoScroll: true
            inputMethodHints: Qt.ImhUrlCharactersOnly
            placeholderText: qsTr("Select background image...")
        }

        ToolButton {
            Layout.fillHeight: true
            Layout.minimumWidth: parent.height
            Layout.maximumWidth: parent.height

            font {
                family: FontAwesome.fontAwesomeFreeSolid
                styleName: FontAwesome.fontAwesomeStyleNameSolid
            }

            text:FontAwesome.icon.file_image

            onClicked: {
                var dialog = imagePickerDialogComponent.createObject(mainWindow)
                dialog.open()
            }

            Component {
                id: imagePickerDialogComponent

                FileDialog {
                    title: qsTr("Choose image")
                    modality: Qt.WindowModal
                    fileMode: FileDialog.OpenFile
                    nameFilters: ["All Picture Files (*.png *.jpg *.bmp *.svg)"]
                    folder: filePath.lastOpenedFolderPath

                    acceptLabel : qsTr("Select")

                    onAccepted: {
                        filePath.selectedFilePath = file
                        filePath.cursorPosition = 0
                        filePath.lastOpenedFolderPath = folder
                        destroy()
                    }
                    onRejected: destroy()
                }
            }
        }
    }

    Loader {
        Layout.fillWidth: true
        Layout.minimumHeight: item ? (item.sourceSize.height / item.sourceSize.width) * root.width : -1
        Layout.maximumHeight: item ? (item.sourceSize.height / item.sourceSize.width) * root.width : -1
        active: filePath.text.length !== 0
        sourceComponent: Image {
            fillMode: Image.PreserveAspectFit
            source: filePath.selectedFilePath
            asynchronous: true
            cache: false
            mipmap: true
            smooth: false
        }
    }

    Item {
        Layout.fillHeight: true
    }
}
