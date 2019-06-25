pragma Singleton
import QtQuick 2.12
import QtQuick.Controls 2.4

import FontAwesome 1.0

ActionGroup {
    id: root

    readonly property alias addImage: addImageAction
    readonly property alias addIcon: addIconAction
    readonly property alias addShape: addShapeAction
    readonly property alias addText: addTextAction

    BasicApplicationAction {
        id: addImageAction
        text: FontAwesome.icon.image
        descriptionText: qsTr("Add Image")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    BasicApplicationAction {
        id: addIconAction
        text: FontAwesome.icon.star
        descriptionText: qsTr("Add Icon")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    BasicApplicationAction {
        id: addShapeAction
        text: FontAwesome.icon.shapes
        descriptionText: qsTr("Add Shape")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    BasicApplicationAction {
        id: addTextAction
        text: FontAwesome.icon.font
        descriptionText: qsTr("Add Text")
        fontFamily: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
    }
}
