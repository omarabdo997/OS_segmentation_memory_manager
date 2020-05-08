#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    SegmentationSelector s;
    s.exec();
    number_processes=s.getNumber_processes();
    ui->setupUi(this);
    setMinimumSize(1000,600);
    ui->memory_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->ruler_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    QFont font_12("times",12);
    ui->processes_list->setFont(font_12);
    ui->processes_combo_box->setFont(font_12);
    for(int i=0;i<number_processes;i++)
    {
        ui->processes_list->addItem("Process "+QString::number(i+1));
        ui->processes_combo_box->addItem("Process "+QString::number(i+1));
    }
    if(!s.getRdy())
    {
        this->~MainWindow();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw()
{

    clear(ui->memory_layout);
    clear(ui->ruler_layout);
    QFont font_14("times",14);
    QPalette color;
    int scale=1;
    QLabel *zero_ruler=new QLabel("0");
    zero_ruler->setMinimumHeight(10);
    zero_ruler->setMaximumHeight(10);
    ui->ruler_layout->addWidget(zero_ruler);

     for(int i=0;i<10;i++)
     {
         QLabel *label;
         if(i==5 or i==7 or i==0)
         {
             label=new QLabel("");
             label->setFrameStyle(1);
             color=QPalette(Qt::Window,Qt::gray);
         }
         else if(i%2==0)
         {
             label=new QLabel("P"+QString::number(i+1)+"\nCode");
             label->setFrameStyle(4);
             color=QPalette(Qt::Window,Qt::red);
         }
         else
         {
             label=new QLabel("P"+QString::number(i+1)+"\nCode");
             label->setFrameStyle(4);
             color=QPalette(Qt::Window,Qt::blue);
         }


         label->setAutoFillBackground(true);
         label->setPalette(color);
         label->setFont(font_14);
         label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
         label->setMinimumSize(200,scale*100);
         label->setMaximumSize(200,scale*100);
         ui->memory_layout->addWidget(label);

         QLabel *ruler=new QLabel(QString::number(i+1));
         ruler->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
         ruler->setMinimumHeight(scale*100);
         ruler->setMaximumHeight(scale*100);
         ui->ruler_layout->addWidget(ruler);
     }
}

void MainWindow::draw2()
{
    clear(ui->memory_layout);
    clear(ui->ruler_layout);
    QFont font_14("times",14);
    QPalette color;
    int scale=1;
    QLabel *zero_ruler=new QLabel("0");
    zero_ruler->setMinimumHeight(10);
    zero_ruler->setMaximumHeight(10);
    ui->ruler_layout->addWidget(zero_ruler);

     for(int i=0;i<10;i++)
     {
         if(i==0)
                  {
                      QPushButton *button=new QPushButton("Occupied");
         //             button->setAutoFillBackground(true);
                      button->setFont(font_14);
                      button->setStyleSheet("background-color:rgb(5, 176, 255)");

                      connect(button,&QPushButton::clicked,[=](){
                          draw();
                      });
                      button->setPalette(color);
                      button->setMinimumSize(200,scale*100);
                      button->setMaximumSize(200,scale*100);
                      ui->memory_layout->addWidget(button);
                  }


         else if(i%2==0)
         {
             QLabel *label;
             label=new QLabel("P"+QString::number(i+1)+"\nCode");
             label->setFrameStyle(4);
             color=QPalette(Qt::Window,Qt::red);
             label->setAutoFillBackground(true);
             label->setPalette(color);
             label->setFont(font_14);
             label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
             label->setMinimumSize(200,scale*100);
             label->setMaximumSize(200,scale*100);
             ui->memory_layout->addWidget(label);
         }
         else if(i==5 or i==7)
         {
             QLabel *label;
             label=new QLabel("");
             label->setFrameStyle(1);
             color=QPalette(Qt::Window,Qt::gray);
             label->setAutoFillBackground(true);
             label->setPalette(color);
             label->setFont(font_14);
             label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
             label->setMinimumSize(200,scale*100);
             label->setMaximumSize(200,scale*100);
             ui->memory_layout->addWidget(label);
         }
         else
         {
             QLabel *label;
             label=new QLabel("P"+QString::number(i+1)+"\nCode");
             label->setFrameStyle(4);
             color=QPalette(Qt::Window,Qt::blue);
             label->setAutoFillBackground(true);
             label->setPalette(color);
             label->setFont(font_14);
             label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
             label->setMinimumSize(200,scale*100);
             label->setMaximumSize(200,scale*100);
             ui->memory_layout->addWidget(label);
         }




         QLabel *ruler=new QLabel(QString::number(i+1));
         ruler->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
         ruler->setMinimumHeight(scale*100);
         ruler->setMaximumHeight(scale*100);
         ui->ruler_layout->addWidget(ruler);
     }
}

void MainWindow::clear(QVBoxLayout* layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0)
    {
        child->widget()->setParent(NULL);
        delete child;
    }
}


void MainWindow::on_delete_process_clicked()
{
    if(ui->processes_combo_box->currentIndex()==-1)
    {
        return;
    }
    QList<QListWidgetItem*>items;
    QString process_name=ui->processes_combo_box->currentText();
    items=ui->processes_list->findItems(process_name,Qt::MatchExactly);
    delete items[0];
    ui->processes_combo_box->removeItem(ui->processes_combo_box->currentIndex());

}

void MainWindow::on_add_process_clicked()
{

    ui->processes_combo_box->addItem("Process "+QString::number(++number_processes));
    ui->processes_list->addItem("Process "+QString::number(number_processes));
    ui->processes_combo_box->setCurrentText("Process "+QString::number(number_processes));

}
void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    showEventHelper();
}

void MainWindow::showEventHelper()
{
    draw2();
}
