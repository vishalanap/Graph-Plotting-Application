#ifndef PARABOLA_H
#define PARABOLA_H

#include <QDialog>

namespace Ui {
class parabola;
}

class parabola : public QDialog
{
    Q_OBJECT

public:
    explicit parabola(QWidget *parent = nullptr);
    ~parabola();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::parabola *ui;
};

#endif // PARABOLA_H
