#-------------------------------------------------
#
# Project created by QtCreator 2018-02-08T01:19:36
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += "SVN_V=\"\\\"$$system(svnversion -n)\\\"\""

TARGET = 060_WDromRead
TEMPLATE = app

include(../hexedit/hexedit.pri)
include(../QtAwesome/QtAwesome.pri)

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    rlab.h

FORMS    += mainwindow.ui

RESOURCES += \
    060_WDromRead.qrc

win* {
  RC_FILE += 060_WDromRead.rc
}
