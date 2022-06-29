#include "Student.h"


Student::Student()
{

}

void Student::set( std::string name, int age, int enrolled )
{
    _name = name;
    _age = age;
    _enrolled = enrolled;
}
Student::Student( std::string name, int age, int enrolled )
{
    set( name, age, enrolled  );
}

Student::Student( const Student &rhs ) : Person( rhs )
{
    setFromJson( rhs.toJsonString().c_str() );
}

Student::~Student()
{

}

bool Student::getValues( JsonData *child, Student *storeValuesHere )
{

    string newName;
    int newAge, newEnrolled;
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

    prop=child->getChild( "enrolled" );
    if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_ULONG )
    {
        return false;
    }
    newEnrolled= prop->getValueAsInt();

    if( JSONDATA_ERRORNUMBER == storeValuesHere->_age || storeValuesHere->_enrolled == JSONDATA_ERRORNUMBER )
    {
        return false;
    }

    storeValuesHere->set( newName, newAge, newEnrolled );

    return true;
}

bool Student::setFromJson( const char *jsonString )
{
    Json json( jsonString );

    if( !json.isValid() )
        return false;

    JsonData *root=json.getRootObject();
    if( !root )
        return false;

    return this->getValues( root, this );
}

String Student::toJsonString() const
{
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age ) + ",";
    str+=toJsonValuePair( "enrolled", _enrolled );
    str+="}";
    return str;
}

