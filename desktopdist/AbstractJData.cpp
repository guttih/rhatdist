#include "AbstractJData.h"

AbstractJData::AbstractJData()
{

}

AbstractJData::~AbstractJData()
{

}

String AbstractJData::toJsonValuePair( String name, String value )
{
    String str="\"";
    str+=name + "\":\"";
    str+=value + "\"";
    return str;
}

String AbstractJData::toJsonValuePair( String name, long value )
{
    String str="\"";
    str+=name + "\":";
    str+=std::to_string( value );
    return str;
}