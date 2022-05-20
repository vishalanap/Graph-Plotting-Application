#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = 0);
    void setData(QVector<double> value, QVector<QColor> colors);
protected:
    void paintEvent(QPaintEvent *);
private:
    QVector<double> qvValues;
    QVector<QColor> qvColors;

signals:

public slots:

};

#endif // PIECHARTWIDGET_H
