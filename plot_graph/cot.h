#ifndef COT_H
#define COT_H

#include <QDialog>

namespace Ui {
class cot;
}

class cot : public QDialog
{
    Q_OBJECT

public:
    explicit cot(QWidget *parent = nullptr);
    ~cot();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::cot *ui;
};

#endif // COT_H
