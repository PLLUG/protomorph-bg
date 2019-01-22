import QtQuick 2.12

import QtQuick.Controls 2.5

import FontAwesome 1.0

Label {
    id: root

    property int zoomValue: 100

    text: internal.textPattern.arg(root.zoomValue)
    font{
        family: FontAwesome.fontAwesomeFreeSolid
        styleName: FontAwesome.fontAwesomeStyleNameSolid
        pointSize: 15
    }
    horizontalAlignment: Label.AlignHCenter
    verticalAlignment: Label.AlignVCenter

    QtObject {
        id: internal
        readonly property string textPattern: "%1".arg(zoomIcon + " %1%")
        readonly property var zoomIcon: root.zoomValue == 100 ? FontAwesome.icon.search
                                                              : root.zoomValue > 100 ? FontAwesome.icon.search_plus
                                                                                     : FontAwesome.icon.search_minus
    }
}
