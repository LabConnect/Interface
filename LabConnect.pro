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
    libSgen-V0.1.cpp \
    usb/hiddata.c

HEADERS  += LabConnect.h \
    libSgen-V0.1.h \
    usb/hiddata.h \
    usb/usbconfig.h

FORMS    += LabConnect.ui

LIBS += -L/usr/lib -lusb

OTHER_FILES +=

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libusb-1.0