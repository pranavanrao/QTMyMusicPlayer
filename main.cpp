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

    slider.setRange(0,100);

    layout.addWidget(&slider);
    layout.addWidget(&bar);

    w.show();

    // QObject::connect(&slider,
    //                  &QSlider::valueChanged,
    //                  &bar,
    //                  &QProgressBar::setValue);

    QObject::connect(&slider,
                     &QSlider::sliderMoved,
                     &w,
                     &Widget::valueReceived);

    QObject::connect(&slider,
                     SIGNAL(sliderMoved(int)),
                     &bar,
                     SLOT(setValue(int)));

    return a.exec();
}
