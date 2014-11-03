#-------------------------------------------------
#
# Project created by QtCreator 2014-09-27T19:44:22
#
#-------------------------------------------------
QT       += core gui
# QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LabConnect
TEMPLATE = app


SOURCES += main.cpp\
        LabConnect.cpp \
    einstellungen.cpp \
    globals.cpp

HEADERS  += LabConnect.h \
    einstellungen.h \
    globals.h

FORMS    += LabConnect.ui \
    einstellungen.ui
