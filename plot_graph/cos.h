#ifndef COS_H
#define COS_H

#include <QDialog>

namespace Ui {
class cos;
}

class cos : public QDialog
{
    Q_OBJECT

public:
    explicit cos(QWidget *parent = nullptr);
    ~cos();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::cos *ui;
};

#endif // COS_H
