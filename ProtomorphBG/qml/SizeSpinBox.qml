import QtQuick 2.12

import QtQuick.Controls 2.5

import protomorph.qmlhelper 1.0

SpinBox {
    id: root

    QtObject {
        id: internal
        readonly property int minComponentSizeValue: 30
        readonly property int maxComponentSizeValue: 1000
        readonly property int singleStep: QmlHelper.fromMMToPixelsOnScreen(1)
    }

    editable: true
    stepSize: internal.singleStep
    from: internal.minComponentSizeValue
    to: internal.maxComponentSizeValue
    valueFromText: function(mm) {
        return QmlHelper.fromMMToPixelsOnScreen(mm)
    }
    textFromValue: function(pixels) {
        return QmlHelper.fromPixelsOnScreenToMM(pixels)
    }
}
