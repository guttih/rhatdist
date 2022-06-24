#ifndef PERSON_H
#define PERSON_H

#pragma once

#include "AbstractJData.h"

class Person : AbstractJData
{
public:
    Person();
    Person( std::string name, int age );
    std::string _name;
    int _age;
    virtual bool setFromJson( const char *jsonString );
    virtual String toJsonString();
    virtual ~Person();
    static bool getValues( JsonData *child, Person &storeValuesHere );

private:

};

#endif