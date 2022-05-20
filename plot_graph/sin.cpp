#include "sin.h"
#include "ui_sin.h"

sin::sin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sin)
{
    ui->setupUi(this);
}

sin::~sin()
{
    delete ui;
}

void sin::on_pushButton_clicked()
{
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    QVector<double> x(251), y0(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = (ui->a_1->value())*qSin((i/10.0)* ui->b_1->value()); // cosine wave
    }

    ui->plot->xAxis2->setVisible(true);
    ui->plot->xAxis2->setTickLabels(false);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));

    // pass data points to graphs:
    ui->plot->graph(0)->setData(x, y0);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->plot->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


}
