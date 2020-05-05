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
    void clear(QVBoxLayout *layout);
    void delay();

private slots:


    void on_delete_process_clicked();

    void on_add_process_clicked();

protected:
      void showEvent(QShowEvent *ev);



private:
    void showEventHelper();
    Ui::MainWindow *ui;
    int number_processes=0;


};
#endif // MAINWINDOW_H
