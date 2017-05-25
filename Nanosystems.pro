#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T13:35:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nanosystems
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helper.cpp \
    state.cpp \
    programcontext.cpp \
    idle.cpp

HEADERS  += mainwindow.h \
    state.h \
    programcontext.h \
    idle.h

FORMS    += mainwindow.ui

OTHER_FILES +=

DISTFILES +=

RESOURCES += \
    resources.qrc
