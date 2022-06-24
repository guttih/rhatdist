#include <QtTest>
#include <QCoreApplication>
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

// void test_JsonSave::test_JStudent_SaveAndLoad()
// {
//     QString filename=qApp->applicationDirPath() + "/../jstudent.json";
//     JStudent obj( filename.toStdString().c_str() );
//     // qDebug( "Filename: %s\n", man.getFilename().c_str() );

//     QCOMPARE( obj.getFilename(), filename.toStdString() );

//     QFile file( filename  );
//     if( QFileInfo::exists( filename ) )
//         file.remove();

//     obj._name="Gudjon";
//     obj._age=50;
//     obj._enrolled=2024;
//     obj.save();
//     obj._name="";
//     obj._age=0;
//     obj._enrolled=22;
//     obj.load();
//     QCOMPARE( obj._name, "Gudjon" );
//     QVERIFY( obj._age == 50 );
//     QVERIFY( obj._enrolled == 2024 );


// }

void test_JsonSave::test_Person_SaveAndLoad()
{
    Person person;
    person._name="Gudjon"; person._age=51;
    JsonFile jf( "person.json", ( AbstractJData* ) &person );
    QVERIFY( jf.save() );
    person._name=""; person._age=0;
    QVERIFY( jf.load() );
    QCOMPARE( person._name, "Gudjon" );
    QVERIFY( person._age == 51 );
}

QTEST_MAIN( test_JsonSave )

#include "tst_test_jsonsave.moc"
