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
    ui->segmants_layout->setAlignment(Qt::AlignTop);
    ui->widget->hide();

    QFont font_12("times",12);
    ui->add_processes_comboBox->setFont(font_12);
    ui->processes_combo_box->setFont(font_12);
    for(int i=0;i<number_processes;i++)
    {
        ui->add_processes_comboBox->addItem("Process "+QString::number(i+1));
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
    QString process_name=ui->processes_combo_box->currentText();
    ui->processes_combo_box->removeItem(ui->processes_combo_box->currentIndex());

}

void MainWindow::on_add_process_clicked()
{

    ui->add_processes_comboBox->addItem("Process "+QString::number(++number_processes));
    ui->add_processes_comboBox->setCurrentText("Process "+QString::number(number_processes));
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

void MainWindow::add_segmants_withBackUp(QString current_process, QVector<QPair<QString, int> > &back_up,int i)
{
    QFont font_12("times",12);
    processes[current_process][i].first=new QLineEdit(this);
    processes[current_process][i].first->setFont(font_12);
    processes[current_process][i].first->setText("Segment "+QString::number(i+1));
    processes[current_process][i].first->setText(back_up[i].first);
    processes[current_process][i].second=new QLineEdit(this);
    processes[current_process][i].second->setFont(font_12);
    processes[current_process][i].second->setPlaceholderText("Size");
    if(QString::number(back_up[i].second) !="0")
    {
        processes[current_process][i].second->setText(QString::number(back_up[i].second));
    }
    ui->segmants_layout->addWidget(processes[current_process][i].first,i,0);
    ui->segmants_layout->addWidget(processes[current_process][i].second,i,1);
}

void MainWindow::add_segmants(QString current_process, int i)
{
    QFont font_12("times",12);
    processes[current_process][i].first=new QLineEdit(this);
    processes[current_process][i].first->setFont(font_12);
    processes[current_process][i].first->setText("Segment "+QString::number(i+1));
    processes[current_process][i].second=new QLineEdit(this);
    processes[current_process][i].second->setFont(font_12);
    processes[current_process][i].second->setPlaceholderText("Size");
    ui->segmants_layout->addWidget(processes[current_process][i].first,i,0);
    ui->segmants_layout->addWidget(processes[current_process][i].second,i,1);
}

void MainWindow::on_number_segmants_button_clicked()
{
        QString current_process=ui->add_processes_comboBox->currentText();
        if(current_process=="")
            return;
        int number_segmants=ui->number_segmants_lineEdit->text().toInt();
        int min=processes[current_process].size()<number_segmants?processes[current_process].size():number_segmants;
        QVector<QPair<QString,int>>back_up(min);
        for(int i=0;i<min;i++)
        {
            back_up[i].first=processes[current_process][i].first->text();
            back_up[i].second=processes[current_process][i].second->text().toInt();
        }
        QLayoutItem *child;
        while ((child = ui->segmants_layout->takeAt(0)) != 0)
        {
            child->widget()->setParent(NULL);
            delete child;
        }
        processes[current_process].resize(number_segmants);
        for(int i=0;i<min;i++)
        {
            add_segmants_withBackUp(current_process,back_up,i);
        }
        for(int i=min;i<number_segmants;i++)
        {
            add_segmants(current_process,i);
        }
}



void MainWindow::on_add_processes_comboBox_currentIndexChanged(const QString &arg1)
{
        QLayoutItem *child;
        while ((child = ui->segmants_layout->takeAt(0)) != 0)
        {
            child->widget()->setParent(ui->widget);
        }
        for(int i=0;i<processes[arg1].size();i++)
        {
            ui->segmants_layout->addWidget(processes[arg1][i].first,i,0);
            ui->segmants_layout->addWidget(processes[arg1][i].second,i,1);
        }
}
