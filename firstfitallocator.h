#ifndef FIRSTFITALLOCATOR_H
#define FIRSTFITALLOCATOR_H
#include "allocator.h"

class firstFitAllocator: public Allocator
{
   bool isAllocated;
public:
    firstFitAllocator();
    void allocate(Process process, QVector<Segment> &segments) override;
    bool is_allocated();
};

#endif // FIRSTFITALLOCATOR_H
