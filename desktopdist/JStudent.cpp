#include "JStudent.h"

JStudent::JStudent( const char *filename ) : JMan( filename )
{
}

JStudent::~JStudent()
{

}

bool JStudent::load()
{
    Json json( fileToString( _filename.c_str() ).c_str() );

    if( !json.isValid() )
        return false;

    JsonData *root=json.getRootObject();

    if( !root )
        return false;

    try
    {
        _name= root->getChild( "name" )->getValueAsString().c_str();
        _age= root->getChild( "age" )->getValueAsInt();
        _enrolled= root->getChild( "enrolled" )->getValueAsInt();
    }
    catch ( ... )
    {
        return false;
    }

    return true;

}

String JStudent::toString()
{
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age ) + ",";
    str+=toJsonValuePair( "enrolled", _enrolled );
    str+="}";
    return str;
}

