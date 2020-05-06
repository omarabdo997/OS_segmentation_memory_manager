#include "segmentationselector.h"
#include "ui_segmentationselector.h"

SegmentationSelector::SegmentationSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SegmentationSelector)
{

    ui->setupUi(this);
    ui->holes_widget->hide();
    ui->processess_widget->hide();
    ui->widget->hide();
    ui->first_fit->toggle();
    this->rdy=0;
    setMaximumSize(400,500);
    setMinimumSize(400,500);

}

SegmentationSelector::~SegmentationSelector()
{

    delete ui;
}



void SegmentationSelector::on_next_first_button_clicked()
{
    this->number_holes=ui->number_holes_lineEdit->text().toInt();
    this->number_processes=ui->number_processes_lineEdit->text().toInt();
    this->memory_size=ui->memory_size_lineEdit->text().toInt();
    if(number_holes!=holes.size())
    {
        QLayoutItem *child;
        while ((child = ui->holes_layout->takeAt(0)) != 0)
        {
            child->widget()->setParent(NULL);
            delete child;
        }
        holes.resize(number_holes);
        holes_values.resize(number_holes);
        for(int i=1;i<=number_holes;i++)
        {
            QLabel *l=new QLabel("Hole "+QString::number(i),this);
            QFont font_12("times",12);
            l->setFont(font_12);
            holes[i-1].first=new QLineEdit(this);
            holes[i-1].first->setPlaceholderText("Starting address");
            holes[i-1].second=new QLineEdit(this);
            holes[i-1].second->setPlaceholderText("Size");
            ui->holes_layout->addWidget(l,i,0);
            ui->holes_layout->addWidget(holes[i-1].first,i,1);
            ui->holes_layout->addWidget(holes[i-1].second,i,2);


        }
    }

    if(number_processes!=processes.size())
    {
        for(int i=0;i<processes.size();i++)
        {
            ui->processes_combo_box->removeItem(processes.size()-i);
            for(int j=0;j<processes[i].size();j++)
            {
                delete processes[i][j].first;
                delete processes[i][j].second;
            }
            processes[i].clear();
        }
        processes.resize(number_processes);
        if(FIRST_TIME)
        {
            for(int i=1;i<=number_processes;i++)
            {
                ui->processes_combo_box->addItem("Process "+QString::number(i));
            }
            FIRST_TIME=0;
        }
        else
        {
            for(int i=2;i<=number_processes;i++)
            {
                ui->processes_combo_box->addItem("Process "+QString::number(i));
            }
        }
    }



    ui->form_widget->hide();
    ui->holes_widget->show();
}

void SegmentationSelector::on_next_second_button_clicked()
{
    for(int i=0;i<number_holes;i++)
    {
        holes_values[i].first=holes[i].first->text().toInt();
        holes_values[i].second=holes[i].second->text().toInt();

    }


    QFont font_12("times",12);
    ui->processes_combo_box->setFont(font_12);
    ui->holes_widget->hide();
    ui->processess_widget->show();






}

void SegmentationSelector::on_number_segmants_button_clicked()
{
    int current_process=ui->processes_combo_box->currentIndex();
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
        processes[current_process][i].first=new QLineEdit(this);
        processes[current_process][i].first->setText(back_up[i].first);
        processes[current_process][i].second=new QLineEdit(this);
        if(QString::number(back_up[i].second)=="0")
        {
            processes[current_process][i].second->setPlaceholderText("Size");
        }
        else
        {
            processes[current_process][i].second->setText(QString::number(back_up[i].second));
        }

        ui->segmants_layout->addWidget(processes[current_process][i].first,i,0);
        ui->segmants_layout->addWidget(processes[current_process][i].second,i,1);
    }
    for(int i=min;i<number_segmants;i++)
    {
        processes[current_process][i].first=new QLineEdit(this);
        processes[current_process][i].first->setText("Segmant "+QString::number(i+1));
        processes[current_process][i].second=new QLineEdit(this);
        processes[current_process][i].second->setPlaceholderText("Size");
        ui->segmants_layout->addWidget(processes[current_process][i].first,i,0);
        ui->segmants_layout->addWidget(processes[current_process][i].second,i,1);
    }
}

void SegmentationSelector::on_processes_combo_box_currentIndexChanged(int index)
{
    QLayoutItem *child;
    while ((child = ui->segmants_layout->takeAt(0)) != 0)
    {
        child->widget()->setParent(ui->widget);
    }
    for(int i=0;i<processes[index].size();i++)
    {
        ui->segmants_layout->addWidget(processes[index][i].first,i,0);
        ui->segmants_layout->addWidget(processes[index][i].second,i,1);
    }


}

void SegmentationSelector::on_back_second_button_clicked()
{
    ui->holes_widget->hide();
    ui->form_widget->show();
}

void SegmentationSelector::on_back_third_button_clicked()
{
    ui->processess_widget->hide();
    ui->holes_widget->show();
}

void SegmentationSelector::on_next_third_button_clicked()
{
    processes_values.resize(number_processes);
    for(int i=0;i<number_processes;i++)
    {
        processes_values[i].resize(processes[i].size());
        for(int j=0;j<processes[i].size();j++)
        {
            processes_values[i][j].first=processes[i][j].first->text();
            processes_values[i][j].second=processes[i][j].second->text().toInt();
        }
    }
    if(ui->first_fit->isChecked())
    {
        allocation_algorithm=0;
    }
    else
    {
        allocation_algorithm=1;
    }
    this->rdy=1;
    this->close();

}

void SegmentationSelector::setNumber_processes(int value)
{
    number_processes = value;
}

int SegmentationSelector::getAllocation_algorithm() const
{
    return allocation_algorithm;
}

QVector<QVector<QPair<QString, int> > > SegmentationSelector::getProcesses_values() const
{
    return processes_values;
}

QVector<QPair<int, int> > SegmentationSelector::getHoles_values() const
{
    return holes_values;
}

int SegmentationSelector::getMemory_size() const
{
    return memory_size;
}

int SegmentationSelector::getNumber_processes() const
{
    return number_processes;
}

int SegmentationSelector::getNumber_holes() const
{
    return number_holes;
}

bool SegmentationSelector::getRdy() const
{
    return rdy;
}
