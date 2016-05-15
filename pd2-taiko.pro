#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T21:49:29
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    drum.cpp \
    point.cpp \
    clock.cpp \
    score.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    drum.h \
    point.h \
    clock.h \
    score.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
