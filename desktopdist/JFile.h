#ifndef JFILE_H
#define JFILE_H

#pragma once

#include <iostream>
#include "String.h"

class JFile
{
public:
    JFile( const char *filename );
    virtual ~JFile();
    std::string getFilename();
    std::string _name;
    int _age;
    virtual bool save();
    virtual bool load() = 0;
    virtual String toString() = 0;

protected:
    std::string _filename;
    virtual String fileToString( String filename );
    String toJsonValuePair( String name, String value );
    String toJsonValuePair( String name, long value );

};

#endif
