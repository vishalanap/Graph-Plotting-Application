QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    dialog2.cpp \
    dialog3.cpp \
    dialog4.cpp \
    dialog5.cpp \
    dialog7.cpp \
    main.cpp \
    mainwindow.cpp \
    piechartwidget.cpp \
    plot_graph/circle.cpp \
    plot_graph/cos.cpp \
    plot_graph/cosec.cpp \
    plot_graph/cot.cpp \
    plot_graph/ellipse.cpp \
    plot_graph/expo.cpp \
    plot_graph/hyperbola.cpp \
    plot_graph/line.cpp \
    plot_graph/parabola.cpp \
    plot_graph/sec.cpp \
    plot_graph/sin.cpp \
    plot_graph/tan.cpp \
    qcustomplot.cpp \

HEADERS += \
    dialog.h \
    dialog2.h \
    dialog3.h \
    dialog4.h \
    dialog5.h \
    dialog7.h \
    mainwindow.h \
    piechartwidget.h \
    plot_graph/circle.h \
    plot_graph/cos.h \
    plot_graph/cosec.h \
    plot_graph/cot.h \
    plot_graph/ellipse.h \
    plot_graph/expo.h \
    plot_graph/hyperbola.h \
    plot_graph/line.h \
    plot_graph/parabola.h \
    plot_graph/sec.h \
    plot_graph/sin.h \
    plot_graph/tan.h \
    qcustomplot.h \


FORMS += \
    dialog.ui \
    dialog2.ui \
    dialog3.ui \
    dialog4.ui \
    dialog5.ui \
    dialog7.ui \
    mainwindow.ui \
    plot_graph/circle.ui \
    plot_graph/cos.ui \
    plot_graph/cosec.ui \
    plot_graph/cot.ui \
    plot_graph/ellipse.ui \
    plot_graph/expo.ui \
    plot_graph/hyperbola.ui \
    plot_graph/line.ui \
    plot_graph/parabola.ui \
    plot_graph/sec.ui \
    plot_graph/sin.ui \
    plot_graph/tan.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    file.txt
