import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4
import QtQuick.Window 2.12

import protomorph.uisizeadapter 1.0

/****************************************************************************
**
** Copyright (C) 2014 Alexander Rössler
** License: LGPL version 2.1
**
** This file is part of QtQuickVcp.
**
** All rights reserved. This program and the accompanying materials
** are made available under the terms of the GNU Lesser General Public License
** (LGPL) version 2.1 which accompanies this distribution, and is available at
** http://www.gnu.org/licenses/lgpl-2.1.html
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Lesser General Public License for more details.
**
** Contributors:
** Alexander Rössler @ The Cool Tool GmbH <mail DOT aroessler AT gmail DOT com>
**
****************************************************************************/
//  A toy QML colorpicker control, by Ruslan Shestopalyuk


/*!
    \qmltype ColorPicker
    \inqmlmodule Machinekit.Controls
    \brief Provides a beautiful color picker.
    \ingroup machinekitcontrols

    The color picker provides an easy to use control to select colors. You can
    use the selected color by using the \l colorValue property.

    \qml
    ColorPicker {
        id: colorPicker
    }
    \endqml
*/
ColumnLayout {
    id: root
    property bool alphaVisible: true
    readonly property color colorValue: internal.hsba(hueSlider.item.value,
                                                      saturationBrightnessPicker.item.saturation,
                                                      saturationBrightnessPicker.item.brightness,
                                                      alphaVisible ? alphaControl.item.value : 1)

    spacing: 0


    Loader {
        id: saturationBrightnessPicker
        sourceComponent: saturationBrightnessPickerComponent

        Layout.preferredHeight: Math.round(parent.height / 1.75)
        Layout.fillWidth: true

        Binding {
            target: saturationBrightnessPicker.item
            property: "hueColor"
            value: hueSlider.item.value
        }
    }

    Rectangle {
        id: huePicker
        Layout.preferredHeight: internal.preferredSliderHeight
        Layout.fillWidth: true

        gradient: Gradient {
            orientation: Gradient.Horizontal

            GradientStop {
                position: 1.0
                color: "#FF0000"
            }
            GradientStop {
                position: 0.85
                color: "#FFFF00"
            }
            GradientStop {
                position: 0.76
                color: "#00FF00"
            }
            GradientStop {
                position: 0.5
                color: "#00FFFF"
            }
            GradientStop {
                position: 0.33
                color: "#0000FF"
            }
            GradientStop {
                position: 0.16
                color: "#FF00FF"
            }
            GradientStop {
                position: 0.0
                color: "#FF0000"
            }
        }

        Loader {
            id: hueSlider
            sourceComponent: colorSliderComponent
            anchors.fill: parent
        }
    }

    Loader {
        id: alphaControl
        active: alphaVisible

        Layout.preferredHeight: internal.preferredSliderHeight
        Layout.fillWidth: true

        sourceComponent: Item {
            id: alphaPicker

            property real value: alphaSlider.item.value

            Rectangle {
                anchors.fill: parent
                color: "white"
            }

            Rectangle{
                anchors.fill: parent

                gradient: Gradient {
                    orientation: Gradient.Horizontal

                    GradientStop {
                        position: 0.0
                        color: "#FF000000"
                    }
                    GradientStop {
                        position: 1.0
                        color: "#00000000"
                    }
                }

                Loader {
                    id: alphaSlider
                    anchors.fill: parent
                    sourceComponent: colorSliderComponent
                }
            }
        }
    }

    RowLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            id: currentColorRect
            Layout.fillHeight: true
            Layout.preferredWidth: root.width * 0.2
            border {
                width: UISizeAdapter.calculateSize(1)
                color: "black"
            }
            color: root.colorValue
        }

        GridLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            rows: 4
            columns: 2

            // H, S, B color values boxes
            Loader {
                id: hBox
                sourceComponent: numberBox
                Layout.row: 0
                Layout.column: 0
                onLoaded: item.caption = "H"
                Binding {
                    target: hBox.item
                    property: "value"
                    value: hueSlider.item.value.toFixed(2)
                }
            }

            Loader {
                id: sBox
                sourceComponent: numberBox
                Layout.row: 1
                Layout.column: 0
                onLoaded: item.caption = "S"
                Binding {
                    target: sBox.item
                    property: "value"
                    value: saturationBrightnessPicker.item.saturation.toFixed(2)
                }
            }

            Loader {
                id: vBox
                sourceComponent: numberBox
                Layout.row: 2
                Layout.column: 0
                onLoaded: item.caption = "V"
                Binding {
                    target: vBox.item
                    property: "value"
                    value: saturationBrightnessPicker.item.brightness.toFixed(2)
                }
            }

            // R, G, B color values boxes
            Loader {
                id: rBox
                sourceComponent: numberBox
                Layout.row: 0
                Layout.column: 1
                onLoaded: {
                    item.caption = "R"
                    item.min = 0
                    item.max = 255
                }
                Binding {
                    target: rBox.item
                    property: "value"
                    value: internal.getChannelStr(root.colorValue, 0)
                }
            }

            Loader {
                id: gBox
                sourceComponent: numberBox
                Layout.row: 1
                Layout.column: 1
                onLoaded: {
                    item.caption = "G"
                    item.min = 0
                    item.max = 255
                }
                Binding {
                    target: gBox.item
                    property: "value"
                    value: internal.getChannelStr(root.colorValue, 1)
                }
            }

            Loader {
                id: bBox
                sourceComponent: numberBox
                Layout.row: 2
                Layout.column: 1
                onLoaded: {
                    item.caption = "B"
                    item.min = 0
                    item.max = 255
                }
                Binding {
                    target: bBox.item
                    property: "value"
                    value: internal.getChannelStr(root.colorValue, 2)
                }
            }

            // alpha value box
            Loader {
                id: aBox
                sourceComponent: numberBox
                Layout.row: 3
                Layout.column: 0
                active: alphaVisible
                onLoaded: {
                    item.caption = "A"
                    item.min = 0
                    item.max = 255
                }
                Binding {
                    target: aBox.item
                    property: "value"
                    value: Math.ceil(root.colorValue.a * 255)
                }
            }

            TextField {
                id: colorEditBox

                Layout.row: 3
                Layout.column: 1
                text: internal.fullColorString(root.colorValue,
                                               root.colorValue.a)
                maximumLength: 9
                focus: true
            }
        }
    }

    QtObject {
        id: internal

        readonly property int preferredSliderHeight: UISizeAdapter.calculateSize(20)

        //Creates color value from hue, saturation, brightness, alpha.
        function hsba(hue, saturation, brightness, alpha) {
            var lightness = (2 - saturation) * brightness
            var satHSL = saturation * brightness / ((lightness <= 1) ? lightness : 2 - lightness)
            lightness /= 2
            return Qt.hsla(hue, satHSL, lightness, alpha)
        }

        //Creates a full color string from color value and alpha[0..1], e.g. "#FF00FF00".
        function fullColorString(color, alpha) {
            return "#" + ((Math.ceil(alpha * 255) + 256).toString(16).substr(
                              1, 2) + color.toString().substr(1,
                                                              6)).toUpperCase()
        }

        //Extracts integer color channel value [0..255] from color value.
        function getChannelStr(color, channelIdx) {
            return parseInt(color.toString().substr(channelIdx * 2 + 1, 2), 16)
        }
    }

    Component {
        id: colorSliderComponent

        MouseArea {
            id: pickerHandlerArea
            property real value: visible ? Math.max(
                                               1 - pickerHandle.x / width,
                                               0.0) : 1.0


            onPositionChanged: handleMouse(mouse)
            onPressed: handleMouse(mouse)

            function handleMouse(mouse) {
                if (mouse.buttons & Qt.LeftButton) {
                    pickerHandle.x = Math.max(0, Math.min(width, mouse.x))
                }
            }

            Rectangle {
                id: pickerHandle

                x: Math.round(parent.width / 2) //center picker handle
                width: Math.round(parent.width * 0.03)
                height: parent.height

                border {
                    color: "black"
                    width: UISizeAdapter.calculateSize(1)
                }

                color: "transparent"

                Rectangle {
                    anchors{
                        fill: parent
                        margins: UISizeAdapter.calculateSize(2)
                    }
                    border{
                        color: "white"
                        width: UISizeAdapter.calculateSize(1)
                    }
                    color: "transparent"
                }
            }
        }
    }

    Component {
        id: numberBox

        RowLayout {
            property alias caption: captionBox.text
            property alias value: inputBox.text
            property alias min: numValidator.bottom
            property alias max: numValidator.top
            property alias decimals: numValidator.decimals

            spacing: UISizeAdapter.calculateSize(5)

            Label {
                id: captionBox
                Layout.fillHeight: true
                font{
                    pixelSize: UISizeAdapter.calculateSize(11)
                    bold: true
                }
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: inputBox
                Layout.fillHeight: true
                Layout.fillWidth: true
                validator: DoubleValidator {
                    id: numValidator
                    bottom: 0
                    top: 1
                    decimals: 2
                    notation: DoubleValidator.StandardNotation
                }
            }
        }
    }

    Component {
        id: saturationBrightnessPickerComponent

        MouseArea {
            id: saturationBrightnessPicker

            property real hueColor: 1.0
            property real saturation: pickerHandle.x / saturationBrightnessPicker.width
            property real brightness: 1 - pickerHandle.y / saturationBrightnessPicker.height

            onPositionChanged: handleMouse(mouse)
            onPressed: handleMouse(mouse)

            function handleMouse(mouse) {
                if (mouse.buttons & Qt.LeftButton) {
                    pickerHandle.x = Math.max(0, Math.min(width, mouse.x))
                    pickerHandle.y = Math.max(0, Math.min(height, mouse.y))
                }
            }

            Rectangle {
                height: parent.width
                width: parent.height
                x: (width - parent.width) / 2
                y: (parent.height - height) / 2

                transform: Rotation {
                    angle: -90
                    origin.x: width / 2
                    origin.y: height / 2
                }

                gradient: Gradient {
                    GradientStop {
                        position: 0.0
                        color: "#FFFFFF"
                    }
                    GradientStop {
                        position: 1.0
                        color: Qt.hsla(hueColor, 1.0, 0.5, 1.0)
                    }
                }
            }

            Rectangle {
                anchors.fill: parent
                gradient: Gradient {
                    GradientStop {
                        position: 1.0
                        color: "#FF000000"
                    }
                    GradientStop {
                        position: 0.0
                        color: "#00000000"
                    }
                }
            }

            Rectangle {
                id: pickerHandle
                property int r: UISizeAdapter.calculateSize(8)
                x: parent.width / 2
                y: parent.height / 2
                width: pickerHandle.r * 2
                height: pickerHandle.r * 2
                radius: pickerHandle.r
                border.color: "black"
                border.width: UISizeAdapter.calculateSize(2)
                color: "transparent"

                Rectangle {
                    anchors.fill: parent
                    anchors.margins: UISizeAdapter.calculateSize(2)
                    border.color: "white"
                    border.width: UISizeAdapter.calculateSize(2)
                    radius: width / 2
                    color: "transparent"
                }
            }
        }
    }
}
