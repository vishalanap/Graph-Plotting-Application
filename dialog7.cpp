#include "dialog7.h"
#include "ui_dialog7.h"

Dialog7::Dialog7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog7)
{
    ui->setupUi(this);
}

Dialog7::~Dialog7()
{
    delete ui;
}

void Dialog7::on_plot_btn_clicked()
{
    QVector<QColor> colors(4);
    QVector<double> values(4);
    colors[0] = Qt::red, colors[1] = Qt::blue, colors[2] = Qt::green, colors[3] = Qt::yellow;
    values[0] = ui->a_1->value(), values[1] = ui->a_2->value(), values[2] = ui->a_3->value(), values[3] = ui->a_4->value();
    ui->widget->setData(values,colors);
}
