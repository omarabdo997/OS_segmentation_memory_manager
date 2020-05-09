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
    this->memory_size=ui->memory_size_lineEdit->text().toFloat();
    if(number_holes!=holes.size())
    {
        QLayoutItem *child;
        while ((child = ui->holes_layout->takeAt(0)) != 0)
        {
            child->widget()->setParent(NULL);
            delete child;
        }
        holes.resize(number_holes);
        int min=number_holes<holes_values.size()?number_holes:holes_values.size();
        for(int i=1;i<=min;i++)
        {
            create_hole_form(i,holes_values[i-1].first,holes_values[i-1].second);
        }
        holes_values.resize(number_holes);
        for(int i=min+1;i<=number_holes;i++)
        {
            create_hole_form(i);
        }
    }
    ui->next_second_button->setDefault(true);
    ui->form_widget->hide();
    ui->holes_widget->show();

//    if(number_processes!=processes.size())
//    {
//        for(int i=0;i<processes.size();i++)
//        {
//            ui->processes_combo_box->removeItem(processes.size()-i);
//            for(int j=0;j<processes[i].size();j++)
//            {
//                delete processes[i][j].first;
//                delete processes[i][j].second;
//            }
//            processes[i].clear();
//        }
//        processes.resize(number_processes);
//        if(FIRST_TIME)
//        {
//            for(int i=1;i<=number_processes;i++)
//            {
//                ui->processes_combo_box->addItem("Process "+QString::number(i));
//            }
//            FIRST_TIME=0;
//        }
//        else
//        {
//            for(int i=2;i<=number_processes;i++)
//            {
//                ui->processes_combo_box->addItem("Process "+QString::number(i));
//            }
//        }
//    }
}

void SegmentationSelector::on_next_second_button_clicked()
{
    for(int i=0;i<number_holes;i++)
    {
        holes_values[i].first=holes[i].first->text().toFloat();
        holes_values[i].second=holes[i].second->text().toFloat();

    }
    QVector<Segment>segments;
    float start=0;
    qSort(holes_values.begin(),holes_values.end());
    for(int i=0;i<holes_values.size();i++)
    {
        if(start==holes_values[i].first)
        {
            if(i>0)
            {
                segments.back().set_to(segments.back().get_to()+holes_values[i].second);
                segments.back().setSize(segments.back().get_to()-segments.back().get_from());
                segments.back().set_processesNames(QVector<QString>(1,""));
                start=segments.back().get_to();
            }
            else
            {
                Segment segment(start,start+holes_values[i].second,"");
                segment.set_isHole(true);
                segments.push_back(segment);
                segments.back().setSize(segments.back().get_to()-segments.back().get_from());
                segments.back().set_processesNames(QVector<QString>(1,""));
                start=start+holes_values[i].second;
            }
        }
        else if(start<holes_values[i].first)
        {
            Segment segment(start,holes_values[i].first,"Occupied"+QString::number(i));
            segment.set_isHole(false);
            segments.push_back(segment);
            segments.back().setSize(segments.back().get_to()-segments.back().get_from());
            segments.back().set_processesNames(QVector<QString>(1,""));
            segment=Segment(holes_values[i].first,holes_values[i].first+holes_values[i].second,"");
            segment.set_isHole(true);
            segments.push_back(segment);
            segments.back().setSize(segments.back().get_to()-segments.back().get_from());
            segments.back().set_processesNames(QVector<QString>(1,""));
            start=holes_values[i].first+holes_values[i].second;
        }
        else
        {
            QMessageBox::critical(this,"Over lap","Holes are overlapping");
            return;
        }

    }

    if(memory_size>segments.back().get_to())
    {
        qDebug()<<memory_size;
        Segment segment(segments.back().get_to(),memory_size,"Occupiedrest");
        segment.set_isHole(false);
        segments.push_back(segment);
        segments.back().setSize(segments.back().get_to()-segments.back().get_from());
        segments.back().set_processesNames(QVector<QString>(1,""));
    }
    else if(memory_size<segments.back().get_to())
    {
        QMessageBox::critical(this,"Memory size exceded","You have exceded you memory size!");
        return;
    }
    for(int i=0;i<segments.size();i++)
    {
        qDebug()<<"start "<<segments[i].get_from()<<" end "<<segments[i].get_to();
    }
    int alg;
    if(ui->first_fit->isChecked())
    {
          alg=0;
    }
    else
    {
        alg=1;
    }
    MM=MemoryManager(segments,alg);
    ui->holes_widget->hide();
    ui->form_widget->show();
    ui->next_first_button->setDefault(true);
    this->rdy=1;
    this->close();
}

