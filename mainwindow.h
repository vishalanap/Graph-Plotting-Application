#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"
#include "dialog5.h"
#include "dialog7.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *second;
    Dialog2 *first;
    Dialog5 *five;
    Dialog4 *fourth;
    Dialog3 *three;
    Dialog7 *six;
};
#endif // MAINWINDOW_H
