#ifndef PERSON_H
#define PERSON_H

#pragma once

#include "AbstractJData.h"

class Person : AbstractJData
{
public:
    Person();
    std::string _name;
    int _age;
    virtual bool setFromJson( const char *jsonString );
    virtual String toJsonString();
    virtual ~Person();

private:

};

#endif