#include "JMan.h"
#include "Json.h"
#include <string>
#include "String.h"
 #include <fstream>

JMan::JMan( const char *filename ) : JFile( filename )
{

}

JMan::~JMan()
{

}

bool JMan::load()
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
    }
    catch ( ... )
    {
        return false;
    }

    return true;

}

String JMan::toString()
{
    String str="{";
    str+=toJsonValuePair( "name", _name ) + ",";
    str+=toJsonValuePair( "age", _age );
    str+="}";
    return str;
}


