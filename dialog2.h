#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "plot_graph/parabola.h"
#include "plot_graph/circle.h"
#include "plot_graph/line.h"
#include "plot_graph/hyperbola.h"
#include "plot_graph/ellipse.h"
#include "plot_graph/sin.h"
#include "plot_graph/cos.h"
#include "plot_graph/tan.h"
#include "plot_graph/cosec.h"
#include "plot_graph/sec.h"
#include "plot_graph/cot.h"
#include "plot_graph/expo.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

    void plot();

private slots:

    void on_select_btn_clicked();

private:
    Ui::Dialog2 *ui;

    parabola *p;
    circle *c;
    line *l;
    hyperbola *h;
    ellipse *e;
    sin *s;
    cos *co;
    tan *t;
    cosec *cose;
    sec *se;
    cot *ct;
    expo *exp;
};

#endif // DIALOG2_H
