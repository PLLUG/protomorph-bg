import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4

import FontAwesome 1.0

Page {
    id: root

    property bool expanded: true
    property Component contentComponent: null

    clip: true
    padding: 16
    topPadding: 0

    background: Rectangle {
        color: Material.primary
    }

    header: RowLayout {
        spacing: 0

        Label {
            text: root.title
            font.bold: true
            Layout.leftMargin: root.padding
        }

        Item {
            Layout.fillWidth: true
        }

        ToolButton {
            text: expanded ? FontAwesome.icon.angle_up : FontAwesome.icon.angle_down
            font.family: FontAwesome.fontAwesomeFreeSolid
            focusPolicy: Qt.NoFocus

            Layout.leftMargin: -8
            Layout.preferredWidth: implicitHeight

            onClicked: expanded = !expanded
        }
    }

    contentItem: Loader {
        active: contentComponent !== null
        width: root.width; height: root.height - root.header.height;
        sourceComponent: contentComponent
    }
}
