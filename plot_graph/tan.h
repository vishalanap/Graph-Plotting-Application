#ifndef TAN_H
#define TAN_H

#include <QDialog>

namespace Ui {
class tan;
}

class tan : public QDialog
{
    Q_OBJECT

public:
    explicit tan(QWidget *parent = nullptr);
    ~tan();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::tan *ui;
};

#endif // TAN_H
