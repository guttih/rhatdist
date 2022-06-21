#include "mainwindow.h"
#include <QtXml>
#include <QtCore>
#include <iostream>
#include <QIODevice>

#include <QApplication>

#include "appsettings.h"
#include "JsonSave.h"

using namespace std;

struct Book
{
    string name;
    double price;
    Book( string _name, double _price )
    {
        name = _name;
        price = _price;
    }
};

void CreateJson( const QString &path )
{
    Book obj1( "high school mathematics", 12 );
    QJsonObject book1;
    book1.insert( "name", obj1.name.c_str() );
    book1.insert( "price", obj1.price );

    Book obj2( "advanced high school mathematics", 14 );
    QJsonObject book2;
    book2.insert( "name", obj2.name.c_str() );
    book2.insert( "price", obj2.price );

    QJsonObject content;
    content.insert( "book1", book1 );
    content.insert( "book2", book2 );

    QJsonDocument document;
    document.setObject( content );
    QByteArray bytes = document.toJson( QJsonDocument::Indented );
    QFile file( path );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );
        iStream.setEncoding( QStringConverter::Utf8 );
        iStream << bytes;
        file.close();
    }
    else
    {
        cout << "file open failed: " << path.toStdString() << endl;
    }
}

void ReadJson( const QString &path )
{
    QFile file( path );
    if( file.open( QIODevice::ReadOnly ) )
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
        if( jsonError.error != QJsonParseError::NoError )
        {
            cout << "fromJson failed: " << jsonError.errorString().toStdString() << endl;
            return;
        }
        if( document.isObject() )
        {
            QJsonObject jsonObj = document.object();
            QStringList books;
            books << "book1" << "book2";
            for( auto book: books )
            {
                if( jsonObj.contains( book ) )
                {
                    QJsonObject obj = jsonObj.value( book ).toObject();
                    QStringList keys = obj.keys();
                    for( auto key: keys )
                    {
                        auto value = obj.take( key );
                        if( value.isDouble() )
                        {
                            qDebug() << key << " : " << value.toDouble();
                        }
                        else if( value.isString() )
                        {
                            qDebug() << key << " : " << value.toString();
                        }

                    }
                }
            }
        }
    }
}
//"/home/gudjon/repo/rhatdist/build-desktopdist-Desktop_Qt_6_2_4_GCC_64bit-Debug/settings.json"
int main( int argc, char *argv[] )
{

    /*
    Vill geta búið til grunn settings klasa sem vinnur með
    grunn setttings object
    sem aðrir klasar erfa og bæta við sínum eigin objectum

    */
    QApplication a( argc, argv );
    MainWindow w;

    JsonSave xx;
    xx.i=4;

    QString path=qApp->applicationDirPath(),
            settingsPath;

    //path="/home/gudjon/devel/qt/untitled3";
    settingsPath=path + "/settings.json";
    AppSettings settings( settingsPath.toStdString() );
    qDebug() << "App path:" + path;
    qDebug() << "setting :" + settingsPath;
    QString str= QString::fromStdString( settings.getFilePath() );
    qDebug() << "settings.getFilePath():" + str;



    qDebug() << "App path:" + path;
    qDebug() << "Settings:" + settingsPath;
    qDebug() << "settings.getDirPath():" + str;

    CreateJson( settingsPath );
    ReadJson( settingsPath );
    w.show();
    return a.exec();
}
