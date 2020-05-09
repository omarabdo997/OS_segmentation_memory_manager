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

void Segment::set_status(bool value)
{
    status = value;
}

bool Segment::get_status()
{
    return status;
}
