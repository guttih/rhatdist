#ifndef JSONFILE_H
#define JSONFILE_H

#pragma once

#include "AbstractJsonFileData.h"

class JsonFile
{
public:
    JsonFile( const char *fileName, AbstractJsonFileData *data );
    ~JsonFile();
    std::string getFilename();
    std::string toJsonString() const;
    std::string fileToString( const char *fileName );
    bool save();
    bool load();

private:
    std::string _filename;
    AbstractJsonFileData *_pData = NULL;
};

#endif