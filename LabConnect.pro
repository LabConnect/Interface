#-------------------------------------------------
#
# Project created by QtCreator 2014-09-27T19:44:22
#
#-------------------------------------------------
QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LabConnect
TEMPLATE = app


SOURCES += main.cpp\
        LabConnect.cpp \
    lib/libSgen/libSgen-V0.1.cpp \
    lib/libUSB/libUSB-V0.1.cpp

HEADERS  += LabConnect.h \
    lib/libPsup/libPsup-V0.1.h \
    lib/libSgen/libSgen-V0.1.h \
    lib/libUSB/libUSB-V0.1.h \
    lib/libLabConnect.h

FORMS    += LabConnect.ui

LIBS += -L/usr/lib -lusb

OTHER_FILES +=

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libusb-1.0
