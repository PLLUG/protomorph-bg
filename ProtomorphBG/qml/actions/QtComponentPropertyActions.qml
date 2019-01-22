pragma Singleton
import QtQuick 2.12
import QtQuick.Controls 2.4

import FontAwesome 1.0

ActionGroup {
    id: root

    Action {
        id: chooseComponentBackgroundAction
        onTriggered: ApplicationActions.chooseComponentBackground
        text: FontAwesome.icon.paint_roller
        property string tooltipText: qsTr("Change Background")
        property string fontFamily: FontAwesome.fontAwesomeFreeSolid
        property string styleName: FontAwesome.fontAwesomeStyleNameSolid
    }

    Action {
        id: changeComponentBordersAction
        onTriggered: ApplicationActions.changeComponentBorders()
        text: FontAwesome.icon.square
        property string tooltipText: qsTr("Change Borders")
        property string fontFamily: FontAwesome.fontAwesomeFreeRegular
        property string styleName: FontAwesome.fontAwesomeStyleNameRegular
    }
}
