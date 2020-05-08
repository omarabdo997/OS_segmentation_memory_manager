#ifndef PROCESS_H
#define PROCESS_H
#include<QVector>
#include "segment.h"
class Process
{
   QVector<Segment>Segments;
public:
   QString name;
   Segment get_Segment(int from,int to,QString name);
   void add_Segment(QString name,int start,int end);
   void remove_Segment(QString name,int start,int end);
   Process(QString name, QVector<Segment>Segments);
   Process(QString name);
   Process();
   QString getName() const;
   void setName(const QString &value);
};

#endif // PROCESS_H
