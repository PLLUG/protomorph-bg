import QtQuick 2.12

import QuickFlux 1.1

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtGraphicalEffects 1.12

import protomorph.enums 1.0
import protomorph.svgimage 1.0

import "qrc:/stores"
import "qrc:/custom_controls"

Item {
    id: root

    Loader {
        id: backgroundLoader
        sourceComponent: rectBackgroundComponent
        anchors.fill: parent

        Binding {
            target: backgroundLoader.item
            value: mainStore.componentEditorStore.borderWidth
            property: "border.width"
        }

        Binding {
            target: backgroundLoader.item
            value: mainStore.componentEditorStore.borderColor
            property: "border.color"
        }

        Connections {
            enabled: root.visible
            target: mainStore.componentEditorStore
            onBackgroundTypeChanged: {
                backgroundLoader.sourceComponent = undefined
                switch(backgroundType) {
                case Enums.BACKGROUND_COLOR:
                    backgroundLoader.sourceComponent = rectBackgroundComponent
                    backgroundLoader.item.color = mainStore.componentEditorStore.backgroundValue
                    break
                case Enums.BACKGROUND_GRADIENT:
                    backgroundLoader.sourceComponent = rectBackgroundComponent
                    backgroundLoader.item.gradient = mainStore.componentEditorStore.backgroundValue
                    break
                case Enums.BACKGROUND_IMAGE:
                    backgroundLoader.sourceComponent = imageBackgroundComponent
                    backgroundLoader.item.source = mainStore.componentEditorStore.backgroundValue
                    break
                case Enums.BACKGROUND_NONE:
                default:
                    backgroundLoader.sourceComponent = rectBackgroundComponent
                    break
                }
            }

            onBackgroundValueChanged: {
                switch(mainStore.componentEditorStore.backgroundType) {
                case Enums.BACKGROUND_COLOR:
                    backgroundLoader.item.color = mainStore.componentEditorStore.backgroundValue
                    break
                case Enums.BACKGROUND_GRADIENT:
                    backgroundLoader.item.gradient = mainStore.componentEditorStore.backgroundValue
                    break
                case Enums.BACKGROUND_IMAGE:
                    backgroundLoader.item.source = mainStore.componentEditorStore.backgroundValue
                    break
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

            Item {
                property alias border: borderRect.border
                property alias source: backgroundImage.source

                Image {
                    id: backgroundImage
                    anchors.fill: parent
                    fillMode: Image.PreserveAspectCrop
                    cache: false
                    mipmap: true
                    smooth: false
                }

                Rectangle {
                    id: borderRect
                    color: "transparent"
                    anchors.fill: parent
                    visible: false
                }

                OpacityMask {
                    anchors.fill: parent
                    source: borderRect
                    maskSource: backgroundImage
                }
            }
        }
    }

    Repeater {
        model: mainStore.componentEditorStore.componentDecorationsModel()

        BasicSelectableDecoration  {

            property var decorationStore: decorationStoreRole
            x: decorationStore.decorationPosition.x
            y:decorationStore.decorationPosition.y
            width: decorationStore.decorationSize.width
            height: decorationStore.decorationSize.height

            contentItem:{
                switch(typeRole) {
                case Enums.DECORATION_GAME_ICON:
                    return gameIconComponent
                }
            }

            Component {
                id: gameIconComponent

                SvgPainter {
                    content: decorationStore.iconData
                    imageColor: decorationStore.foregroundColor
                }
            }
        }
    }
}
