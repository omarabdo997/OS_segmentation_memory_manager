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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void draw();
    void draw2();
    void clear(QVBoxLayout *layout);
    void delay();

private slots:


    void on_delete_process_clicked();

    void on_add_process_clicked();

    void on_number_segmants_button_clicked();


    void on_add_processes_comboBox_currentIndexChanged(const QString &arg1);

protected:
      void showEvent(QShowEvent *ev);



private:
    void showEventHelper();
    Ui::MainWindow *ui;
    int number_processes=0;
    QVector<QVector<QPair<QString,int>>>processes_values;
    QMap<QString,QVector<QPair<QLineEdit*,QLineEdit*>>>processes;
    void add_segmants_withBackUp(QString current_process, QVector<QPair<QString,int>>&back_up, int i);
    void add_segmants(QString current_process, int i);


};
#endif // MAINWINDOW_H
