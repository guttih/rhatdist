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

    JsonData *child;
    Person tmp;
    child=root->getChildAt( 0 );
    _list.clear();
    do
    {
        if( !Person::getValues( child, &tmp ) )
            return false;

        _list.push_back( tmp );

        child=child->getNext();

    } while( child );

    return true;
}
String Persons::toJsonString() const
{

    Person person;
    string ss="[";
    for( auto it=_list.begin(); it != _list.end(); it++ )
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

void Persons::addItem( Person const person )
{
    _list.push_back( person );
}

bool Persons::RemoveItem( Person const person )
{
    String jsonStringToMatch=Person( person._name, person._age ).toJsonString();
    for( vector< Person >::iterator it=_list.begin(); it != _list.end(); it++ )
    {

        if( ( *it ).toJsonString() == jsonStringToMatch )
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
