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
    // throw NotImplemented( __FUNCTION__ );
    Json json( jsonString );

    if( !json.isValid() )
        return false;

    JsonData *root=json.getRootObject();
    if( !root )
        return false;

    try
    {
        JsonData *child;

        child=root->getChild( "name" );
        if( !child || child->getType() != JSONTYPE::JSONTYPE_KEY_VALUE )
            return false;
        _name= child->getValueAsString().c_str();
        child=root->getChild( "age" );
        if( !child || child->getType() != JSONTYPE::JSONTYPE_KEY_VALUE )
            return false;
        _age= child->getValueAsInt();
    }
    catch ( ... )
    {
        return false;
    }

    return true;

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
