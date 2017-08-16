#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T13:35:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Nanosystems
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helper.cpp \
    state.cpp \
    s_idle.cpp \
    s_calibration.cpp \
    calibrate.cpp \
    s_measure.cpp \
    qcustomplot.cpp \
    chart.cpp

HEADERS  += mainwindow.h \
    helper.h \
    state.h \
    s_idle.h \
    s_calibration.h \
    calibrate.h \
    s_measure.h \
    qcustomplot.h \
    chart.h

FORMS    += mainwindow.ui \
    calibrate.ui \
    chart.ui

OTHER_FILES +=

DISTFILES +=

RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += \
    -std=c++11
