#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    SegmentationSelector s;
    s.exec();

    if(s.getRdy())
    {
        ui->setupUi(this);
    }
    else
    {
        this->~MainWindow();
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

