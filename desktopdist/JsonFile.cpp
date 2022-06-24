#include "JsonFile.h"


JsonFile::JsonFile( const char *fileName, AbstractJData *data )
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