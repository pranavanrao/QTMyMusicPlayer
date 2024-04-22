#ifndef WIDGET_H
#define WIDGET_H
#include <mybosswidget.h>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void ready(bool);

public slots:
    void valueReceived(int);
    void playerStarted(bool val);

private:
    MyBossWidget *m_bPlayer;
};
#endif // WIDGET_H
