#ifndef EXPO_H
#define EXPO_H

#include <QDialog>

namespace Ui {
class expo;
}

class expo : public QDialog
{
    Q_OBJECT

public:
    explicit expo(QWidget *parent = nullptr);
    ~expo();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::expo *ui;
};

#endif // EXPO_H
