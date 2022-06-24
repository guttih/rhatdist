#include <QtTest>
#include <QCoreApplication>
#include "JStudent.h"
#include "String.h"
#include "JMan.h"
#include "JStudent.h"
#include "JFile.h"
  #include <fstream>
#include "Person.h"
#include "JsonFile.h"

// add necessary includes here

class test_JsonSave : public QObject
{
Q_OBJECT

private:
    String fileToString( String fullFilePath );

public:
    test_JsonSave();
    ~test_JsonSave();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_readJsonExampleFile();
    void test_JMan_SaveAndLoad();
    void test_JStudent_SaveAndLoad();
    void test_Person_SaveAndLoad();
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

String test_JsonSave::fileToString( String fullFilePath )
{
    ifstream inFile;
    inFile.open( fullFilePath.c_str() ); //open the input file

    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file

    return strStream.str().c_str();

}

void test_JsonSave::test_readJsonExampleFile()
{
    QString path=qApp->applicationDirPath() + "/../example7.json";
    // qDebug( "Reading file %s\n", path.toStdString().c_str() );
    Json json( fileToString( path.toStdString().c_str() ).c_str() );
    QVERIFY( json.isValid() );
    // qDebug( "json=%s", json.toTree().c_str() );
}

void test_JsonSave::test_JMan_SaveAndLoad()
{
    QString filename=qApp->applicationDirPath() + "/../jman.json";
    JMan man( filename.toStdString().c_str() );
    // qDebug( "Filename: %s\n", man.getFilename().c_str() );

    QCOMPARE( man.getFilename(), filename.toStdString() );

    QFile file( filename  );
    if( QFileInfo::exists( filename ) )
        file.remove();

    man._name="Gudjon";
    man._age=50;
    man.save();
    man._name="";
    man._age=0;
    man.load();
    QCOMPARE( man._name, "Gudjon" );
    QVERIFY( man._age == 50 );

}

void test_JsonSave::test_JStudent_SaveAndLoad()
{
    /*
        class IJData {
            public
                read
                virtual bool setFromJson(const char *jsonString)=0;
                virtual CString toJsonString() = 0
        };

        class AbstractJData : IJData{
            public
                read
                virtual bool setFromJson(const char *jsonString)=0;
                virtual CString toJsonString() = 0
        };

        class Student : JAbstractData {
            public
                read
                bool setFromJson(const char *jsonString)=0;
                CString toJsonString() = 0
        };

        JFile JFile("student.json");
        CString str=student.fileToString();

        Person inherits JData
            Father inherits Person
            Child inherits Person
        JData


    */
    QString filename=qApp->applicationDirPath() + "/../jstudent.json";
    JStudent obj( filename.toStdString().c_str() );
    // qDebug( "Filename: %s\n", man.getFilename().c_str() );

    QCOMPARE( obj.getFilename(), filename.toStdString() );

    QFile file( filename  );
    if( QFileInfo::exists( filename ) )
        file.remove();

    obj._name="Gudjon";
    obj._age=50;
    obj._enrolled=2024;
    obj.save();
    obj._name="";
    obj._age=0;
    obj._enrolled=22;
    obj.load();
    QCOMPARE( obj._name, "Gudjon" );
    QVERIFY( obj._age == 50 );
    QVERIFY( obj._enrolled == 2024 );


}

void test_JsonSave::test_Person_SaveAndLoad()
{
    Person person;

    person._name="Gudjon"; person._age=51;
    JsonFile jf( "person.json", ( AbstractJData* ) &person );
    qDebug( "json:%s\n", jf.toJsonString().c_str() );
    // jf.save();
    // person._name=""; person._age=0;
    // jf.load();
    // QCOMPARE( person._name, "Gudjon" );
    // QVERIFY( person._age == 50 );
}

QTEST_MAIN( test_JsonSave )

#include "tst_test_jsonsave.moc"
