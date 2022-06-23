#ifndef IJSONSAVEDATA_H
#define IJSONSAVEDATA_H

#include <iostream>

class IJsonSaveData
{
public:
    IJsonSaveData();
    virtual ~IJsonSaveData();
    virtual std::string toString() const = 0;

private:

};

#endif