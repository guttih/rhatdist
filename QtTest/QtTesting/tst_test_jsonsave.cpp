#include <QtTest>
#include <QCoreApplication>
#include <fstream>
#include "Person.h"
#include "Persons.h"
#include "JsonFile.h"
#include "String.h"
#include "JsonFileDataCollection.h"

// add necessary includes here

class test_JsonSave : public QObject
{
Q_OBJECT

private:

public:
    test_JsonSave();
    ~test_JsonSave();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void Persons_SetAndGet();
    void Person_CopyConstructor();
    void Person_SaveAndLoad();
    void Persons_SaveAndLoad();
    void Persons_AddAndSave();
    void Persons_ComparisonOperators();
    void Coll_AddAndSave();
    void Persons_RemoveAndSave();
    void Coll_AddAndRemove();
    void Persons_Iterate();
    void Persons_Iterate2();
    void sandbox();

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

// String test_JsonSave::fileToString( String fullFilePath )
// {
//     ifstream inFile;
//     inFile.open( fullFilePath.c_str() );  //open the input file

//     stringstream strStream;
//     strStream << inFile.rdbuf();  //read the file

//     return strStream.str().c_str();

// }

// void test_JsonSave::test_readJsonExampleFile()
// {
//     QString path=qApp->applicationDirPath() + "/../example7.json";
//     qDebug( "Reading file %s\n", path.toStdString().c_str() );
//     Json json( fileToString( path.toStdString().c_str() ).c_str() );
//     QVERIFY( json.isValid() );
// }




void test_JsonSave::Persons_SetAndGet()
{
    Persons persons;
    QVERIFY( persons.count() == 0 );
    String orgJsonStr="[{\"name\":\"Gudjon\",\"age\":51},{\"name\":\"Orri\",\"age\":12}]";
    bool success = persons.setFromJson( orgJsonStr.c_str() );
    QVERIFY( persons.count() == 2 );
    String actualStr=persons.toJsonString();
    qDebug( "\norgJsonStr:%s\nactualStr :%s\n", orgJsonStr.c_str(), actualStr.c_str() );
    QVERIFY( success );
    QCOMPARE( actualStr.c_str(), orgJsonStr.c_str() );
}

void test_JsonSave:: Person_CopyConstructor()
{
    Person gudjon( "Gudjon", 51 );
    Person orri( "Orri", 12 );
    orri=gudjon;
    QCOMPARE( gudjon.toJsonString().c_str(), orri.toJsonString().c_str() );
    orri.set( "Orri", 11 );
    QCOMPARE( orri._name.c_str(), "Orri" );
    QVERIFY( orri._age == 11 );
    gudjon.setFromJson( orri.toJsonString().c_str() );
    QCOMPARE( gudjon.toJsonString().c_str(), orri.toJsonString().c_str() );
}

void test_JsonSave::Person_SaveAndLoad()
{
    Person person;
    person._name="Gudjon"; person._age=51;
    JsonFile jf( "person.json", ( AbstractJsonFileData* ) &person );
    QVERIFY( jf.save() );
    person._name=""; person._age=0;
    QVERIFY( jf.load() );
    QCOMPARE( person._name, "Gudjon" );
    QVERIFY( person._age == 51 );
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

    JsonFile jFile( filename.toStdString().c_str(), ( AbstractJsonFileData* ) &persons );
    jFile.save();

    Persons perTest;
    JsonFile jFile2( filename.toStdString().c_str(), ( AbstractJsonFileData* ) &perTest );
    jFile2.load();
    QVERIFY( persons.count() == 2 );
}


void test_JsonSave::Persons_Iterate()
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
    QVERIFY( tmp._age == 2 );

    QVERIFY( persons.getNextItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "Three" );
    QVERIFY( tmp._age == 3 );

    QVERIFY( !persons.getNextItem( &tmp )  );
    QCOMPARE( tmp._name.c_str(), "Three" );
    QVERIFY( tmp._age == 3 );
}

void test_JsonSave::Persons_AddAndSave()
{
    QString filename="persons.json";
    Persons persons;
    Person p;
    p._name="Sigurborg"; p._age=45;
    QVERIFY( persons.count() == 0 );
    persons.addItem( p );
    QVERIFY( persons.count() == 1 );
    JsonFile jFile( filename.toStdString().c_str(), ( AbstractJsonFileData* ) &persons );
    jFile.save();

    Persons perTest;
    JsonFile jFile2( filename.toStdString().c_str(), ( AbstractJsonFileData* ) &perTest );
    jFile2.load();
    QVERIFY( persons.count() == 1 );
}

