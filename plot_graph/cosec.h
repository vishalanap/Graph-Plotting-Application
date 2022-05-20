#ifndef COSEC_H
#define COSEC_H

#include <QDialog>

namespace Ui {
class cosec;
}

class cosec : public QDialog
{
    Q_OBJECT

public:
    explicit cosec(QWidget *parent = nullptr);
    ~cosec();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::cosec *ui;
};

#endif // COSEC_H
