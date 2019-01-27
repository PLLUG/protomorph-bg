QT += qml quick quickcontrols2 svg widgets
CONFIG += c++17 ordered

DEFINES += QT_DEPRECATED_WARNINGS

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
    src/models/GameIconsListModel.hpp

SOURCES += \
        src/main.cpp \
    src/models/SizesListModel.cpp \
    src/helpers/MeasurementConverters.cpp \
    src/helpers/QmlHelper.cpp \
    src/store/ComponentEditorStore.cpp \
    src/helpers/UISizeAdapter.cpp \
    src/helpers/GradientHelper.cpp \
    src/models/GameIconsListModel.cpp

RESOURCES += qml.qrc \
    fonts.qrc \
    images.qrc \
    game-icons.qrc
