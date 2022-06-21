#include <QtTest>
#include <QCoreApplication>
#include "appsettings.h"
#include "JsonSave.h"
#include "JSAppSettings.h"
// add necessary includes here

class test_JsonSave : public QObject
{
Q_OBJECT

public:
    test_JsonSave();
    ~test_JsonSave();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();

};

test_JsonSave::test_JsonSave()
{

}

test_JsonSave::~test_JsonSave()
{


}

void test_JsonSave::initTestCase()
{

}

void test_JsonSave::cleanupTestCase()
{

}

void test_JsonSave::test_case1()
{
    QString path=qApp->applicationDirPath(),
            settingsPath, test;

    settingsPath=path + "/settings.json";
    AppSettings settings( settingsPath.toStdString() );
    qDebug(  "Path : %s", settings.getFilePath().c_str() );
    test = settings.getFilePath().c_str();
    QVERIFY( test.endsWith( "/settings.json" ) );
    // QCOMPARE( settings.getFilePath(), "/settings.json" );
}

void test_JsonSave::test_case2()
{
    JsonSave xxx;
    JSAppSettings jas;

    xxx.i=444;
    QVERIFY( 444 == xxx.i );
}

QTEST_MAIN( test_JsonSave )

#include "tst_test_jsonsave.moc"
