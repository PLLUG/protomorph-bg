pragma Singleton
import QtQuick 2.12
import QuickFlux 1.0

ActionCreator {
    //Application actions
    signal startApp
    signal quitApp

    signal changeComponentSize(size size);
    signal changeComponentBackground(var propertiesObj)
    signal changeComponentBorders(var propertiesObj)
    signal addDecoration(var propertiesObj)
}
