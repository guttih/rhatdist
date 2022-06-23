#include "JMan.h"
#include "Json.h"
#include <string>
#include "String.h"
 #include <fstream>

JMan::JMan( const char *filename )
{
    _filename = filename;
}

JMan::~JMan()
{

}

std::string JMan::getFilename()
{
    return _filename;
}

bool JMan::load()
{
    Json json( fileToString( _filename.c_str() ).c_str() );
    if( !json.isValid() )
        return false;
    JsonData *root=json.getRootObject();
    if( !root )
        return false;

    try
    {
        _name= root->getChild( "name" )->getValueAsString().c_str();
        _age= root->getChild( "age" )->getValueAsInt();
    }
    catch ( ... )
    {
        return false;
    }

    return true;

}

String JMan::fileToString( String filename )
{
    ifstream inFile;
    inFile.open( filename.c_str() ); //open the input file

    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file

    return strStream.str().c_str();

}

String JMan::toJsonValuePair( String name, String value )
{
    String str="\"";
    str+=name + "\":\"";
    str+=value + "\"";
    return str;
}

String JMan::toJsonValuePair( String name, long value )
{
    String str="\"";
    str+=name + "\":";
    str+=std::to_string( value );
    return str;
}

String JMan::toString()
{
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age );
    str+="}";
    return str;
}

bool JMan::save()
{
    FILE * fp;
    fp = fopen( getFilename().c_str(), "w" );
    fprintf( fp, "%s ", toString().c_str() );
    fclose( fp );
}

