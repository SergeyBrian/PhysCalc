QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../table.pri)
include(../../exceptions/exceptions.pri)

HEADERS += \
    tabletest.h \

SOURCES += \
    tabletest.cpp \
