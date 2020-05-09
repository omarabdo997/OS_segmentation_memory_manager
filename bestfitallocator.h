#ifndef BESTFITALLOCATOR_H
#define BESTFITALLOCATOR_H
#include "allocator.h"

class bestFitAllocator:public Allocator
{
public:

    bestFitAllocator();
    void allocate(Process s, QVector<Segment> &segments) override;
};

#endif // BESTFITALLOCATOR_H
