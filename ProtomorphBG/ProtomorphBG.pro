QT += qml quick quickcontrols2 svg widgets xml
CONFIG += c++17 ordered

DEFINES += QT_DEPRECATED_WARNINGS TURNOFFSVGLOADING

win32:CONFIG(release, debug|release) {
        QMAKE_CXXFLAGS_RELEASE += /O2
        QMAKE_LFLAGS_RELEASE -= /O1 /O3
}
#SUBMODULES
FLUX= submodules/quickflux/quickflux.pri
FONTAWESOMEPATH = submodules/fontawesome.pri/fontawesome.pri

include($${FLUX})
include($${FONTAWESOMEPATH})

HEADERS += \
    src/constants/CardSizesConstants.hpp \
    src/models/SizesListModel.hpp \
    src/helpers/MeasurementConverters.hpp \
    src/helpers/QmlHelper.hpp \
    src/store/ComponentEditorStore.hpp \
    src/helpers/UISizeAdapter.hpp \
    src/constants/Enums.hpp \
    src/helpers/GradientHelper.hpp \
    src/dataobjects/Background.hpp \
    src/dataobjects/ComponentDecoration.hpp \
    src/dataobjects/Component.hpp \
    src/dataobjects/Borders.hpp \
    src/models/GameIconsListModel.hpp \
    src/qmlitems/SvgImage.hpp \
    src/models/GameIconsFilterModel.hpp \
    src/qmlitems/SvgCanvas.hpp \
    src/helpers/GameIconsSvgColorsHelper.hpp

SOURCES += \
        src/main.cpp \
    src/models/SizesListModel.cpp \
    src/helpers/MeasurementConverters.cpp \
    src/helpers/QmlHelper.cpp \
    src/store/ComponentEditorStore.cpp \
    src/helpers/UISizeAdapter.cpp \
    src/helpers/GradientHelper.cpp \
    src/models/GameIconsListModel.cpp \
    src/qmlitems/SvgImage.cpp \
    src/models/GameIconsFilterModel.cpp \
    src/qmlitems/SvgCanvas.cpp \
    src/helpers/GameIconsSvgColorsHelper.cpp

RESOURCES += qml.qrc \
    fonts.qrc \
    images.qrc \
    game-icons.qrc
