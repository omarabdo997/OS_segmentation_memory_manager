#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "segment.h"

class Allocator
{
public:
    Allocator();
    virtual void allocate(Segment s, QVector<Segment>& segments)=0;
    void deallocate(Segment s, QVector<Segment>& segments);
};

#endif // ALLOCATOR_H
