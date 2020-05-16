#include "sysprocess.h"

Process::Process()
{

}
void Process::add_Segment(Segment s)
{
    Segments.push_back(s);
}

void Process::add_Segment(QString name, int start, int end)
{
    Segment segment(start,end,name);
    Segments.push_back(segment);
}
QVector<Segment> Process::getSegments() const
{
    return Segments;
}

void Process::setSegments(const QVector<Segment> &value)
{
    Segments = value;
}

QString Process::getName() const
{
    return name;
}

void Process::setName(const QString &value)
{
    name = value;
}


Segment Process::get_Segment(int from,int to,QString name)
{
    Segment segment(from,to,name);
    for(int i=0;i<Process::Segments.size();i++)
    {
        if(segment.get_to()==Segments[i].get_to()&&segment.get_from()==Segments[i].get_from()&&segment.get_name()==Segments[i].get_name())return Segments[i];
      }
    segment.set_name("Not Found");
    return segment;
}
void Process::remove_Segment(QString name,int start,int finish)
{
    Segment segment(start,finish,name);
    for(int i=0;i<Segments.size();i++)
    {
        if(segment.get_to()==Segments[i].get_to()&&segment.get_from()==Segments[i].get_from()&&segment.get_name()==Segments[i].get_name())
        {
            Segments.remove(i);
            return;
        }

    }
}

Process::Process(QString name, QVector<Segment> segments)
{
    this->name = name;
    this->Segments = segments;
}

Process::Process(QString name)
{
    this->name = name;
}

