#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T12:38:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PNC
TEMPLATE = app


SOURCES += main.cpp\
    arc.cpp \
    graphwidget.cpp \
    pitem.cpp \
    place.cpp \
    scene.cpp \
    transition.cpp \
    mainwindow.cpp

HEADERS  += \
    arc.h \
    graphwidget.h \
    pitem.h \
    place.h \
    scene.h \
    transition.h \
    mainwindow.h

FORMS    +=

RESOURCES += \
    application.qrc
