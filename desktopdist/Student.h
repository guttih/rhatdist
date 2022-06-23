#ifndef STUDENT_H
#define STUDENT_H

#include "IJsonSaveData.h"

class Student : public IJsonSaveData
{
public:
    std::string _name;
    int _age;
    Student();
    Student( const Student &student );
    Student( std::string name, int age );
    void set( std::string name, int age );
    virtual std::string toString() const;
    virtual ~Student();

private:

};

#endif