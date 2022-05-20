#include "dialog4.h"
#include "ui_dialog4.h"


Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);

    // set dark background gradient(gray color):
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->plot->setBackground(QBrush(gradient));

    ui->label_a->setText("<font color='purple'>A</font>");
    ui->label_b->setText("<font color='yellow'>B</font>");
    ui->label_c->setText("<font color='green'>C</font>");

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

Dialog4::~Dialog4()
{
    delete ui;
}


void Dialog4::add_data()
{
    // creating empty bar chart objects:
    QCPBars *studentA = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    QCPBars *studentB = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    QCPBars *studentC = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    studentA->setStackingGap(1);
    studentB->setStackingGap(1);
    studentC->setStackingGap(1);

    // set names and colors:
//    studentB->setName("Student B");
    studentB->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    studentB->setBrush(QColor(111, 9, 176));
//    studentC->setName("Student C");
    studentC->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    studentC->setBrush(QColor(250, 170, 20));
//    studentA->setName("Student A");
    studentA->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    studentA->setBrush(QColor(0, 168, 140));

    // stack bars on top of each other:
    studentB->moveAbove(studentC);
    studentA->moveAbove(studentB);


    // prepare x axis with subject labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << ui->lineEdit_1->text() << ui->lineEdit_2->text() << ui->lineEdit_3->text() << ui->lineEdit_4->text() << ui->lineEdit_5->text() << ui->lineEdit_6->text() << ui->lineEdit_7->text();
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->plot->xAxis->setTicker(textTicker);
    ui->plot->xAxis->setTickLabelRotation(60);
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->xAxis->setTickLength(0, 4);
    ui->plot->xAxis->setRange(0, 8);
    ui->plot->xAxis->setBasePen(QPen(Qt::white));
    ui->plot->xAxis->setTickPen(QPen(Qt::white));
    ui->plot->xAxis->grid()->setVisible(true);
    ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->plot->xAxis->setTickLabelColor(Qt::white);
    ui->plot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->plot->yAxis->setRange(0, 12.1);
    ui->plot->yAxis->setPadding(5); // a bit more space to the left border
    ui->plot->yAxis->setLabel("Marks of each subjects(outoff 20)");
    ui->plot->yAxis->setBasePen(QPen(Qt::white));
    ui->plot->yAxis->setTickPen(QPen(Qt::white));
    ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setLabelColor(Qt::white);
    ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    QVector<double> StudentA, StudentB, StudentC;
    StudentB  << ui->input_1->value() << ui->input_2->value() << ui->input_3->value() << ui->input_4->value() << ui->input_5->value() << ui->input_6->value() << ui->input_7->value();
    StudentC << ui->b_1->value() << ui->b_2->value() << ui->b_3->value() << ui->b_4->value() << ui->b_5->value() << ui->b_6->value() << ui->b_7->value() ;
    StudentA   << ui->c_1->value() << ui->c_2->value() << ui->c_3->value() << ui->c_4->value() << ui->c_5->value() << ui->c_6->value() << ui->c_7->value() ;
    studentB->setData(ticks, StudentB);
    studentC->setData(ticks, StudentC);
    studentA->setData(ticks, StudentA);


}


void Dialog4::on_plot2_btn_clicked()
{
    add_data();

}

void Dialog4::on_download_btn_clicked()
{
    QString filename("F:/Qt5/3/Download_plot/barchart.png");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << file.errorString();
    }
    else{
        ui->plot->savePng(filename);
    }
}
