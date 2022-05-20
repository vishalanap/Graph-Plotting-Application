#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QDialog>

namespace Ui {
class ellipse;
}

class ellipse : public QDialog
{
    Q_OBJECT

public:
    explicit ellipse(QWidget *parent = nullptr);
    ~ellipse();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ellipse *ui;
};

#endif // ELLIPSE_H
