#include "segment.h"

Segment::Segment()
{

}

Segment::Segment(int from,int to,QString name)
{
    this->set_from(from);
    this->set_to(to);
    this->set_name(name);
}

void Segment::set_to(int value)
{
    to = value;
}

int Segment::get_to()
{
    return to;
}

void Segment::set_from(int value)
{
    from  = value;
}

int Segment::get_from()
{
    return from;
}

void Segment::set_name(QString value)
{
    name = value;
}

QString Segment::get_name()
{
    return name;
}

void Segment::set_isHole(bool value)
{
    isHole = value;
}

bool Segment::get_isHole()
{
    return isHole;
}

int Segment::get_numProcesses()
{
    return numProcesses;
}

void Segment::free()
{
    this->set_isHole(1);
    this->set_name("FREE");
}

float Segment::getSize() const
{
    return size;
}

void Segment::setSize(float value)
{
    size = value;
}

void Segment::set_numProcesses(int value)
{
    numProcesses =  value;
}

void Segment::set_processesNames(QVector<QString> vec)
{
    processesNames = vec;
    set_numProcesses(processesNames.size());
}

QVector<QString> Segment::get_processesNames()
{
    return processesNames;
}


void Segment::addProcessname(QString Name)
{
    processesNames.push_back(Name);
    numProcesses++;
}
