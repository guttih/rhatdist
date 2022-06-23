#ifndef JFILE_H
#define JFILE_H

#pragma once

#include <iostream>
#include "String.h"

class JFile
{
public:
    JFile( const char *filename );
    ~JFile();
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
