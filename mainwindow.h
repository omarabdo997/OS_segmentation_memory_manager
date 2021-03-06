#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "segmentationselector.h"
#include <QApplication>
#include <QListWidgetItem>
#include <QListWidget>
#include <QList>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>
#include <QMap>
#include <QtAlgorithms>
#include "segment.h"
#include <QMessageBox>
#include "memorymanager.h"
#include <QTextLine>
#include <QScrollBar>
#include <string>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void draw(QVector<Segment>segments);
    void draw2();
    void clear(QVBoxLayout *layout);
    void delay();

private slots:


    void on_delete_process_clicked();

    void on_add_process_clicked();

    void on_number_segmants_button_clicked();


    void on_add_processes_comboBox_currentIndexChanged(const QString &arg1);

    void on_submit_button_clicked();

    void on_processes_combo_box_currentIndexChanged(const QString &arg1);

    void on_actionNew_triggered();

    void on_actionExit_triggered();

protected:
      void showEvent(QShowEvent *ev);



private:
    SegmentationSelector s;
    void showEventHelper();
    Ui::MainWindow *ui;
    int number_processes=0;
    QVector<QVector<QPair<QString,int>>>processes_values;
    QMap<QString,QVector<QPair<QLineEdit*,QLineEdit*>>>processes;
    void add_segmants_withBackUp(QString current_process, QVector<QPair<QString,int>>&back_up, int i);
    void add_segmants(QString current_process, int i);
    QVector<QPair<float,float>>holes_values;
    float memory_size;
    MemoryManager MM;
    QMap<QString,QVector<Segment>>process_segment_results;
    QVector<Process>processes_for_dealocate;
    QMap<QString,QColor>p_color;

    bool isFloat(const std::string& s)
    {
        int points=0;
        std::string::const_iterator it = s.begin();
        while (it != s.end() && (std::isdigit(*it) or ((*it)=='.')))
        {
            if((*it)=='.')
            {
                points++;
            }
            ++it;
        }
        return !s.empty() && it == s.end() && points<=1 && s.back()!='.';
    }
    bool isInt(const std::string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]) == false)
                return false;

        return true;
    }


};
#endif // MAINWINDOW_H
