#ifndef BOOK_H
#define BOOK_H

#include "IJsonSaveData.h"

class Book : public IJsonSaveData
{
public:
    std::string _name;
    int _year;
    Book();
    Book( std::string name, int year );
    virtual ~Book();
    virtual std::string toString() const;

private:
    void init( std::string name, int year );

};

#endif