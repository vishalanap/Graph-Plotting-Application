#include "dialog5.h"
#include "ui_dialog5.h"

Dialog5::Dialog5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog5)
{
    ui->setupUi(this);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

Dialog5::~Dialog5()
{
    delete ui;
}

void Dialog5::on_plot_btn_clicked()
{
    add_data();
}

void Dialog5::add_data()
{
    //int size = 10;
    QVector<double> x, y,ticks;
    ticks << 1 << 2 << 3 << 4 << 5;
    x<<ui->i_1->value()<<ui->i_2->value()<<ui->i_3->value()<<ui->i_4->value()<<ui->i_5->value();
    y<<ui->i_6->value()<<ui->i_7->value()<<ui->i_8->value()<<ui->i_9->value()<<ui->i_10->value();

    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);

    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));
    ui->plot->xAxis->setRange(0,10);
    ui->plot->yAxis->setRange(0,10);

}

void Dialog5::on_Download_btn_clicked()
{
    QString filename("F:/Qt5/3/Download_plot/line_chart.png");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << file.errorString();
    }
    else{
        ui->plot->savePng(filename);
    }
}
