#ifndef JMAN_H
#define JMAN_H

#pragma once

#include <iostream>
#include "String.h"

class JMan
{
public:
    JMan( const char *filename );
    ~JMan();
    std::string getFilename();
    std::string _name;
    int _age;
    bool load();
    bool save();
    String toString();
private:
    std::string _filename;
    String fileToString( String filename );
    String toJsonValuePair( String name, String value );
    String toJsonValuePair( String name, long value );

};

#endif
