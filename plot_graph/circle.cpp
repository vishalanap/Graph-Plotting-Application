#include "circle.h"
#include "ui_circle.h"

circle::circle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::circle)
{
    ui->setupUi(this);
}

circle::~circle()
{
    delete ui;
}

void circle::on_plot_btn_clicked()
{
    // create empty curve objects:
    QCPCurve *Circle = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
    // generate the curve data points:
    const int pointCount = 500;
    QVector<QCPCurveData> Circle1(pointCount);
    for (int i=0; i<pointCount; ++i)
    {
      double phi = i/(double)(pointCount-1)*8*M_PI;
      Circle1[i] = QCPCurveData(i, (ui->radius->value())*(qCos(phi)) + ui->d_1->value(), (ui->radius->value())*(qSin(phi)) + ui->d_2->value());
    }

    Circle->data()->set(Circle1, true);
    // color the curves:
    Circle->setPen(QPen(Qt::blue));
    Circle->setBrush(QBrush(QColor(0, 0, 255, 20)));

    // set some basic config:
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot->axisRect()->setupFullAxesBox();
    ui->plot->rescaleAxes();
}
