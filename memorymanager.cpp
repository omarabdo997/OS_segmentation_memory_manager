#include "memorymanager.h"

bool MemoryManager::getIs_best_fit() const
{
    return is_best_fit;
}

void MemoryManager::setIs_best_fit(bool value)
{
    is_best_fit = value;
}

QVector<Process> MemoryManager::getProcesses() const
{
    return processes;
}

void MemoryManager::setProcesses(const QVector<Process> &value)
{
    processes = value;
}

QVector<Segment> MemoryManager::getSegments() const
{
    return segments;
}

void MemoryManager::setSegments(const QVector<Segment> &value)
{
    segments = value;
}

void MemoryManager::deallocate_segment(Segment s)
{
    allocator->deallocate(s,segments,s.get_processesNames()[0]);
}

void MemoryManager::deallocate_process(Process p)
{
    QVector<Segment> process_segments = p.getSegments();
    for(int i = 0 ; i<process_segments.size(); ++i)
        allocator->deallocate(process_segments[i], segments, p.getName());
}

MemoryManager::MemoryManager()
{

}

MemoryManager::MemoryManager(QVector<Segment> segments, QVector<Process> processes, bool is_best_fit)
{
    this->setSegments(segments);
    this->setProcesses(processes);
    this->setIs_best_fit(is_best_fit);
    MemoryManager::is_best_fit?allocator=new bestFitAllocator():allocator=new firstFitAllocator();
}

MemoryManager::MemoryManager(QVector<Segment> segments, bool is_best_fit)
{
    this->setSegments(segments);
    this->setIs_best_fit(is_best_fit);
    MemoryManager::is_best_fit?allocator=new bestFitAllocator():allocator=new firstFitAllocator();
}

MemoryManager::MemoryManager(bool is_best_fit)
{
    this->setIs_best_fit(is_best_fit);
   MemoryManager::is_best_fit?allocator=new bestFitAllocator():allocator=new bestFitAllocator();
}
