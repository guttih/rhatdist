QT += testlib
QT -= gui


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
SRC = $$PWD/../../desktopdist
SRC_RELATIVE = ../../desktopdist
NOW = $$system(date +%Y-%m-%d) $$system(date +%H:%M:%S)
INCLUDEPATH += $$SRC
DEPENDPATH += $$SRC
TEMPLATE = app

SOURCES += \
        $$SRC_RELATIVE/JsonFile.cpp \
        $$SRC_RELATIVE/Person.cpp \
        $$SRC_RELATIVE/AbstractJData.cpp \
        $$SRC_RELATIVE/JFile.cpp \
        $$SRC_RELATIVE/JMan.cpp \
        $$SRC_RELATIVE/String.cpp \
        $$SRC_RELATIVE/Json.cpp \
        $$SRC_RELATIVE/JsonData.cpp \
        $$SRC_RELATIVE/JStudent.cpp \
        tst_test_jsonsave.cpp
HEADERS += \
        $$SRC_RELATIVE/JsonFile.h \
        $$SRC_RELATIVE/Person.h \
        $$SRC_RELATIVE/AbstractJData.h \
        $$SRC_RELATIVE/IJData.h \
        $$SRC_RELATIVE/JFile.h \
        $$SRC_RELATIVE/JMan.h \
        $$SRC_RELATIVE/String.h \
        $$SRC_RELATIVE/Json.h \
        $$SRC_RELATIVE/JsonData.h \
        $$SRC_RELATIVE/JStudent.h \

message("============================================================")
message("Build time   : $$NOW")
message("SRC          : $$SRC")
message("SRC_RELATIVE : $$SRC_RELATIVE")
