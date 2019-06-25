import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.4

import "qrc:/components"

Flickable {
    id: root

    contentHeight: sectionsLayout.implicitHeight
    boundsMovement: Flickable.StopAtBounds

    ColumnLayout {
        id: sectionsLayout

        anchors {
            left: parent.left
            right: parent.right
        }

        Repeater {
            model: ListModel { id: sectionModel }

            delegate: CollapsibleSection {
                id: section
                title: sectionTitle

                Layout.fillWidth: true
                Layout.preferredHeight: section.implicitHeight

                contentItem: Loader {
                    source: sectionSourceUrl
                    onLoaded: {
                        if (item.payload !== undefined)
                            item.payload = sectionPayload
                    }
                }
            }
        }

        Item { Layout.fillHeight: true }
    }

    ScrollBar.vertical: ScrollBar { policy: ScrollBar.AsNeeded }

    function addCollapsibleSection(sectionTitle, sectionSourceUrl, sectionPayload) {
        if (sectionPayload === undefined)
            sectionPayload = {}

        sectionModel.append({"sectionTitle" : sectionTitle, "sectionSourceUrl": sectionSourceUrl, "sectionPayload": sectionPayload})
    }

    function clearPanel() {
        sectionModel.clear()
    }
}
