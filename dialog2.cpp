#include "dialog2.h"
#include "ui_dialog2.h"
#include<QTextStream>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

}

Dialog2::~Dialog2()
{
    delete ui;
}



void Dialog2::on_select_btn_clicked()
{
    if(ui->radioButton->isChecked()){
        hide();
        p = new parabola(this);
        p->show();
    }
    if(ui->radioButton_2->isChecked()){
        hide();
        c = new circle(this);
        c->show();
    }
    if(ui->radioButton_3->isChecked()){
        hide();
        l = new line(this);
        l->show();
    }
    if(ui->radioButton_4->isChecked()){
        hide();
        h = new hyperbola(this);
        h->show();
    }
    if(ui->radioButton_5->isChecked()){
        hide();
        e = new ellipse(this);
        e->show();
    }
    if(ui->radioButton_6->isChecked()){
        hide();
        s = new sin(this);
        s->show();
    }
    if(ui->radioButton_7->isChecked()){
        hide();
        co = new cos(this);
        co->show();
    }
    if(ui->radioButton_8->isChecked()){
        hide();
        t = new tan(this);
        t->show();
    }
    if(ui->radioButton_9->isChecked()){
        hide();
        cose = new cosec(this);
        cose->show();
    }
    if(ui->radioButton_10->isChecked()){
        hide();
        se = new sec(this);
        se->show();
    }
    if(ui->radioButton_11->isChecked()){
        hide();
        ct = new cot(this);
        ct->show();
    }
    if(ui->radioButton_12->isChecked()){
        hide();
        exp = new expo(this);
        exp->show();
    }
}
