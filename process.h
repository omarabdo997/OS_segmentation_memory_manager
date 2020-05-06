#ifndef PROCESS_H
#define PROCESS_H
#include<QVector>
#include "segment.h"
class Process
{
   QVector<Segment>Segments;
public:
   Segment get_Segment(int from,int to,QString name);
   void add_Segment(QString name,int start,int end);
   void remove_Segment(QString name,int start,int end);
    Process();
};

#endif // PROCESS_H
