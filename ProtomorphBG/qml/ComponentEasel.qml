import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.5

import protomorph.enums 1.0
import protomorph.qmlhelper 1.0

import "qrc:/custom_controls"
import "qrc:/stores"

Page {
    id: root
    padding: 0

    background: Rectangle {
        color: Material.color(Material.BlueGrey, Material.Shade100)
    }

    contentItem: ZoomArea {
        id: easel

        Item {
            id: compomponentCanvas
            anchors.centerIn: parent
            height: MainStore.componentEditorStore.height
            width: MainStore.componentEditorStore.width

            Loader {
                id: backgroundLoader
                anchors.fill: parent

                sourceComponent: rectBackgroundComponent

                Binding {
                    target: backgroundLoader.item
                    value: easel.currentScale
                    property: "scale"
                }

                Connections {
                    enabled: root.visible
                    target: MainStore.componentEditorStore
                    onBackgroundChanged: {
                        backgroundLoader.sourceComponent = undefined
                        switch(background.type) {
                        case Enums.BACKGROUND_COLOR:
                            backgroundLoader.sourceComponent = rectBackgroundComponent
                            backgroundLoader.item.color = background.value
                            break
                        case Enums.BACKGROUND_GRADIENT:
                            backgroundLoader.sourceComponent = rectBackgroundComponent
                            backgroundLoader.item.gradient = background.value
                            break
                        case Enums.BACKGROUND_IMAGE:
                            backgroundLoader.sourceComponent = imageBackgroundComponent
                            backgroundLoader.item.source = background.value
                            break
                        case Enums.BACKGROUND_NONE:
                        default:
                            backgroundLoader.sourceComponent = rectBackgroundComponent
                            break
                        }
                    }
                }
            }

            Component {
                id: rectBackgroundComponent

                Rectangle {
                    color: Material.accent
                }
            }

            Component {
                id: imageBackgroundComponent

                Image {
                    fillMode: Image.PreserveAspectCrop
                    asynchronous: true
                    cache: false
                    mipmap: true
                    smooth: false
                }
            }
        }
    }

    footer: Page {
        id: statusBar
        padding: 0

        header: ToolSeparator {
            orientation: Qt.Horizontal
            horizontalPadding: 0
            verticalPadding: 0
        }

        contentItem: RowLayout {
            id: statusBarLayout
            spacing: 0

            Item {
                Layout.fillWidth: true
            }

            ZoomLabel {
                id: zoomLabel
                zoomValue: easel.currentScaleInPercent
                Layout.fillHeight: true
                Layout.minimumWidth: zoomLabel.implicitWidth
                Layout.margins: 10
            }
        }
    }
}
