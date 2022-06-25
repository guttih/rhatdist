#ifndef ABSTRACTJDATA_H
#define ABSTRACTJDATA_H

// #pragma once

#include "IJsonFileData.h"
#include "NotImplementedException.h"
#include <iostream>
class AbstractJsonFileData : public IJsonFileData
{
public:
    AbstractJsonFileData();
    virtual ~AbstractJsonFileData();

protected:
    String toJsonValuePair( String name, String value );
    String toJsonValuePair( String name, long value );

};

#endif
