#include "Student.h"

Student::Student()
{
}

Student::Student( const Student &student )
{
    set( student._name, student._age );
}

Student::Student( std::string name, int age )
{
    set( name, age );
}

Student::~Student()
{

}

void Student::set( std::string name, int age )
{
    _name=name;
    _age=age;
}

std::string Student::toString()
{

    std::string str=_name;
    str.append( ";" );
    str.append( std::to_string( _age ) );
    return str;
}