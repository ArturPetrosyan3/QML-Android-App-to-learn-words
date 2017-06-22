TEMPLATE = app

QT += qml quick widgets

QT += sql
android: {
QT += androidextras
}

SOURCES += sources/main.cpp \
    sources/mydevice.cpp \
    database.cpp \
    model.cpp \
    createdictionary.cpp

HEADERS += sources/mydevice.h \
    database.h \
    model.h \
    createdictionary.h

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

