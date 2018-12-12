QT += quick
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    src\constants\CardSizesConstants.hpp \
    src\models\SizesListModel.hpp

SOURCES += \
        src\main.cpp \
    src\models\SizesListModel.cpp

RESOURCES += qml.qrc
