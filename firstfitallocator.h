#ifndef FIRSTFITALLOCATOR_H
#define FIRSTFITALLOCATOR_H
#include "allocator.h"

class firstFitAllocator: public Allocator
{
public:
    firstFitAllocator();
    void allocate(Process process, QVector<Segment> &segments) override;
};

#endif // FIRSTFITALLOCATOR_H
