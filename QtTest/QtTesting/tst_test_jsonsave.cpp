#include <QtTest>
#include <QCoreApplication>
#include <fstream>
#include "Person.h"
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

    void ReadJsonExampleFile();
    void Coll_SetAndGet();
    void Coll_SaveAndLoad();
    void Person_CopyConstructor();
    void Person_ComparisonOperators();
    void Persons_SaveAndLoad();
    void Coll_AddAndSave();
    void Coll_RemoveAndSave();
    void Coll_AddAndRemove();
    void Coll_Iterate();

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


void test_JsonSave::ReadJsonExampleFile()
{
    QString pathQ=qApp->applicationDirPath() + "/../example7.json";
    String path=pathQ.toStdString().c_str();
    qDebug( "Reading file %s\n", path.c_str() );

    ifstream inFile;
    inFile.open( path.c_str() );  //open the input file

    stringstream strStream;
    strStream << inFile.rdbuf();  //read the file

    std::string content = strStream.str().c_str();

    Json json( content.c_str() );
    QVERIFY( json.isValid() );
}




void test_JsonSave::Coll_SetAndGet()
{
    JsonFileDataCollection< Person > coll;
    QVERIFY( coll.count() == 0 );
    //todo: make this test for JsonFileDataCollection
    String orgJsonStr="[{\"name\":\"Gudjon\",\"age\":51},{\"name\":\"Orri\",\"age\":12}]";
    bool success = coll.setFromJson( orgJsonStr.c_str() );
    QVERIFY( coll.count() == 2 );
    String actualStr=coll.toJsonString();
    qDebug( "\norgJsonStr:%s\nactualStr :%s\n", orgJsonStr.c_str(), actualStr.c_str() );
    QVERIFY( success );
    QVERIFY( actualStr == orgJsonStr );
}

void test_JsonSave:: Person_CopyConstructor()
{
    Person gudjon( "Gudjon", 51 );
    Person orri( "Orri", 12 );
    orri=gudjon;
    QCOMPARE( gudjon.toJsonString().c_str(), orri.toJsonString().c_str() );
    QVERIFY( gudjon == orri );
    orri.set( "Orri", 11 );
    QCOMPARE( orri._name.c_str(), "Orri" );
    QVERIFY( orri._age == 11 );
    gudjon.setFromJson( orri.toJsonString().c_str() );
    QCOMPARE( gudjon.toJsonString().c_str(), orri.toJsonString().c_str() );
    QVERIFY( gudjon == orri );
}

void test_JsonSave::Coll_SaveAndLoad()
{
    Person_CopyConstructor();
    Person person;
    person._name="Gudjon"; person._age=51;
    JsonFileDataCollection< Person > coll( "coll-person.json" );
    coll.addItem( person );

    QVERIFY( coll.save() );
    coll.clear();
    QVERIFY( coll.count() == 0 );
    Person second;
    QVERIFY( coll.load() );
    QVERIFY( coll.getFirstItem( &second ) );
    QVERIFY( person == second );
}

void test_JsonSave::Persons_SaveAndLoad()
{
    QString filename="persons.json";

    QFile file( filename  );
    if( QFileInfo::exists( filename ) )
        file.remove();

    JsonFileDataCollection< Person > coll( filename.toStdString().c_str() );
    // Persons persons;
    QVERIFY( coll.count() == 0 );
    std::string orgJsonStr="[{\"name\":\"Gudjon\",\"age\":51},{\"name\":\"Orri\",\"age\":12}]";
    coll.setFromJson( orgJsonStr.c_str() );
    QVERIFY( coll.count() == 2 );
    QVERIFY( coll.save() );

    JsonFileDataCollection< Person > coll2;
    coll2.load( filename.toStdString().c_str() );
    QVERIFY( coll.count() == 2 );
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


void test_JsonSave::Person_ComparisonOperators()
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


void test_JsonSave::Coll_RemoveAndSave()
{
    //todo: make this test for JsonFileDataCollection
    JsonFileDataCollection< Person > coll( "coll-persons.json" );
    QVERIFY( coll.count() == 0 );
    coll.setFromJson( "[{\"name\":\"Gudjon\",\"age\":51},{\"name\":\"Sigurborg\",\"age\":45},{\"name\":\"Orri\",\"age\":12}]" );
    coll.save();

    QVERIFY( coll.count() == 3 );

    Person removeMe( "Sigurborg", 45 );
    coll.RemoveItem( removeMe );
    QVERIFY( coll.count() == 2 );

    JsonFileDataCollection< Person > coll2( "coll-persons.json" );
    coll2.load();
    QVERIFY( coll2.count() == 3 );

    while( coll2.getFirstItem( &removeMe ) )
    {
        coll2.RemoveItem( removeMe );
    }
    QVERIFY( coll2.count() == 0 );
    // QVERIFY( persons.count() == 0 );
    // jFile.load();
    // Person perTwo( "Gudjon", 51 );
    // persons.addItem( perTwo );
    // jFile.save();
    // jFile.load();
    // QVERIFY( persons.count() == 2 );
    // persons.RemoveItem( perTwo );
    // QVERIFY( persons.count() == 1 );
    // persons.RemoveItem( removeMe );
    // QVERIFY( persons.count() == 0 );
}


void test_JsonSave::Coll_Iterate()
{
    JsonFileDataCollection< Person > coll;
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
