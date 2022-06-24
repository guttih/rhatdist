#ifndef PERSONS_H
#define PERSONS_H


// #include "AbstractJData.h"
#include "Person.h"

// #include <iostream>
// #include <vector>

class Persons : AbstractJData
{
public:
    Persons();
    virtual bool setFromJson( const char *jsonString );
    String toJsonString();
    virtual ~Persons();

    unsigned int count();
    void clearData();
    bool addItem( Person const person );
    bool RemoveItem( Person person );
    bool getFirstItem( Person *person );
    bool getNextItem( Person *person );

private:
    std::vector< Person > _list;
    vector< Person >::iterator _itStepping;
};

#endif
