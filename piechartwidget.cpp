#include "piechartwidget.h"
#include <QPainter>

PieChartWidget::PieChartWidget(QWidget *parent) :
    QWidget(parent)
{
}

void PieChartWidget::setData(QVector<double> value, QVector<QColor> colors)
{
    qvValues = value;
    qvColors = colors;
    repaint();
    update();
}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    QRectF size;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    if (this->height() > this->width())
    {
        size = QRectF(5, 5, this->width()-10, this->width()-10);
    }
    else
    {
        size = QRectF(5, 5, this->height()-10, this->height()-10);
    }

    double sum = 0.0, startAng = 0.0;
    double angle, endAng, percent;

    for (int i=0; i<qvValues.size(); i++)
    {
        sum += qvValues[i];
    }

    for (int i=0; i<qvValues.size(); i++)
    {
        percent = qvValues[i]/sum;
        angle = percent * 360.0;
        endAng = startAng + angle;
        painter.setBrush(qvColors[i]);
        painter.drawPie(size, startAng*16, angle*16);
        startAng = endAng;
    }
}
