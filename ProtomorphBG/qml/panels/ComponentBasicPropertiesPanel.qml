import QtQuick 2.12

BasicPanel {
    id: root

    Component.onCompleted: {
        root.addCollapsibleSection(qsTr("Component size"), "qrc:/panels/sections/ComponentSizeSection.qml")
        root.addCollapsibleSection(qsTr("Background"), "qrc:/panels/sections/ComponentBackgroundSection.qml")
        root.addCollapsibleSection(qsTr("Borders"), "qrc:/panels/sections/ComponentBorderSection.qml")
    }
}
