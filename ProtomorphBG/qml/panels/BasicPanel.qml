import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import "qrc:/components"

ColumnLayout {
    id: root

    function addCollapsibleSection(sectionTitle, sectionSourceUrl) {
        sectionModel.append({"sectionTitle" : sectionTitle, "sectionSourceUrl": sectionSourceUrl})
    }

    Repeater {
        model: ListModel {
            id: sectionModel
            dynamicRoles: true
        }

        delegate: CollapsibleSection {
            id: section
            title: sectionTitle

            Layout.fillWidth: true
            Layout.minimumHeight: section.expanded ? section.header.implicitHeight + section.contentComponent.implicitHeight : -1
            Layout.maximumHeight: section.expanded ? section.implicitHeight : section.header.implicitHeight

            contentComponent: Loader {
                source: sectionSourceUrl
            }
        }
    }

    Item {
        Layout.fillHeight: true
    }
}
