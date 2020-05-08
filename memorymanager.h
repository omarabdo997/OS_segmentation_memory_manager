#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include "segment.h"
#include "allocator.h"
#include "sysprocess.h"

class MemoryManager
{
private:
    QVector<Segment> segments;
    QVector<Process> processes;
    bool is_best_fit;
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
};

#endif // MEMORYMANAGER_H
