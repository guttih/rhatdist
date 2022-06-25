#include "Person.h"


Person::Person()
{

}

Person::Person( std::string name, int age )
{
    _name = name;
    _age = age;
}

Person::~Person()
{

}

bool Person::getValues( JsonData *child, Person &storeValuesHere )
{

    if( !child || child->getType() != JSONTYPE::JSONTYPE_OBJECT )
    {
        return false;
    }
    JsonData *prop=child->getChild( "name" );
    if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_STRING )
    {
        return false;
    }

    storeValuesHere._name= prop->getValueAsString().c_str();

    prop=child->getChild( "age" );
    if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_ULONG )
    {
        return false;
    }
    storeValuesHere._age= prop->getValueAsInt();

    return storeValuesHere._age != JSONDATA_ERRORNUMBER;
}

bool Person::setFromJson( const char *jsonString )
{
    Json json( jsonString );

    if( !json.isValid() )
        return false;

    JsonData *root=json.getRootObject();
    if( !root )
        return false;

    return this->getValues( root, *this );
}

String Person::toJsonString()
{
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age );
    str+="}";
    return str;
}