void test_JsonSave::Coll_AddAndSave()
{
    QString filename="coll-persons.json";
    Person p( "Sigurborg", 45 );

    JsonFileDataCollection< Person > coll( filename.toStdString().c_str() );

    QVERIFY( coll.count() == 0 );
    coll.addItem( p );
    QVERIFY( coll.count() == 1 );
    QVERIFY( coll.save() == true );
    coll.clear();
    QVERIFY( coll.count() == 0 );
    coll.load();
    QVERIFY( coll.count() == 1 );
    Person test;
    coll.getFirstItem( &test );
    QVERIFY( test == p );
    QCOMPARE( test.toJsonString().c_str(), p.toJsonString().c_str() );

    //Test comparison operators
    QVERIFY( p == test );
    p._age=1;
    QVERIFY( !( p == test ) );

    //Test not equal operator
    QVERIFY( p != test );
    p._age=45;
    QVERIFY( p == test );
    QVERIFY( !( p != test ) );

}


void test_JsonSave::Persons_ComparisonOperators()
{
    Person p1( "Sigurborg", 45 ), p2( "Sigurborg", 45 );

    QVERIFY( p1 == p2 );
    QVERIFY( !( p1 != p2 ) );
    QCOMPARE( p1.toJsonString().c_str(), p2.toJsonString().c_str() );

    //Not equal
    p1._name="Bogga";
    QVERIFY( p1 != p2 );
    QVERIFY( !( p1 == p2 ) );
    QVERIFY( p1.toJsonString() != p2.toJsonString()  );

    //Equal again
    p2._name = p1._name;
    QVERIFY( p1 == p2 );
    QVERIFY( !( p1 != p2 ) );
    QVERIFY( p1.toJsonString() == p2.toJsonString()  );

}


void test_JsonSave::Persons_RemoveAndSave()
{
    Persons_AddAndSave();
    Persons persons;
    QVERIFY( persons.count() == 0 );
    QString filename="persons.json";
    JsonFile jFile( filename.toStdString().c_str(), ( AbstractJsonFileData* ) &persons );
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



void test_JsonSave::sandbox()
{
    JsonFileDataCollection< Person > coll;
    coll.addItem( Person( "Gudjon", 51 ) );
    coll.addItem( Person( "Sigurborg", 51 - 6 ) );
    coll.addItem( Person( "Orri", 12 ) );
    coll.print();
    qDebug( coll.toJsonString().c_str() );

}

void test_JsonSave::Persons_Iterate2()
{
    JsonFileDataCollection< Person > coll;
    Persons_AddAndSave();
    coll.addItem( Person( "One", 1 ) );
    coll.addItem( Person( "Two", 2 ) );
    coll.addItem( Person( "Three", 3 ) );
    QVERIFY( coll.count() == 3 );
    Person tmp;
    QVERIFY( coll.getFirstItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "One" );
    QVERIFY( tmp._age == 1 );

    QVERIFY( coll.getNextItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "Two" );
    QVERIFY( tmp._age == 2 );

    QVERIFY( coll.getNextItem( &tmp ) );
    QCOMPARE( tmp._name.c_str(), "Three" );
    QVERIFY( tmp._age == 3 );

    QVERIFY( coll.getNextItem( &tmp ) == false  );
    QCOMPARE( tmp._name.c_str(), "Three" );
    QVERIFY( tmp._age == 3 );
}
void test_JsonSave::Coll_AddAndRemove()
{
    JsonFileDataCollection< Person > coll;
    coll.addItem( Person( "One", 1 ) );
    QVERIFY( coll.count() == 1 );
    coll.RemoveItem( Person( "One", 1 ) );
    QVERIFY( coll.count() == 0 );
    coll.addItem( Person( "OneX", 1 ) );
    coll.addItem( Person( "TwoX", 2 ) );
    coll.addItem( Person( "ThreeX", 3 ) );
    QVERIFY( coll.count() == 3 );

    //should fail
    QVERIFY( !coll.RemoveItem( Person( "TwoX", 1 ) ) );
    QVERIFY( coll.count() == 3 );

    //should succeed
    coll.RemoveItem( Person( "TwoX", 2 ) );
    QVERIFY( coll.count() == 2 );

    coll.RemoveItem( Person( "ThreeX", 3 ) );
    QVERIFY( coll.count() == 1 );
    coll.RemoveItem( Person( "OneX", 1 ) );
    coll.print();
    QVERIFY( coll.count() == 0 );
    QCOMPARE( coll.toJsonString().c_str(), "[]" );
}

QTEST_MAIN( test_JsonSave )

#include "tst_test_jsonsave.moc"
