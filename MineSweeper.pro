TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    square.cpp \
    board.cpp \
    gridofsquares.cpp \
    boardmodel.cpp

RESOURCES += qml.qrc

# Added this to get console output on Windows 8 machine
CONFIG += console

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    lib/grid.h \
    square.h \
    board.h \
    gridofsquares.h \
    boardmodel.h

OTHER_FILES += \
    dummydata/boardModel.qml
