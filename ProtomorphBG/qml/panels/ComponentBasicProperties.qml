import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.4

import protomorph.enums 1.0
import protomorph.sizelistmodel 1.0
import protomorph.uisizeadapter 1.0

import "qrc:/actions"
import "qrc:/components"
import "qrc:/constants"
import "qrc:/custom_controls"
import "qrc:/stores"

ColumnLayout {
    id: root

    CollapsibleSection {
        id: componentSizeSection
        title: qsTr("Component size")

        Layout.fillWidth: true
        Layout.minimumHeight: componentSizeSection.expanded ? componentSizeSection.header.implicitHeight + componentSizeSection.contentComponent.implicitHeight : -1
        Layout.maximumHeight: componentSizeSection.expanded ? componentSizeSection.implicitHeight : componentSizeSection.header.implicitHeight

        contentComponent: ColumnLayout {
            ComboBox {
                id: cardSizes
                Layout.fillWidth: true

                textRole: "sizeAsString"
                displayText: currentText + " mm"

                model: SizesListModel {
                    id: sizesListModel
                }

                onCurrentIndexChanged: {
                    var cardSize = sizesListModel.sizeByIndex(cardSizes.currentIndex)
                    widthSpinbox.value = cardSize.width
                    heightSpinbox.value = cardSize.height
                }
            }

            SizeSpinBox {
                id: widthSpinbox
                Layout.fillWidth: true
                Layout.preferredHeight: UISizeAdapter.calculateSize(30)
                onValueChanged: ApplicationActions.changeComponentWidth(widthSpinbox.value)
            }

            SizeSpinBox {
                id: heightSpinbox
                Layout.fillWidth: true
                Layout.preferredHeight: UISizeAdapter.calculateSize(30)
                onValueChanged: ApplicationActions.changeComponentHeight(heightSpinbox.value)
            }
        }
    }

    CollapsibleSection {
        id: backgroundSection
        title: qsTr("Background")

        Layout.fillWidth: true
        Layout.minimumHeight: backgroundSection.expanded ? backgroundSection.header.implicitHeight + backgroundSection.contentComponent.implicitHeight : -1
        Layout.maximumHeight: backgroundSection.expanded ? backgroundSection.implicitHeight : backgroundSection.header.implicitHeight

        contentComponent: ColumnLayout {
            ComboBox {
                id: backgroundType

                Layout.fillWidth: true
                Layout.minimumHeight: UISizeAdapter.calculateSize(30)

                textRole: "translated"
                model: BackgroundConstants.backgroundTypes
            }

            Loader {
                Layout.fillWidth: true

                sourceComponent: {                    
                    switch(BackgroundConstants.backgroundTypes[backgroundType.currentIndex].type) {
                    case Enums.BACKGROUND_COLOR:
                        return colorPickerComponent
                    case Enums.BACKGROUND_GRADIENT:
                        return gradientPickerComponent
                    case Enums.BACKGROUND_IMAGE:
                        return imagePickerComponent
                    }
                }

                Component {
                    id: colorPickerComponent
                    ColorPickerButton {
                        onBackgroundColorChanged: ApplicationActions.changeComponentBackgroundColor (backgroundColor)
                    }
                }

                Component {
                    id: gradientPickerComponent
                    GradientPresetsPicker {
                        onGradientChanged: ApplicationActions.changeComponentBackgroundGradient(gradient)
                    }
                }

                Component {
                    id: imagePickerComponent
                    ImagePicker {
                        onImagePathChanged: ApplicationActions.changeComponentBackgroundImage(imagePath)
                    }
                }
            }
        }
    }

    Item {
        Layout.fillHeight: true
    }
}
