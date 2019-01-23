pragma Singleton
import QtQuick 2.12
import QtQuick.Controls 2.4

import FontAwesome 1.0

ActionGroup {
    id: root

    BasicApplicationAction {
        id: addImageAction
        onTriggered: ApplicationActions.addImage()
        text: FontAwesome.icon.image
        descriptionText: qsTr("Add Image")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    BasicApplicationAction {
        id: addIconAction
        onTriggered: ApplicationActions.addIcon()
        text: FontAwesome.icon.star
        descriptionText: qsTr("Add Icon")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    BasicApplicationAction {
        id: addShapeAction
        onTriggered: ApplicationActions.addShape()
        text: FontAwesome.icon.shapes
        descriptionText: qsTr("Add Shape")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    BasicApplicationAction {
        id: addTextAction
        onTriggered: ApplicationActions.addText()
        text: FontAwesome.icon.font
        descriptionText: qsTr("Add Text")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }
}
