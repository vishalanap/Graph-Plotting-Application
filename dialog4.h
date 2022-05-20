#ifndef DIALOG4_H
#define DIALOG4_H

#include <QDialog>

namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = nullptr);
    ~Dialog4();

    void add_data();

private slots:

    void on_plot2_btn_clicked();

    void on_download_btn_clicked();

private:
    Ui::Dialog4 *ui;

};

#endif // DIALOG4_H
