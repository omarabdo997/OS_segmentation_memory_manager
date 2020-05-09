#ifndef SEGMENT_H
#define SEGMENT_H
#include <QString>
#include <QVector>
class Segment
{
private:
    float from;
    float to;
    float size;
    QString name;
    bool isHole;
    QVector<QString> processesNames;
    int numProcesses;
    void set_numProcesses(int value);
public:
    Segment();
    Segment(int from,int to,QString name);
    void set_from(int value);
    int get_from();
    void set_to(int value);
    int get_to();
    void set_name(QString value);
    QString get_name();
    void set_isHole(bool value);
    bool get_isHole();
    void addProcessname(QString Name);
    QVector<QString> get_processesNames();
    void set_processesNames(QVector<QString> vec);
    int get_numProcesses();
    void free();
    float getSize() const;
    void setSize(float value);
};

#endif // SEGMENT_H
