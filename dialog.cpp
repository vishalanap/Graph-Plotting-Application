#include "dialog.h"
#include "ui_dialog.h"
#include "qcustomplot.h"
#include <QtPrintSupport/qprinter.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addpoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void Dialog::clear()
{
    qv_x.clear();
    qv_y.clear();
}

void Dialog::plot()
{
    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->replot();
    ui->plot->update();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}


void Dialog::on_pushButton_clicked()
{
    addpoint(ui->bx_x->value(),ui->bx_y->value());
    plot();
}

void Dialog::on_pushButton_2_clicked()
{
    clear();
    plot();
}


void Dialog::on_download_btn_clicked()
{
    QString filename("F:/Qt5/3/Download_plot/point_plot.png");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << file.errorString();
    }
    else{
        ui->plot->savePng(filename);
    }
}
