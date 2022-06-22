#include "JStudent.h"

JStudent::JStudent()
{
}
JStudent::JStudent( Student data )
{
    set( data );
}
void JStudent::set( const Student &student )
{
    _data._name=student._name;
    _data._age=student._age;
}

JStudent::~JStudent()
{

}

std::string JStudent::toString()
{
    return _data.toString();
}

