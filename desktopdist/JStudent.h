#ifndef JSTUDENT_H
#define JSTUDENT_H

#pragma once

#include "Student.h"
#include "JsonSave.h"

class JStudent : JsonSave
{
public:
    JStudent();
    JStudent( Student data );
    ~JStudent();

    void set( const Student &student );
    std::string toString();

private:
    Student _data;

};

#endif