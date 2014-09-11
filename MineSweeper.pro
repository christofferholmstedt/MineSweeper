TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    minefield.cpp \
    minefieldmodel.cpp

RESOURCES += qml.qrc

# Added this to get console output on Windows 8 machine
CONFIG += console

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    minefield.h \
    minefieldmodel.h \
    lib/grid.h
