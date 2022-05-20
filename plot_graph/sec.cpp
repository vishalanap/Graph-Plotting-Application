#include "sec.h"
#include "ui_sec.h"

sec::sec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sec)
{
    ui->setupUi(this);
}

sec::~sec()
{
    delete ui;
}

void sec::on_plot_btn_clicked()
{
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    QVector<double> x(251), y0(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = (ui->a_1->value())*(1/qCos((i/10.0)* ui->b_1->value())); // tangent waveform
    }

    ui->plot->xAxis2->setVisible(true);
    ui->plot->xAxis2->setTickLabels(false);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(false);

    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    ui->plot->graph(0)->setData(x, y0);
    ui->plot->graph(0)->rescaleAxes();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
