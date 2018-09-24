import QtQuick 2.12

import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    background: Rectangle {
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#434343";
            }
            GradientStop {
                position: 1.00;
                color: "#000000";
            }
        }
    }

    Material.theme: Material.Dark
    Material.accent: Material.Grey

    title: qsTr("Protomorph BG")
}