//void SegmentationSelector::on_number_segmants_button_clicked()
//{
//    int current_process=ui->processes_combo_box->currentIndex();
//    int number_segmants=ui->number_segmants_lineEdit->text().toInt();
//    int min=processes[current_process].size()<number_segmants?processes[current_process].size():number_segmants;
//    QVector<QPair<QString,int>>back_up(min);
//    for(int i=0;i<min;i++)
//    {
//        back_up[i].first=processes[current_process][i].first->text();
//        back_up[i].second=processes[current_process][i].second->text().toInt();
//    }
//    QLayoutItem *child;
//    while ((child = ui->segmants_layout->takeAt(0)) != 0)
//    {
//        child->widget()->setParent(NULL);
//        delete child;
//    }
//    processes[current_process].resize(number_segmants);
//    for(int i=0;i<min;i++)
//    {
//        processes[current_process][i].first=new QLineEdit(this);
//        processes[current_process][i].first->setText(back_up[i].first);
//        processes[current_process][i].second=new QLineEdit(this);
//        if(QString::number(back_up[i].second)=="0")
//        {
//            processes[current_process][i].second->setPlaceholderText("Size");
//        }
//        else
//        {
//            processes[current_process][i].second->setText(QString::number(back_up[i].second));
//        }

//        ui->segmants_layout->addWidget(processes[current_process][i].first,i,0);
//        ui->segmants_layout->addWidget(processes[current_process][i].second,i,1);
//    }
//    for(int i=min;i<number_segmants;i++)
//    {
//        processes[current_process][i].first=new QLineEdit(this);
//        processes[current_process][i].first->setText("Segmant "+QString::number(i+1));
//        processes[current_process][i].second=new QLineEdit(this);
//        processes[current_process][i].second->setPlaceholderText("Size");
//        ui->segmants_layout->addWidget(processes[current_process][i].first,i,0);
//        ui->segmants_layout->addWidget(processes[current_process][i].second,i,1);
//    }
//}

//void SegmentationSelector::on_processes_combo_box_currentIndexChanged(int index)
//{
//    QLayoutItem *child;
//    while ((child = ui->segmants_layout->takeAt(0)) != 0)
//    {
//        child->widget()->setParent(ui->widget);
//    }
//    for(int i=0;i<processes[index].size();i++)
//    {
//        ui->segmants_layout->addWidget(processes[index][i].first,i,0);
//        ui->segmants_layout->addWidget(processes[index][i].second,i,1);
//    }


//}

void SegmentationSelector::on_back_second_button_clicked()
{
    for(int i=0;i<number_holes;i++)
    {
        if(holes[i].first->text() != "")
        {
            holes_values[i].first=holes[i].first->text().toFloat();
        }
        else
        {
            holes_values[i].first=-1;
        }
        if(holes[i].second->text() != "")
        {
            holes_values[i].second=holes[i].second->text().toFloat();
        }
        else
        {
            holes_values[i].second=-1;
        }
    }
    ui->next_first_button->setDefault(true);
    ui->holes_widget->hide();
    ui->form_widget->show();
}

void SegmentationSelector::create_hole_form(int i, float starting_address, float size)
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
    if(size != -1)
    {
        holes[i-1].second->setText(QString::number(size));
    }
    if(starting_address != -1)
    {
        holes[i-1].first->setText(QString::number(starting_address));
    }
}

MemoryManager SegmentationSelector::getMM() const
{
    return MM;
}

//void SegmentationSelector::on_back_third_button_clicked()
//{
//    ui->processess_widget->hide();
//    ui->holes_widget->show();
//}

//void SegmentationSelector::on_next_third_button_clicked()
//{
//    processes_values.resize(number_processes);
//    for(int i=0;i<number_processes;i++)
//    {
//        processes_values[i].resize(processes[i].size());
//        for(int j=0;j<processes[i].size();j++)
//        {
//            processes_values[i][j].first=processes[i][j].first->text();
//            processes_values[i][j].second=processes[i][j].second->text().toInt();
//        }
//    }
//    if(ui->first_fit->isChecked())
//    {
//        allocation_algorithm=0;
//    }
//    else
//    {
//        allocation_algorithm=1;
//    }
//    this->rdy=1;
//    this->close();

//}

//void SegmentationSelector::setNumber_processes(int value)
//{
//    number_processes = value;
//}

int SegmentationSelector::getAllocation_algorithm() const
{
    return allocation_algorithm;
}

//QVector<QVector<QPair<QString, int> > > SegmentationSelector::getProcesses_values() const
//{
//    return processes_values;
//}

QVector<QPair<float, float> > SegmentationSelector::getHoles_values() const
{
    return holes_values;
}

float SegmentationSelector::getMemory_size() const
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
