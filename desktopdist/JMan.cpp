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

bool JMan::save()
{
    String str="{\"name\":\"";
    str+=_name;
    str+="\",\"age\":";
    str+=std::to_string( _age );
    str+="}";

    FILE * fp;
    fp = fopen( getFilename().c_str(), "w" );
    fprintf( fp, "%s ", str.c_str() );
    fclose( fp );
}

