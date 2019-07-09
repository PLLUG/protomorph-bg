QT += testlib
QT += gui widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += \
        testprototypecomponentsnavigatorwindow.cpp

include($$PWD/../../prototypecomponentsnavigatorwindow/prototypecomponentsnavigatorwindow.pri)
