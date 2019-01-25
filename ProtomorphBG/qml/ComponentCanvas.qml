import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4

import protomorph.enums 1.0

import "qrc:/stores"

Control {
    id: root

    background: Loader {
        id: backgroundLoader
        sourceComponent: rectBackgroundComponent

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
