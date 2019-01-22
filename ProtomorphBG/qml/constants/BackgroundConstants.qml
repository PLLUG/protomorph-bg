pragma Singleton
import QtQuick 2.12

QtObject {
    id: root

    readonly property var backgroundTypes: [colorType, gradientType, imageType]

    readonly property var colorType: {"original" : "Color", "translated" : qsTr("Color")}
    readonly property var gradientType: {"original" : "Gradient", "translated" : qsTr("Gradient")}
    readonly property var imageType: {"original" : "Image", "translated" : qsTr("Image")}
}
