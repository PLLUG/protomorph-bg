pragma Singleton
import QtQuick 2.12
import QuickFlux 1.0

ActionCreator {
    //Application actions
    signal startApp
    signal quitApp

    //Component edit screen actions
    signal changeComponentHeight(real height);
    signal changeComponentWidth(real width);

    signal addImage
    signal addIcon
    signal addShape
    signal addText

    signal changeComponentBackground(var backgroundPropertiesObj)
    signal changeComponentBorders(var bordersPropertiesObj)
    signal iconSelected(var iconPropertiesObj)
}
