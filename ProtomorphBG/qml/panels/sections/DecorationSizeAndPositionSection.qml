import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12

import protomorph.sizelistmodel 1.0
import protomorph.uisizeadapter 1.0

import "qrc:/actions"
import "qrc:/custom_controls"

ColumnLayout {
    id: root

    property var payload: ({})
    property var decorationStore: null

    onPayloadChanged: decorationStore = ComponentDecorationsModel.getByIndexAndRole(payload.index, "decorationStoreRole")

    SpinBox {
        id: xSpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationPosition.x : 0
        onValueChanged: {
            if(decorationStore) {
            }
        }
    }

    SpinBox {
        id: ySpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationPosition.y : 0
        onValueChanged: {
            if(decorationStore)
                decorationStore.decorationPosition.y = value
        }
    }

    SpinBox {
        id: widthSpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationSize.width : 0
        onValueChanged: {
            if(decorationStore)
                decorationStore.decorationPosition.width = value
        }
    }

    SpinBox {
        id: heightSpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationSize.height : 0
        onValueChanged: {
            if(decorationStore)
                decorationStore.decorationPosition.height = value
        }
    }

    QtObject {
        id: internal
        readonly property real componentsDefaultHeight: UISizeAdapter.calculateSize(30)
    }
}
