QT += qml quick quickcontrols2 svg widgets
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

#SUBMODULES
FLUX= submodules\quickflux\quickflux.pri
FONTAWESOMEPATH = submodules\fontawesome.pri\fontawesome.pri

include($${FLUX})
include($${FONTAWESOMEPATH})

!include($${FLUX}) {
    message("Please, get quickflux submodule correctly")
}
!include($${FONTAWESOMEPATH}) {
    message("Please, get fontawesome.pri submodule correctly")
}

HEADERS += \
    src\constants\CardSizesConstants.hpp \
    src\models\SizesListModel.hpp \
    src/helpers/MeasurementConverters.hpp \
    src/helpers/QmlHelper.hpp \
    src/store/ComponentEditorStore.hpp \
    src/helpers/UISizeAdapter.hpp

SOURCES += \
        src\main.cpp \
    src\models\SizesListModel.cpp \
    src/helpers/MeasurementConverters.cpp \
    src/helpers/QmlHelper.cpp \
    src/store/ComponentEditorStore.cpp \
    src/helpers/UISizeAdapter.cpp

RESOURCES += qml.qrc \
    fonts.qrc \
    images.qrc
