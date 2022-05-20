#include "parabola.h"
#include "ui_parabola.h"

parabola::parabola(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parabola)
{
    ui->setupUi(this);
}

parabola::~parabola()
{
    delete ui;
}


void parabola::on_plot_btn_clicked()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100

    if(ui->radioButton->isChecked()){
        for (int i=0; i<101; ++i){
            y[i] = i/50.0 - 1; // y goes from -1 to 1
            (x[i])= (y[i]*y[i] + 2*y[i]*(ui->p_1->value()) + (ui->p_1->value())*(ui->p_1->value()) - (ui->p_3->value()))/(ui->p_2->value()) ; // let's plot a quadratic function
        }
    }
    if(ui->radioButton_2->isChecked()){
        for (int i=0; i<101; ++i){
            y[i] = i/50.0 - 1; // y goes from -1 to 1
            (x[i])= -(y[i]*y[i] + 2*y[i]*(ui->p_6->value()) + (ui->p_6->value())*(ui->p_6->value()) - (ui->p_5->value()))/(ui->p_4->value()) ; // let's plot a quadratic function
        }
    }
    if(ui->radioButton_3->isChecked()){
        for (int i=0; i<101; ++i){
            x[i] = i/50.0 - 1; // x goes from -1 to 1
            (y[i])= (x[i]*x[i] + 2*x[i]*(ui->p_9->value()) + (ui->p_9->value())*(ui->p_9->value()) - (ui->p_8->value()))/(ui->p_7->value()) ; // let's plot a quadratic function
        }
    }
    if(ui->radioButton_4->isChecked()){
        for (int i=0; i<101; ++i){
            x[i] = i/50.0 - 1; // x goes from -1 to 1
            (y[i])= - (x[i]*x[i] + 2*x[i]*(ui->p_12->value()) + (ui->p_12->value())*(ui->p_12->value()) - (ui->p_11->value()))/(ui->p_10->value()) ; // let's plot a quadratic function
        }
    }
    // create graph and assign data to it:
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-1, 1);
    ui->plot->yAxis->setRange(0, 1);
    ui->plot->replot();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
