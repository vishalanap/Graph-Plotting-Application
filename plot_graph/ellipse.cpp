#include "ellipse.h"
#include "ui_ellipse.h"

ellipse::ellipse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ellipse)
{
    ui->setupUi(this);
}

ellipse::~ellipse()
{
    delete ui;
}

void ellipse::on_pushButton_clicked()
{
    QCPCurve *Ellipse = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
    // generate the curve data points:
    const int pointCount = 500;
    QVector<QCPCurveData> h1(pointCount);
    for (int i=0; i<pointCount; ++i) {
          double phi = i/(double)(pointCount-1)*8*M_PI;
          h1[i] = QCPCurveData(i, (ui->a_1->value())*(qCos(phi)) + ui->h_1->value(), (ui->b_1->value())*(qSin(phi)) + ui->k_1->value());

    }

    Ellipse->data()->set(h1, true);
    // color the curves:
    Ellipse->setPen(QPen(Qt::blue));
    Ellipse->setBrush(QBrush(QColor(0, 0, 255, 20)));

    // set some basic config:
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot->axisRect()->setupFullAxesBox();
    ui->plot->rescaleAxes();
}
