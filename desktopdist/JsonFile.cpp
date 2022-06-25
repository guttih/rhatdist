#include "JsonFile.h"
 #include <fstream>

JsonFile::JsonFile( const char *fileName, AbstractJsonFileData *data )
{
    _filename=fileName;
    _pData=data;
}

JsonFile::~JsonFile()
{

}

std::string JsonFile::getFilename()
{
    return _filename;
}

std::string JsonFile::toJsonString()
{
    std::string ret = _pData->toJsonString().c_str();
    return ret;
}

bool JsonFile::save()
{
    FILE * fp;
    fp = fopen(  getFilename().c_str(), "w" );
    if( !fp )
        return false;
    int cnt = fprintf( fp, "%s ", toJsonString().c_str() );
    fclose( fp );
    return cnt > 0;
}

std::string JsonFile::fileToString( const char *fileName )
{
    ifstream inFile;
    inFile.open( fileName ); //open the input file

    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file

    return strStream.str();

}

bool JsonFile::load()
{
    return _pData->setFromJson( fileToString( getFilename().c_str() ).c_str() );
}
