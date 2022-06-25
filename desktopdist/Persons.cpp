#include "Persons.h"

Persons::Persons()
{

}

Persons::~Persons()
{
    _list.clear();

}

bool Persons::setFromJson( const char *jsonString )
{
    Json json( jsonString );

    if( !json.isValid() )
        return false;

    JsonData *root=json.getRootObject();
    if( !root || root->getType() != JSONTYPE::JSONTYPE_ARRAY )
        return false;

    JsonData *child, *prop;
    Person tmp;
    child=root->getChildAt( 0 );
    _list.clear();
    do
    {
        if( !Person::getValues( child, tmp ) )
            return false;
        // if( child->getType() != JSONTYPE::JSONTYPE_OBJECT )
        // {
        //     return false;
        // }
        // prop=child->getChild( "name" );
        // if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_STRING )
        // {
        //     return false;
        // }
        // tmp._name= prop->getValueAsString().c_str();

        // prop=child->getChild( "age" );
        // if( !prop || prop->getType() != JSONTYPE::JSONTYPE_KEY_VALUE || prop->getValueType() != JSONTYPE_ULONG )
        // {
        //     return false;
        // }

        // tmp._age= prop->getValueAsInt();
        _list.push_back( tmp );

        child=child->getNext();

    } while( child );

    return true;
}
String Persons::toJsonString()
{

    Person person;
    string ss="[";
    for( vector< Person >::iterator it=_list.begin(); it != _list.end(); it++ )
    {
        const string assa =  ( *it ).toJsonString().c_str();
        ss.append( assa );
        if( next( it ) != _list.end() )
        {
            ss.append( "," );
        }
    }
    ss.append( "]" );
    return ss;
}

unsigned int Persons::count()
{
    return _list.size();
}

void Persons::clearData()
{
    return _list.clear();
}

bool Persons::addItem( Person const person )
{
    _list.push_back( person );
}

bool Persons::RemoveItem( Person person )
{
    for( vector< Person >::iterator it=_list.begin(); it != _list.end(); it++ )
    {

        if( ( *it ).toJsonString() == person.toJsonString() )
        {
            _list.erase( it );
            return true;
        }
    }
    return false;
}


bool Persons::getFirstItem( Person *person )
{
    _itStepping=_list.begin();
    if( _itStepping != _list.end() )
    {
        person->_name=( *_itStepping )._name;
        person->_age= ( *_itStepping )._age;
        return true;
    }
    return false;
}
bool Persons::getNextItem( Person *person )
{
    _itStepping++;
    if( _itStepping != _list.end() )
    {
        person->_name=( *_itStepping )._name;
        person->_age= ( *_itStepping )._age;
        return true;
    }
    return false;
}