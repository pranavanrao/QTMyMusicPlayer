#include "mybosswidget.h"
#include <QDebug>
#include <QTimer>

MyBossWidget::MyBossWidget(QObject *parent)
    : QObject{parent}
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &MyBossWidget::timerExpired);
    timer->start(15000);
}

void MyBossWidget::changeVolume(int value)
{
    qDebug() << Q_FUNC_INFO << "Changed Volume: ";
}

void MyBossWidget::timerExpired()
{
    qDebug() << Q_FUNC_INFO << "Display MyBossWidget";
    emit imReady(true);
}
