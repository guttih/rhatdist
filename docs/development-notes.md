# Development notes
Some notes used when developing

## snippets

### test project

- test.pro
    ```
    INCLUDEPATH += $$PWD/../../desktopdist
    LIBS += -L/home/gudjon/repos/personal/rhatdist/build-desktopdist-Desktop-buggi
    target_link_libraries(appsettingsTests PRIVATE appsettings)
    QT += testlib
    QT -= gui

    CONFIG += qt console warn_on depend_includepath testcase
    CONFIG -= app_bundle

    TEMPLATE = app

    SOURCES +=  tst_appsettingstest.cpp

    message("XXPath : ["$$INCLUDEPATH}"]")
    message("XXPath : ["$$LIBS}"]")
    ```
- tst_qutests.cpp
    ```
    ...
    void QUtests::test_case1()
    {
        QString qstr = "test me Dude!";
        //AppSettings settings(qstr.toStdString());
        AppSettings settings;
        QString path=QString::fromStdString(settings.getFilePath());
        QCOMPARE(qstr.toStdString(), path);

    }
    ```