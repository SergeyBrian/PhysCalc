QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../calculator.pri)
include(../../data/data.pri)
include(../../exceptions/exceptions.pri)

HEADERS += \
    calculatortest.h

SOURCES += \
    calculatortest.cpp
