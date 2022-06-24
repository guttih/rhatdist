#ifndef ABSTRACTJDATA_H
#define ABSTRACTJDATA_H

#pragma once

#include "IJData.h"
#include <iostream>
class AbstractJData : public IJData
{
public:
    AbstractJData();
    virtual ~AbstractJData();

protected:
    String toJsonValuePair( String name, String value );
    String toJsonValuePair( String name, long value );

};

#endif