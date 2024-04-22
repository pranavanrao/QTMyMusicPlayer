#ifndef MYBOSSWIDGET_H
#define MYBOSSWIDGET_H

#include <QObject>

class MyBossWidget : public QObject
{
    Q_OBJECT
public:
    explicit MyBossWidget(QObject *parent = nullptr);

public slots:
    void changeVolume(int val);
    void timerExpired();

signals:
    void imReady(bool);
};

#endif // MYBOSSWIDGET_H
