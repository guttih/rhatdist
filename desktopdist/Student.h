#ifndef STUDENT_H
#define STUDENT_H

#include "JsonSaveData.h"

class Student : JsonSaveData
{
public:
    std::string _name;
    int _age;
    Student();
    Student( const Student &student );
    Student( std::string name, int age );
    void set( std::string name, int age );
    std::string toString();
    ~Student();

private:

};

#endif