QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SRC = $$PWD/../../desktopdist
SRC_RELATIVE = ../../desktopdist
NOW = $$system(date +%Y-%m-%d) $$system(date +%H:%M:%S)
INCLUDEPATH += $$SRC
DEPENDPATH += $$SRC


SOURCES +=  \
            tst_settings.cpp \
            $$SRC_RELATIVE/appsettings.cpp
HEADERS +=  \
            $$SRC_RELATIVE/appsettings.h
