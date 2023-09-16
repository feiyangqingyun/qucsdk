#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QWidget>
#include <QDateTime>

class QTimer;

#ifdef quc
class Q_DECL_EXPORT OvenTimer : public QWidget
#else
class OvenTimer : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int duration READ getDuration WRITE setDuration)

public:
    explicit OvenTimer(QWidget *parent = 0);
    ~OvenTimer();

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void draw(QPainter *painter);

private:
    int duration;
    QDateTime finishTime;

    QTimer *updateTimer;
    QTimer *finishTimer;

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置时长
    int getDuration() const;

public Q_SLOTS:
    void setDuration(int secs);

Q_SIGNALS:
    void timeout();
};

#endif
