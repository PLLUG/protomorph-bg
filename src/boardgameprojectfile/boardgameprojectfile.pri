
FLATC_SCHEME_FILES += \
    $$PWD/bgame.fbs

include($$PWD/flatbuffers.pri)

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/boardgameprojectfile.h

SOURCES += \
    $$PWD/boardgameprojectfile.cpp
