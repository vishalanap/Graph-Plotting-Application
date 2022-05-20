#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    if(ui->radioButton->isChecked()){
        first = new Dialog2(this);
        first->show();
    }
    if(ui->radioButton_2->isChecked()){
        second = new Dialog(this);
        second->show();
    }
    if(ui->radioButton_3->isChecked()){
        fourth = new Dialog4(this);
        fourth->show();
    }
    if(ui->radioButton_4->isChecked()){
        five = new Dialog5(this);
        five->show();
    }
    if(ui->radioButton_5->isChecked()){
        three = new Dialog3(this);
        three->show();
    }
    if(ui->radioButton_6->isChecked()){
        six = new Dialog7(this);
        six->show();
    }

}
