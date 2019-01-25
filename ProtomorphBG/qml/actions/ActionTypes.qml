pragma Singleton
import QtQuick 2.12
import QuickFlux 1.0

KeyTable {
    // Call it when the initialization is finished.
    // Now, it is able to start and show the application
    property string startApp

    // Call it to quit the application
    property string quitApp

    //Component Decorations
    property string addImage
    property string addIcon
    property string addShape
    property string addText

    //Component Properties
    property string changeComponentHeight
    property string changeComponentWidth
    property string changeComponentBackground
    property string changeComponentBorders
}
