#ifndef IJDATA_H
#define IJDATA_H

#pragma once

#include "String.h"
#include "Json.h"

class IJsonFileData
{
public:
    virtual bool setFromJson( const char *jsonString ) = 0;
    virtual String toJsonString() = 0;

private:

};

#endif
