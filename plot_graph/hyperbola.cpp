#include "hyperbola.h"
#include "ui_hyperbola.h"

hyperbola::hyperbola(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hyperbola)
{
    ui->setupUi(this);
}

hyperbola::~hyperbola()
{
    delete ui;
}

void hyperbola::on_pushButton_clicked()
{
    QCPCurve *Hyperbola = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
    // generate the curve data points:
    const int pointCount = 500;
    QVector<QCPCurveData> h1(pointCount);

    if(ui->radioButton->isChecked()){
        for (int i=0; i<pointCount; ++i)
        {
          double phi = i/(double)(pointCount-1)*8*M_PI;
          h1[i] = QCPCurveData(i, (ui->b_1->value())*(qTan(phi)) + ui->c_1->value(), (ui->a_1->value())*(1/qCos(phi)) + ui->c_2->value());
          //vertical hyperbola
        }
    }

    if(ui->radioButton_2->isChecked()){
        for (int i=0; i<pointCount; ++i)
        {
          double phi = i/(double)(pointCount-1)*8*M_PI;
          h1[i] = QCPCurveData(i, (ui->a_2->value())*(1/qCos(phi)) + ui->c_3->value(), (ui->b_2->value())*(1/qTan(phi)) + ui->c_4->value());
          //vertical hyperbola
        }
    }

    Hyperbola->data()->set(h1, true);
    // color the curves:
    Hyperbola->setPen(QPen(Qt::blue));
    Hyperbola->setBrush(QBrush(QColor(0, 0, 255, 20)));

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot->axisRect()->setupFullAxesBox();
    ui->plot->rescaleAxes();
    ui->plot->replot();
    ui->plot->update();
}
