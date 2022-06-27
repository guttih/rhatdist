#include "Person.h"


Person::Person()
{

}

void Person::set( std::string name, int age )
{
    _name = name;
    _age = age;
}
Person::Person( std::string name, int age )
{
    set( name, age  );
}

Person::Person( const Person &rhs )
{
    set( rhs._name, rhs._age ); //todo: Next line should be activated instead of this one
    // setFromJson( rhs.toJsonString().c_str() ); //Error: Why does this fail?  Is it because AbstractJsonFileData::toJsonString() is called instead of Person::toJsonString()
}

Person::~Person()
{

}

bool Person::getValues( JsonData *child, Person *storeValuesHere )
{

    string newName;
    int newAge;
    if( !child || child->getType() != JSONTYPE::JSONTYPE_OBJECT )
    {
        return false;
    }
    JsonData *prop=child->getChild( "name" );
    if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_STRING )
    {
        return false;
    }

    newName= prop->getValueAsString().c_str();

    prop=child->getChild( "age" );
    if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_ULONG )
    {
        return false;
    }
    newAge= prop->getValueAsInt();
    bool success = storeValuesHere->_age != JSONDATA_ERRORNUMBER;
    if( success )
        storeValuesHere->set( newName, newAge );

    return success;
}

bool Person::setFromJson( const char *jsonString )
{
    Json json( jsonString );

    if( !json.isValid() )
        return false;

    JsonData *root=json.getRootObject();
    if( !root )
        return false;

    return this->getValues( root, this );
}

String Person::toJsonString() const
{
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age );
    str+="}";
    return str;
}

