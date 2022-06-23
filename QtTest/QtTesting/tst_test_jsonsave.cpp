#include <QtTest>
#include <QCoreApplication>
#include "appsettings.h"
#include "JsonSave.h"
#include "JsonSaveMany.h"
#include "Student.h"
#include "Book.h"
#include "JStudent.h"
#include "String.h"
#include "Json.h"
#include "JMan.h"
  #include <fstream>

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
    void test_case1();
    void test_case2();
    void test_readJsonExampleFile();
    void test_JMan();
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
    /*
    Book     <- IJsonSaveData
    Student  <- IJsonSaveData

    JBook    <- JsonSave
    JStudent <- JsonSave

    JBook    uses Book
    JStudent uses Student

    JDisk <Book>.
    JStudent.load();
    JStudent.save();
    JBook.load();
    JBook.save();




    */
    // JsonSaveMany jas;
    // Student me( "Gudjon", 50 );
    // Book bk( "Gone with the wind", 33 );
    // JStudent jMe( me );
    // qDebug( "Student::toString()=%s", me.toString().c_str() );
    // qDebug( "Book::toString()=%s", bk.toString().c_str() );
    // QCOMPARE( me._name.c_str(), "Gudjon" );
    // QVERIFY( me._age == 50 );
    // QCOMPARE( me.toString().c_str(), "Gudjon;50" );
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

void test_JsonSave::test_JMan()
{
    QString filename=qApp->applicationDirPath() + "/../jman.json";
    JMan man( filename.toStdString().c_str() );
    QCOMPARE( man.getFilename(), filename.toStdString() );

    QFile file( filename  );
    if( QFileInfo::exists( filename ) )
        file.remove();

    qDebug( "Filename: %s\n", man.getFilename().c_str() );
    man._name="Gudjon";
    man._age=50;
    man.save();
    man._name="";
    man._age=0;
    man.load();
    QCOMPARE( man._name, "Gudjon" );
    QVERIFY( man._age == 50 );

}

QTEST_MAIN( test_JsonSave )

#include "tst_test_jsonsave.moc"
