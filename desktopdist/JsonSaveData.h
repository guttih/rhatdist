#ifndef IJSONSAVEDATA_H
#define IJSONSAVEDATA_H

#include <iostream>

class IJsonSaveData
{
public:
    IJsonSaveData();
    virtual ~IJsonSaveData();
    virtual std::string toString() = 0;

private:

};

#endif