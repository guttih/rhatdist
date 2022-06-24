#include <QtTest>
#include <QCoreApplication>
#include <fstream>
#include "Person.h"
#include "Persons.h"
#include "JsonFile.h"
#include "String.h"


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
    void Persons_SetAndGet();
    void Persons_SaveAndLoad();
    void Persons_AddAndSave();
    void Persons_RemoveAndSave();
    void Persons_Itterate();
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

void test_JsonSave::Persons_SetAndGet()
{
    Persons persons;
    QVERIFY( persons.count() == 0 );
    String orgJsonStr="[{\"name\":\"Gudjon\",\"age\":51},{\"name\":\"Orri\",\"age\":12}]";
    QVERIFY( persons.setFromJson( orgJsonStr.c_str() ) == true );
    QVERIFY( persons.count() == 2 );
    QCOMPARE( persons.toJsonString().c_str(), orgJsonStr.c_str() );

}
void test_JsonSave::Persons_SaveAndLoad()
{
    QString filename="persons.json";
    QFile file( filename  );
    if( QFileInfo::exists( filename ) )
        file.remove();

    Persons persons;
    QVERIFY( persons.count() == 0 );
    std::string orgJsonStr="[{\"name\":\"Gudjon\",\"age\":51},{\"name\":\"Orri\",\"age\":12}]";
    persons.setFromJson( orgJsonStr.c_str() );

    JsonFile jFile( filename.toStdString().c_str(), ( AbstractJData* ) &persons );
    jFile.save();

    Persons perTest;
    JsonFile jFile2( filename.toStdString().c_str(), ( AbstractJData* ) &perTest );
    jFile2.load();
    QVERIFY( persons.count() == 2 );
}

void test_JsonSave::Persons_AddAndSave()
{
    QString filename="persons.json";
    /*  QFile file( filename  );
     if( QFileInfo::exists( filename ) )
         file.remove();
 */
    Persons persons;
    Person p;
    p._name="Sigurborg"; p._age=45;
    QVERIFY( persons.count() == 0 );
    persons.addItem( p );
    QVERIFY( persons.count() == 1 );
    JsonFile jFile( filename.toStdString().c_str(), ( AbstractJData* ) &persons );
    jFile.save();

    Persons perTest;
    JsonFile jFile2( filename.toStdString().c_str(), ( AbstractJData* ) &perTest );
    jFile2.load();
    QVERIFY( persons.count() == 1 );
}

void test_JsonSave::Persons_RemoveAndSave()
{
    Persons_AddAndSave();
    Persons persons;
    QVERIFY( persons.count() == 0 );
    QString filename="persons.json";
    JsonFile jFile( filename.toStdString().c_str(), ( AbstractJData* ) &persons );
    jFile.load();
    QVERIFY( persons.count() == 1 );
    Person removeMe( "Sigurborg", 45 );
    persons.RemoveItem( removeMe );
    QVERIFY( persons.count() == 0 );
    jFile.load();
    Person perTwo( "Gudjon", 51 );
    persons.addItem( perTwo );
    jFile.save();
    jFile.load();
    QVERIFY( persons.count() == 2 );
    persons.RemoveItem( perTwo );
    QVERIFY( persons.count() == 1 );
    persons.RemoveItem( removeMe );
    QVERIFY( persons.count() == 0 );
}


void test_JsonSave::Persons_Itterate()
{
    Persons_AddAndSave();
    Persons persons;
    persons.addItem( Person( "One", 1 ) );
    persons.addItem( Person( "Two", 2 ) );
    persons.addItem( Person( "Three", 3 ) );
    QVERIFY( persons.count() == 3 );
    Person tmp;
    QVERIFY( persons.getFirstItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "One" );
    QVERIFY( tmp._age == 1 );

    QVERIFY( persons.getNextItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "Two" );
    ( tmp._age == 2 );

    QVERIFY( persons.getNextItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "Three" );
    QVERIFY( tmp._age == 3 );

    QVERIFY( persons.getNextItem( &tmp ) == false );
    QCOMPARE( tmp._name.c_str(), "Three" );
    QVERIFY( tmp._age == 3 );


}

QTEST_MAIN( test_JsonSave )

#include "tst_test_jsonsave.moc"
