TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    layer.cpp \
    testmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    layer.h \
    testmodel.h

DISTFILES += \
    main.py

