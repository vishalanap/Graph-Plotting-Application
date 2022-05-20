#ifndef LINE_H
#define LINE_H

#include <QDialog>

namespace Ui {
class line;
}

class line : public QDialog
{
    Q_OBJECT

public:
    explicit line(QWidget *parent = nullptr);
    ~line();

private slots:
    void on_plot_btn_clicked();

private:
    Ui::line *ui;
};

#endif // LINE_H
