#ifndef JSONFILE_H
#define JSONFILE_H

#pragma once

#include "AbstractJData.h"

class JsonFile
{
public:
    JsonFile( const char *fileName, AbstractJData *data );
    ~JsonFile();
    std::string getFilename();
    std::string toJsonString();

private:
    std::string _filename;
    AbstractJData *_pData = NULL;
};

#endif