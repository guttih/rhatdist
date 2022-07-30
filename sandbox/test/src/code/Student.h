#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
public:
    Student();
    Student( std::string name, int age, int enrolled );
    Student( const Student &rhs );
    bool operator==( const Student& right )
    {
        return ( this->toJsonString() == right.toJsonString() );
    }
    bool operator!=( const Student& right )
    {
        return !( *this == right );
    }
    std::string _name;
    int _age;
    int _enrolled;
    virtual bool setFromJson( const char *jsonString );
    virtual String toJsonString() const;
    virtual ~Student();
    static bool getValues( JsonData *child, Student *storeValuesHere );
    void set( std::string name, int age, int enrolled );

private:

};

#endif