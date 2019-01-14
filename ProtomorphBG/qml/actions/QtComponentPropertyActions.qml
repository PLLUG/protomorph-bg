pragma Singleton
import QtQuick 2.12
import QtQuick.Controls 2.4

import FontAwesome 1.0

ActionGroup {
    id: root

    Action {
        id: changeBackgroundAction
        onTriggered: ApplicationActions.changeComponentBackground()
        text: FontAwesome.palette
        property string tooltipText: qsTr("Add Image")
    }
}
