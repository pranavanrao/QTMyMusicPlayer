#include "widget.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QProgressBar>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QVBoxLayout layout(&w);
    QSlider slider;
    QProgressBar bar;

    layout.addWidget(&slider);
    layout.addWidget(&bar);

    w.show();

    QObject::connect(&slider,
                     &QSlider::valueChanged,
                     &bar,
                     &QProgressBar::setValue);

    QObject::connect(&slider,
                     SIGNAL(QSlider::sliderMoved(int)),
                     &bar,
                     SLOT(&QProgressBar::setValue));

    return a.exec();
}
