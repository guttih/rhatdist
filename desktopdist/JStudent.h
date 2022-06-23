#ifndef JSTUDENT_H
#define JSTUDENT_H

#pragma once

#include "JMan.h"
class JStudent : public JMan
{
public:
    JStudent( const char *filename );
    ~JStudent();
    bool load();
    virtual String toString();
    int _enrolled;

private:

};

#endif