#ifndef JMAN_H
#define JMAN_H

#pragma once

#include <iostream>
#include "String.h"
#include "JFile.h"

class JMan : public JFile
{
public:
    JMan( const char *filename );
    virtual ~JMan();
    std::string _name;
    int _age;
    bool load();
    virtual String toString();

};

#endif
