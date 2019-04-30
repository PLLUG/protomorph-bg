import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4

import FontAwesome 1.0

Page {
    id: root

    readonly property int paddingValue: 16

    clip: true
    horizontalPadding: paddingValue
    topPadding: 0; bottomPadding: root.contentItem.implicitHeight > 0 ? paddingValue : 0
    implicitHeight: expandButton.checked  ? root.header.implicitHeight + root.contentItem.implicitHeight + root.bottomPadding
                                          : root.header.implicitHeight

    header: RowLayout {
        spacing: 0

        Label {
            Layout.leftMargin: paddingValue
            font.bold: true
            text: root.title
        }

        Item { Layout.fillWidth: true }

        ToolButton {
            id: expandButton
            Layout.leftMargin: -(paddingValue / 2)
            Layout.preferredWidth: implicitHeight
            checkable: true
            checked: true

            focusPolicy: Qt.NoFocus
            font {
                family: FontAwesome.fontAwesomeFreeSolid
                styleName: FontAwesome.fontAwesomeStyleNameSolid
            }
            text: expandButton.checked ? FontAwesome.icon.angle_up : FontAwesome.icon.angle_down
        }
    }

    background: Rectangle { color: Material.primary }
}
