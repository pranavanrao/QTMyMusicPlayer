#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_bPlayer = new MyBossWidget(this);
    connect(m_bPlayer,
            &MyBossWidget::imReady,
            this,
            &Widget::playerStarted);
}

void Widget::playerStarted(bool val) {
    qDebug() << "Player Started =?" <<val;
    emit ready(val);
}

Widget::~Widget()
{

}

void Widget::valueReceived(int val)
{
    qDebug() << Q_FUNC_INFO << "Value = " << val;
    m_bPlayer -> changeVolume(val);
}
