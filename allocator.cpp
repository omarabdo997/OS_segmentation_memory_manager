#include "allocator.h"

void Allocator::setIsAllocated(bool value)
{
    isAllocated = value;
}

void Allocator::merge(int index, QVector<Segment> &segments, bool before)
{
    if(before)
    {
        if(segments[index-1].get_isHole())
        {
            segments[index].set_from(segments[index-1].get_from());
            segments.remove(index-1);
        }
    }
    else
    {
        if(segments[index+1].get_isHole())
        {
            segments[index].set_to(segments[index+1].get_to());
            segments.remove(index+1);
        }
    }
}
bool Allocator::is_allocated()
{
    return isAllocated;
}

Allocator::Allocator()
{
isAllocated=true;
}

void Allocator::deallocate(Segment s, QVector<Segment> &segments, QString pName = "")
{
    for(int i = 0 ; i < segments.size() ; ++i)
    {
        if((s.get_name() == segments[i].get_name()) && (s.get_processesNames() == segments[i].get_processesNames()))
        {
            if(segments[i].get_numProcesses() > 1 && pName != "")
            {
                QVector<QString> temp =  segments[i].get_processesNames();
                for(int k = 0 ; k < segments[i].get_numProcesses() ; ++k)
                {
                    if(temp[i] == pName)
                    {
                        temp.remove(i);
                        segments[i].set_processesNames(temp);
                        break;
                    }
                }
            }
            else
            {
                segments[i].free();
                if(i==0 && segments.size()==1)
                {}
                else if (i == 0 && segments.size() > 1)
                    merge(i,segments,0);
                else if(i == segments.size()-1)
                    merge(i,segments,1);
                else
                {
                    merge(i,segments,0);
                    merge(i,segments,1);
                }
            }
            return;
        }
    }
}

