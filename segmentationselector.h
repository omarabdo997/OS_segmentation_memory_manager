#ifndef SEGMENTATIONSELECTOR_H
#define SEGMENTATIONSELECTOR_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVector>
#include <QPair>
#include <QFont>
#include <QDebug>
#include <QComboBox>
#include <memorymanager.h>
#include <QMessageBox>

namespace Ui {
class SegmentationSelector;
}

class SegmentationSelector : public QDialog
{
    Q_OBJECT

public:
    explicit SegmentationSelector(QWidget *parent = nullptr);
    ~SegmentationSelector();



    bool getRdy() const;

    int getNumber_holes() const;

    int getNumber_processes() const;

    float getMemory_size() const;

    QVector<QPair<float, float> > getHoles_values() const;

//    QVector<QVector<QPair<QString, int> > > getProcesses_values() const;

    int getAllocation_algorithm() const;

//    void setNumber_processes(int value);

    MemoryManager getMM() const;

    void setRdy(bool value);

private slots:
    void on_next_first_button_clicked();

    void on_next_second_button_clicked();

//    void on_number_segmants_button_clicked();

//    void on_processes_combo_box_currentIndexChanged(int index);

    void on_back_second_button_clicked();

//    void on_back_third_button_clicked();

//    void on_next_third_button_clicked();

private:
    Ui::SegmentationSelector *ui;
    bool rdy;
    int number_holes;
    int number_processes;
    float memory_size;
    QVector<QPair<QLineEdit*,QLineEdit*>>holes;
    QVector<QPair<float,float>>holes_values;
//    QVector<QVector<QPair<QLineEdit*,QLineEdit*>>>processes;
//    QVector<QVector<QPair<QString,int>>>processes_values;
    int allocation_algorithm;
    int FIRST_TIME=1;
    void create_hole_form(int i,float starting_address=-1,float size=-1);
    MemoryManager MM;

};

#endif // SEGMENTATIONSELECTOR_H
