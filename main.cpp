#include "widget.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QProgressBar>
#include <QObject>
#include <QLabel>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QVBoxLayout layout(&w);
    QSlider slider(Qt::Horizontal);
    QProgressBar bar;
    QLabel text;

    slider.setRange(0,100);
    slider.setDisabled(true);

    layout.addWidget(&slider);
    layout.addWidget(&bar);
    layout.addWidget(&text);

    w.show();

    // QObject::connect(&slider,
    //                  &QSlider::valueChanged,
    //                  &bar,
    //                  &QProgressBar::setValue);

    QObject::connect(&slider,
                     &QSlider::sliderMoved,
                     &w,
                     &Widget::valueReceived);

    QObject::connect(&w,
                     &Widget::ready,
                     &slider,
                     &QSlider::setEnabled);

    QObject::connect(&slider,
                     &QSlider::valueChanged,
                     [&text](int value) {
                         text.setText("Slider value = " + QString::number(value));
                     });

    QObject::connect(&slider,
                     SIGNAL(sliderMoved(int)),
                     &bar,
                     SLOT(setValue(int)));

    return a.exec();
}
