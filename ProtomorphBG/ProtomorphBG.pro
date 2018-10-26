QT += quick
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    CardSizesConstants.hpp \
    SizesListModel.hpp

SOURCES += \
        main.cpp \
    SizesListModel.cpp

RESOURCES += qml.qrc
