QT += quick
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    CardSizesConstants.hpp \
    SizesListModel.hpp \
    models/PrototypeProjectsModel.hpp \
    dataobjects/Project.hpp

SOURCES += \
        main.cpp \
    SizesListModel.cpp \
    models/PrototypeProjectsModel.cpp

RESOURCES += qml.qrc
