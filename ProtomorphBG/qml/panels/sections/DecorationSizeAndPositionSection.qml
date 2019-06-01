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
            /*emit*/ ApplicationActions.changeDecorationPosition(Qt.point(value, decorationStore.decorationPosition.y))
        }
    }

    SpinBox {
        id: ySpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationPosition.y : 0
        onValueChanged: {
            /*emit*/ ApplicationActions.changeDecorationPosition(Qt.point(decorationStore.decorationPosition.x, value))
        }
    }

    SpinBox {
        id: widthSpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationSize.width : 0
        onValueChanged: {
            /*emit*/ ApplicationActions.changeDecorationSize(Qt.size(value, decorationStore.decorationSize.height))
        }
    }

    SpinBox {
        id: heightSpinbox
        Layout.fillWidth: true
        Layout.minimumHeight: internal.componentsDefaultHeight
        to: Screen.width
        value: decorationStore ? decorationStore.decorationSize.height : 0
        onValueChanged: {
            /*emit*/ ApplicationActions.changeDecorationSize(Qt.size(decorationStore.decorationSize.width, value))
        }
    }

    QtObject {
        id: internal
        readonly property real componentsDefaultHeight: UISizeAdapter.calculateSize(30)
    }
}
