#ifndef SIN_H
#define SIN_H

#include <QDialog>

namespace Ui {
class sin;
}

class sin : public QDialog
{
    Q_OBJECT

public:
    explicit sin(QWidget *parent = nullptr);
    ~sin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sin *ui;
};

#endif // SIN_H
