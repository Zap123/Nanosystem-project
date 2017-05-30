#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T13:35:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nanosystems
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helper.cpp \
    state.cpp \
    #programcontext.cpp \
    s_idle.cpp \
    s_calibration.cpp \
    calibrate.cpp \
    s_measure.cpp

HEADERS  += mainwindow.h \
    helper.h \
    state.h \
    #programcontext.h \
    s_idle.h \
    s_calibration.h \
    calibrate.h \
    s_measure.h

FORMS    += mainwindow.ui \
    calibrate.ui

OTHER_FILES +=

DISTFILES +=

RESOURCES += \
    resources.qrc
