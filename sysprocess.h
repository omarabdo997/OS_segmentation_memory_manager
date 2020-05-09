#ifndef PROCESS_H
#define PROCESS_H
#include<QVector>
#include "segment.h"
class Process
{
private:
   QVector<Segment>Segments;
   QString name;
public:
   void add_Segment(Segment s);
   void add_Segment(QString name,int start,int end);
   void remove_Segment(QString name,int start,int end);
   Segment get_Segment(int from,int to,QString name);
   Process(QString name, QVector<Segment>segments);
   Process(QString name);
   Process();
   QString getName() const;
   void setName(const QString &value);
   QVector<Segment> getSegments() const;
   void setSegments(const QVector<Segment> &value);
};

#endif // PROCESS_H
