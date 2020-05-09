#ifndef BESTFITALLOCATOR_H
#define BESTFITALLOCATOR_H
#include "allocator.h"

class bestFitAllocator:public Allocator
{
    bool isAllocated;
public:

    bestFitAllocator();
    void allocate(Process s, QVector<Segment> &segments) override;
    bool is_allocated();
};

#endif // BESTFITALLOCATOR_H
