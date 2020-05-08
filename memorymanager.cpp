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

MemoryManager::MemoryManager()
{

}

MemoryManager::MemoryManager(QVector<Segment> segments, QVector<Process> processes, bool is_best_fit)
{
    this->setSegments(segments);
    this->setProcesses(processes);
    this->setIs_best_fit(is_best_fit);
}

MemoryManager::MemoryManager(QVector<Segment> segments, bool is_best_fit)
{
    this->setSegments(segments);
    this->setIs_best_fit(is_best_fit);
}

MemoryManager::MemoryManager(bool is_best_fit)
{
    this->setIs_best_fit(is_best_fit);
}
