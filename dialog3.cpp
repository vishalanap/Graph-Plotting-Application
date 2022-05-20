#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::add_data()
{
    QCPStatisticalBox *statistical = new QCPStatisticalBox(ui->plot->xAxis, ui->plot->yAxis);
    QBrush boxBrush(QColor(60, 60, 255, 100));
    boxBrush.setStyle(Qt::Dense6Pattern);
    statistical->setBrush(boxBrush);

    // specify data:

    double k = ui->a_1->value(),b =ui->a_2->value() ,c =ui->a_3->value() ,d =ui->a_4->value() ,e =ui->a_5->value();
    double f =ui->a_6->value() ,g =ui->a_7->value() ,h =ui->a_8->value() ,i =ui->a_9->value() ,j =ui->a_10->value() ;

    statistical->addData(1,k,b,c,d,e);
    statistical->addData(2,f,g,h,i,j);
    // prepare manual x axis labels:
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->xAxis->setTickLength(0, 4);
    ui->plot->xAxis->setTickLabelRotation(20);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(1, "Sample 1");
    textTicker->addTick(2, "Sample 2");

    ui->plot->xAxis->setTicker(textTicker);

    // prepare axes:
    ui->plot->yAxis->setLabel(QString::fromUtf8("Y axis"));
    ui->plot->rescaleAxes();
    ui->plot->xAxis->scaleRange(1.7, ui->plot->xAxis->range().center());
    ui->plot->yAxis->setRange(0, 20);
}

void Dialog3::on_plot_btn_clicked()
{
    add_data();
}

void Dialog3::on_download_btn_clicked()
{
    QString filename("F:/Qt5/3/Download_plot/boxchart.png");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << file.errorString();
    }
    else{
        ui->plot->savePng(filename);
    }

}
