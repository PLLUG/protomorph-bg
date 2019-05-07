import QtQuick 2.12

import protomorph.enums 1.0

BasicPanel {
    id: root

    Connections {
        target: ComponentDecorationsModel
        onDecorationSelectionChanged: {
            if (indexRow > -1) {
                var decorationType = ComponentDecorationsModel.getByIndexAndRole(indexRow, "typeRole")
                switch(decorationType) {
                case Enums.DECORATION_GAME_ICON:
                    gameIconDecorationPanelModel(indexRow)
                    break;
                }
            }
        }
    }

    function gameIconDecorationPanelModel(index) {
        root.addCollapsibleSection(qsTr("Decoration size and position"), "qrc:/panels/sections/DecorationSizeAndPositionSection.qml", {index: index})
//        root.addCollapsibleSection(qsTr("Icon color"), "", {decorationStore: selectedDecorationStore})
    }
}
