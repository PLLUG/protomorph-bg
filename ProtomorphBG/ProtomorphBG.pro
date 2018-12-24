QT += quick
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

FONTAWESOMEPATH = D:\protomorph-bg\ProtomorphBG\submodules\fontawesome.pri\fontawesome.pri

include($${FONTAWESOMEPATH})
!include($${FONTAWESOMEPATH}) {
    message("Please, get fontawesome.pri submodule correctly")
}

HEADERS += \
    src\constants\CardSizesConstants.hpp \
    src\models\SizesListModel.hpp \
    src/helpers/MeasurementConverters.hpp \
    src/helpers/QmlHelper.hpp

SOURCES += \
        src\main.cpp \
    src\models\SizesListModel.cpp \
    src/helpers/MeasurementConverters.cpp \
    src/helpers/QmlHelper.cpp

RESOURCES += qml.qrc \
    fonts.qrc \
    images.qrc
