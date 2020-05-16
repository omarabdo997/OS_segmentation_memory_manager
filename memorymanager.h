#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include "segment.h"
#include "allocator.h"
#include "sysprocess.h"
#include "firstfitallocator.h"
#include"bestfitallocator.h"
class MemoryManager
{
private:
    QVector<Segment> segments;
    QVector<Process> processes;
    bool is_best_fit;
    Allocator* allocator;
public:
    MemoryManager();
    MemoryManager(QVector<Segment> segments, QVector<Process> processes,bool is_best_fit);
    MemoryManager(QVector<Segment> segments, bool is_best_fit);
    MemoryManager(bool is_best_fit);
    bool getIs_best_fit() const;
    void setIs_best_fit(bool value);
    QVector<Process> getProcesses() const;
    void setProcesses(const QVector<Process> &value);
    QVector<Segment> getSegments() const;
    void setSegments(const QVector<Segment> &value);
    void deallocate_segment(Segment s);
    void deallocate_process(Process p);
    void allocate_process(Process process);
    bool isAlocated();
    Allocator *getAllocator() const;
};

#endif // MEMORYMANAGER_H
