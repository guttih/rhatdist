#include "AbstractJsonFileData.h"

AbstractJsonFileData::AbstractJsonFileData()
{

}

AbstractJsonFileData::~AbstractJsonFileData()
{

}

String AbstractJsonFileData::toJsonValuePair( String name, String value )
{
    String str="\"";
    str+=name + "\":\"";
    str+=value + "\"";
    return str;
}

String AbstractJsonFileData::toJsonValuePair( String name, long value )
{
    String str="\"";
    str+=name + "\":";
    str+=std::to_string( value );
    return str;
}