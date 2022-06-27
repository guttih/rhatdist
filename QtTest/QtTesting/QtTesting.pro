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
        $$SRC_RELATIVE/Persons.cpp \
        $$SRC_RELATIVE/Person.cpp \
        $$SRC_RELATIVE/AbstractJsonFileDataCollection.cpp \
        $$SRC_RELATIVE/AbstractJsonFileData.cpp \
        $$SRC_RELATIVE/String.cpp \
        $$SRC_RELATIVE/Json.cpp \
        $$SRC_RELATIVE/JsonData.cpp \
        tst_test_jsonsave.cpp

HEADERS += \
        $$SRC_RELATIVE/JsonFileDataCollection.h \
        $$SRC_RELATIVE/JsonFile.h \
        $$SRC_RELATIVE/Persons.h \
        $$SRC_RELATIVE/Person.h \
        $$SRC_RELATIVE/AbstractJsonFileDataCollection.h \
        $$SRC_RELATIVE/AbstractJsonFileData.h \
        $$SRC_RELATIVE/IJsonFileData.h \
        $$SRC_RELATIVE/String.h \
        $$SRC_RELATIVE/Json.h \
        $$SRC_RELATIVE/JsonData.h \

message("============================================================")
message("Build time   : $$NOW")
message("SRC          : $$SRC")
message("SRC_RELATIVE : $$SRC_RELATIVE")
 
