#ifndef SEGMENT_H
#define SEGMENT_H
#include <QString>

class Segment
{
private:
    int from;
    int to;
    QString name;
    bool status;

public:
    Segment();
    Segment(int from,int to,QString name);
    void set_from(int value);
    int get_from();
    void set_to(int value);
    int get_to();
    void set_name(QString value);
    QString get_name();
    void set_status(bool value);
    bool get_status();
};

#endif // SEGMENT_H
