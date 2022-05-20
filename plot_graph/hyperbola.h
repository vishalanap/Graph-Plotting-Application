#ifndef HYPERBOLA_H
#define HYPERBOLA_H

#include <QDialog>

namespace Ui {
class hyperbola;
}

class hyperbola : public QDialog
{
    Q_OBJECT

public:
    explicit hyperbola(QWidget *parent = nullptr);
    ~hyperbola();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hyperbola *ui;
};

#endif // HYPERBOLA_H
