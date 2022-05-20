#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();
    void add_data();

private slots:
    void on_plot_btn_clicked();

    void on_download_btn_clicked();

private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
