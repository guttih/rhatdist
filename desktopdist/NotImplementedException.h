#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H

#pragma once

#define NOT_IMPLEMENTED throw NotImplementedException( __PRETTY_FUNCTION__ );

#include <string>

/**
 * @brief Throw this exception when your function has been declared but not implemented yet.
 *
 * Usage example 1:
 *    bool Person::setFromJson( const char *jsonString )
*     {
*          NOT_IMPLEMENTED
*     }
* Usage example 2:
 *    bool Person::setFromJson( const char *jsonString )
*     {
*          throw NotImplementedException( __PRETTY_FUNCTION__ );
*     }
 */
class NotImplementedException : public std::logic_error
{
private:

    std::string _text;

    NotImplementedException( const char* message, const char* function )
        :
        std::logic_error( "Not Implemented" )
    {
        _text = message;
        _text += " : ";
        _text += function;
    };

public:

    NotImplementedException()
        :
        NotImplementedException( "Not Implememented", __FUNCTION__ )
    {
    }

    NotImplementedException( const char* message )
        :
        NotImplementedException( message, __FUNCTION__ )
    {
    }

    virtual const char *what() const throw ( )
    {
        return _text.c_str();
    }
};

#endif


