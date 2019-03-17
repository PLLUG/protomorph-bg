import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import FontAwesome 1.0

import protomorph.uisizeadapter 1.0

import "qrc:/custom_controls"

ColumnLayout {
    id: root

    spacing: 0

    ListView {
        id: decorationListView

        Layout.fillWidth: true
        Layout.preferredHeight: count * (spacing + internal.delegateDefaultHeight)

        spacing: UISizeAdapter.calculateSize(2)

        model: ComponentDecorationsModel
        boundsMovement: Flickable.StopAtBounds
        clip: true

        delegate: ItemDelegate {
            height: internal.delegateDefaultHeight
            width: parent.width

            contentItem: RowLayout {
                spacing: 0
                Label {
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignVCenter
                    text: "%1. ".arg(zOrderRole + 1)
                    verticalAlignment: Label.AlignVCenter
                    horizontalAlignment: Label.AlignLeft
                }

                Label {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                    text: nameRole
                    elide: Label.ElideRight
                    verticalAlignment: Label.AlignVCenter
                    horizontalAlignment: Label.AlignLeft
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
                    enabled: index !== decorationListView.count - 1
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

        ScrollBar.vertical: ScrollBar { policy: ScrollBar.AsNeeded }
        ScrollBar.horizontal: ScrollBar { policy: ScrollBar.AlwaysOff }
    }

    QtObject {
        id: internal
        readonly property int delegateDefaultHeight: UISizeAdapter.calculateSize(30)
        readonly property int buttonDefaultSideSize: UISizeAdapter.calculateSize(20)
    }
}
