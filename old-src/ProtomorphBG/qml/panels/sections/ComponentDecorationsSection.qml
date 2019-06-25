import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import FontAwesome 1.0

import protomorph.uisizeadapter 1.0

import "qrc:/custom_controls"

ListView {
    id: root

    boundsMovement: Flickable.StopAtBounds
    clip: true
    model: ComponentDecorationsModel
    spacing: UISizeAdapter.calculateSize(2)
    implicitHeight: (internal.delegateDefaultHeight + root.spacing) * (count < internal.maxVisibleItems ? count : internal.maxVisibleItems)

    delegate: ItemDelegate {
        height: internal.delegateDefaultHeight
        width: parent.width
        padding: 0

        contentItem: RowLayout {
            spacing: 0

            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignVCenter
                text: nameRole
                elide: Label.ElideRight
                verticalAlignment: Label.AlignVCenter
                wrapMode: Label.WordWrap
            }

            ToolButton {
                id: decorationVisibilityBtn
                Layout.preferredHeight: internal.buttonDefaultSideSize
                Layout.preferredWidth: internal.buttonDefaultSideSize
                Layout.alignment: Qt.AlignVCenter
                text: visibleRole ? FontAwesome.icon.eye_slash : FontAwesome.icon.eye
                font{
                    family: FontAwesome.fontAwesomeFreeSolid
                    styleName: FontAwesome.fontAwesomeStyleNameSolid
                }

                onPressed: visibleRole = !visibleRole
            }

            ToolButton {
                id: moveDecorationUpBtn
                Layout.preferredHeight: internal.buttonDefaultSideSize
                Layout.preferredWidth: internal.buttonDefaultSideSize
                Layout.alignment: Qt.AlignVCenter
                text: FontAwesome.icon.angle_double_up
                enabled: index !== 0
                font{
                    family: FontAwesome.fontAwesomeFreeSolid
                    styleName: FontAwesome.fontAwesomeStyleNameSolid
                }

                onPressed: zOrderRole = zOrderRole - 1
            }

            ToolButton {
                id: moveDecorationDownBtn
                Layout.preferredHeight: internal.buttonDefaultSideSize
                Layout.preferredWidth: internal.buttonDefaultSideSize
                Layout.alignment: Qt.AlignVCenter
                text: FontAwesome.icon.angle_double_down
                enabled: index !== root.count - 1
                font{
                    family: FontAwesome.fontAwesomeFreeSolid
                    styleName: FontAwesome.fontAwesomeStyleNameSolid
                }

                onPressed: zOrderRole = zOrderRole + 1
            }

            ToolButton {
                id: removeDecorationBtn
                Layout.preferredHeight: internal.buttonDefaultSideSize
                Layout.preferredWidth: internal.buttonDefaultSideSize
                Layout.alignment: Qt.AlignVCenter
                text: FontAwesome.icon.trash
                font{
                    family: FontAwesome.fontAwesomeFreeSolid
                    styleName: FontAwesome.fontAwesomeStyleNameSolid
                }

                onPressed: ComponentDecorationsModel.removeDecoration(index)
            }
        }

        onPressed: selectedRole = !selectedRole
    }

    ScrollIndicator.vertical: ScrollIndicator{}

    QtObject {
        id: internal
        readonly property int buttonDefaultSideSize: UISizeAdapter.calculateSize(20)
        readonly property int delegateDefaultHeight: UISizeAdapter.calculateSize(30)
        readonly property int maxVisibleItems: 5
    }
}
