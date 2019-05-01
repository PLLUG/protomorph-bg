import QtQuick 2.12

import QuickFlux 1.1

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4

import protomorph.enums 1.0
import protomorph.svgimage 1.0

import "qrc:/stores"
import "qrc:/custom_controls"

Control {
    id: root

    background: ComponentBackground {}

    contentItem: Repeater {
        id: decorationsRepeater
        model: ComponentDecorationsModel

        BasicSelectableDecoration  {
            id: decorationManipulator

            x: decorationStoreRole.decorationPosition.x
            y:decorationStoreRole.decorationPosition.y
            width: decorationStoreRole.decorationSize.width
            height: decorationStoreRole.decorationSize.height

            z: zOrderRole
            selected: selectedRole
            visible: visibleRole

            onPressed: {
                if (decorationManipulator.containsPress && !decorationManipulator.selected) {
                    selectedRole = true
                }
            }

            contentItem:{
                switch(typeRole) {
                case Enums.DECORATION_GAME_ICON:
                    return gameIconComponent
                }
            }

            Component {
                id: gameIconComponent

                SvgPainter {
                    content: decorationStoreRole.iconData
                    imageColor: decorationStoreRole.foregroundColor
                }
            }

            Component.onCompleted: decorationManipulator.forceActiveFocus()
        }
    }

    function clearDecorationSelection() {
        ComponentDecorationsModel.clearDecorationSelection()
    }
}
