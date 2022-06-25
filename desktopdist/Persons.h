#ifndef PERSONS_H
#define PERSONS_H


#include "Person.h"
#include "AbstractJsonFileDataCollection.h"

class Persons : AbstractJsonFileDataCollection
{
public:
    Persons();
    virtual bool setFromJson( const char *jsonString );
    virtual String toJsonString();
    virtual ~Persons();

    unsigned int count();
    void clearData();
    void addItem( Person const person );
    bool RemoveItem( Person const person );
    bool getFirstItem( Person *person );
    bool getNextItem( Person *person );

private:
    std::vector< Person > _list;
    vector< Person >::iterator _itStepping;
};

#endif
