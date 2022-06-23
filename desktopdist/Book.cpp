#include "Book.h"

Book::Book()
{

}
Book::Book( std::string name, int year )
{
    init( name, year );
}


Book::~Book()
{

}

void Book::init( std::string name, int year )
{
    _name = name;
    _year = year;
}

std::string Book::toString() const
{

    std::string str=_name;
    str.append( ";" );
    str.append( std::to_string( _year ) );
    return str;
}