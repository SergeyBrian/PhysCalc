QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../data.pri)
include(../../exceptions/exceptions.pri)

HEADERS += \
    datatest.h \

SOURCES += \
    datatest.cpp \
