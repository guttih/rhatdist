#include "Person.h"
#include "NotImplemented.h"

Person::Person()
{

}

Person::~Person()
{

}


bool Person::setFromJson( const char *jsonString )
{
    throw NotImplemented( __FUNCTION__ );
    Json json( jsonString );
    if( !json.isValid() )
        return false;

}

String Person::toJsonString()
{
    // throw NotImplemented( __FUNCTION__ );
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age );
    str+="}";
    return str;
}