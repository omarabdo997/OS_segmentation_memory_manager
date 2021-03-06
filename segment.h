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
    Segment(float size,QString name);
    Segment(float from, float to, QString name);
    void set_from(float value);
    float get_from();
    void set_to(float value);
    float get_to();
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
