import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import "qrc:/components"

Flickable {
    id: root

    function addCollapsibleSection(sectionTitle, sectionSourceUrl) {
        sectionModel.append({"sectionTitle" : sectionTitle, "sectionSourceUrl": sectionSourceUrl})
    }

    contentHeight: sectionsLayout.implicitHeight
    boundsMovement: Flickable.StopAtBounds

    ColumnLayout {
        id: sectionsLayout

        anchors {
            left: parent.left
            right: parent.right
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

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AsNeeded
    }
}
