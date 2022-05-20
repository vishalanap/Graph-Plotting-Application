#ifndef CIRCLE_H
#define CIRCLE_H

#include <QDialog>

namespace Ui {
class circle;
}

class circle : public QDialog
{
    Q_OBJECT

public:
    explicit circle(QWidget *parent = nullptr);
    ~circle();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::circle *ui;
};

#endif // CIRCLE_H
