import QtQuick 2.12

BasicPanel {
    id: root

    Connections {
        target: ComponentDecorationsModel
        onDecorationSelectionChanged: {
            if (indexRow > -1) {
                print(ComponentDecorationsModel.getDecorationStoreByIndex(indexRow))
            }
        }
    }
}
