#ifndef DIALOG5_H
#define DIALOG5_H

#include <QDialog>

namespace Ui {
class Dialog5;
}

class Dialog5 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog5(QWidget *parent = nullptr);
    ~Dialog5();
    void add_data();

private slots :
    void on_plot_btn_clicked();

    void on_Download_btn_clicked();

private:
    Ui::Dialog5 *ui;
};

#endif // DIALOG5_H
