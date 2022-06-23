#include "JFile.h"
#include "Json.h"
#include <string>
#include "String.h"
 #include <fstream>

JFile::JFile( const char *filename )
{
    _filename = filename;
}

JFile::~JFile()
{

}

std::string JFile::getFilename()
{
    return _filename;
}

String JFile::fileToString( String filename )
{
    ifstream inFile;
    inFile.open( filename.c_str() ); //open the input file

    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file

    return strStream.str().c_str();

}

String JFile::toJsonValuePair( String name, String value )
{
    String str="\"";
    str+=name + "\":\"";
    str+=value + "\"";
    return str;
}

String JFile::toJsonValuePair( String name, long value )
{
    String str="\"";
    str+=name + "\":";
    str+=std::to_string( value );
    return str;
}


bool JFile::save()
{
    FILE * fp;
    fp = fopen( getFilename().c_str(), "w" );
    fprintf( fp, "%s ", toString().c_str() );
    fclose( fp );
}

