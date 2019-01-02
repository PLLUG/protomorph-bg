pragma Singleton
import QtQuick 2.12
import QtQuick.Controls 2.4

import FontAwesome 1.0

ActionGroup {
    id: root

    Action {
        id: addImageAction
        onTriggered: ApplicationActions.addImage()
        text: FontAwesome.image
        property string tooltipText: qsTr("Add Image")
    }

    Action {
        id: addIconAction
        onTriggered: ApplicationActions.addIcon()
        text: FontAwesome.fileImageO
        property string tooltipText: qsTr("Add Icon")
    }

    Action {
        id: addShapeAction
        onTriggered: ApplicationActions.addShape()
        text: FontAwesome.cube
        property string tooltipText: qsTr("Add Shape")
    }

    Action {
        id: addTextAction
        onTriggered: ApplicationActions.addText()
        text: FontAwesome.font
        property string tooltipText: qsTr("Add Text")
    }
}
