import QtQuick 2.12

import protomorph.enums 1.0

BasicPanel {
    id: root

    property int currentSelectedDecorationIndex: -1

    Connections {
        target: ComponentDecorationsModel
        onDecorationSelectionChanged: {
            if (currentSelectedDecorationIndex === indexRow)
                return;

            root.clearPanel()

            if (indexRow > -1) {

                var decorationType = ComponentDecorationsModel.getByIndexAndRole(indexRow, "typeRole")
                switch(decorationType) {
                case Enums.DECORATION_GAME_ICON:
                    gameIconDecorationPanelModel(indexRow)
                    break;
                }
            }

            root.currentSelectedDecorationIndex = indexRow
        }
    }

    function gameIconDecorationPanelModel(index) {
        root.addCollapsibleSection(qsTr("Decoration size and position"), "qrc:/panels/sections/DecorationSizeAndPositionSection.qml", {index: index})
    }
}
