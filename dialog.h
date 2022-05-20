#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void addpoint(double x,double y);
    void clear();
    void plot();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_download_btn_clicked();

private:
    Ui::Dialog *ui;
    QVector<double> qv_x, qv_y;


};

#endif // DIALOG_H
