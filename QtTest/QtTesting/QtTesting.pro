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
        $$SRC_RELATIVE/String.cpp \
        $$SRC_RELATIVE/Json.cpp \
        $$SRC_RELATIVE/JsonData.cpp \
        $$SRC_RELATIVE/Book.cpp \
        $$SRC_RELATIVE/JStudent.cpp \
        $$SRC_RELATIVE/Student.cpp \
        $$SRC_RELATIVE/JsonSaveMany.cpp \
        $$SRC_RELATIVE/IJsonSaveData.cpp \
        $$SRC_RELATIVE/JsonSave.cpp \
        $$SRC_RELATIVE/appsettings.cpp \
        tst_test_jsonsave.cpp
HEADERS += \
        $$SRC_RELATIVE/String.h \
        $$SRC_RELATIVE/Json.h \
        $$SRC_RELATIVE/JsonData.h \
        $$SRC_RELATIVE/Book.h \
        $$SRC_RELATIVE/JStudent.h \
        $$SRC_RELATIVE/Student.h \
        $$SRC_RELATIVE/JsonSaveMany.h \
        $$SRC_RELATIVE/IJsonSaveData.h \
        $$SRC_RELATIVE/JsonSave.h \
        $$SRC_RELATIVE/appsettings.h \

message("============================================================")
message("Build time   : $$NOW")
message("SRC          : $$SRC")
message("SRC_RELATIVE : $$SRC_RELATIVE")
