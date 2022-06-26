#ifndef PERSON_H
#define PERSON_H

#pragma once

#include "AbstractJsonFileData.h"

class Person : AbstractJsonFileData
{
public:
    Person();
    Person( std::string name, int age );
    Person( const Person &rhs );
    std::string _name;
    int _age;
    virtual bool setFromJson( const char *jsonString );
    virtual String toJsonString() const;
    virtual ~Person();
    static bool getValues( JsonData *child, Person *storeValuesHere );
    void set( std::string name, int age );

private:

};

#endif