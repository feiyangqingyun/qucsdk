#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QTime>
#include <QPainterPath>
#include <QDebug>

/**
 * 时间线控件 作者:雨田哥(QQ:3246214072) 整理:feiyangqingyun(QQ:517216493) 2021-03-05
 * 1. 可设置当前缩放比例。
 * 2. 可设置线条高度。
 * 3. 可设置线条颜色。
 * 4. 可设置背景颜色。
 * 5. 缩放级别支持 时、分、秒、毫秒。
 * 6. 支持鼠标滚轮缩放。
 */

#ifdef quc
class Q_DECL_EXPORT TimeLine : public QWidget
#else
class TimeLine : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int scaled READ getScaled WRITE setScaled)
    Q_PROPERTY(int lineHeight READ getLineHeight WRITE setLineHeight)

    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

public:
    enum TimeLineUnit {
        TimeLineUnit_Hour = 0,
        TimeLineUnit_Minute = 1,
        TimeLineUnit_Second = 2,
        TimeLineUnit_Msecs = 3
    };

    //自定义时间线时间结构体
    struct TimeLineTime {
        TimeLineTime(const TimeLineTime &other) {
            this->ds = other.ds;
        }

        TimeLineTime(qint64 h = 0, qint64 m = 0, qint64 s = 0, qint64 ms = 0, qint64 us = 0) {
            ds = us + ms * 1000 + s * 1000 * 1000 + m * 60 * 1000 * 1000 + h * 60 * 60 * 1000 * 1000;
        }

        qint64 usTo(const TimeLineTime &other) const {
            return other.ds - this->ds;
        }

        TimeLineTime addUsto(qint64 us) {
            qint64 ds = this->ds + us;
            qint64 h = ds / 3600000000;
            qint64 m = (ds % 3600000000) / 60000000;
            qint64 s = (ds / 1000000) % 60;
            qint64 ms = (ds / 1000) % 1000;
            return TimeLineTime(h, m, s, ms, ds % 1000);
        }

        bool isValid() const {
            return this->ds >= 0;
        }

        int hour() const {
            return this->ds / 3600000000;
        }

        int minute() const {
            return (this->ds % 3600000000) / 60000000;
        }

        int second() const {
            return (this->ds / 1000000) % 60;
        }

        int msecs() const {
            return (this->ds / 1000) % 1000;
        }

        int ucs() const {
            return this->ds % 1000;
        }

        QString toString(int type) const {
            if (type == TimeLine::TimeLineUnit_Hour) {
                int nHour = hour();
                if (minute() > 59) {
                    nHour += 1;
                }

                QString strHour = QString("%1").arg(nHour, 2, 10, QChar('0'));
                return QString("%1时").arg(strHour);
            } else if (type == TimeLine::TimeLineUnit_Minute) {
                int nMin = minute();
                if (second() > 59) {
                    nMin += 1;
                }

                QString strHour = QString("%1").arg(hour(), 2, 10, QChar('0'));
                QString strMin = QString("%1").arg(nMin, 2, 10, QChar('0'));
                return QString("%1:%2分").arg(strHour).arg(strMin);
            } else if (type == TimeLine::TimeLineUnit_Second) {
                int nSec = second();
                if (msecs() > 999) {
                    nSec += 1;
                }

                QString strHour = QString("%1").arg(hour(), 2, 10, QChar('0'));
                QString strMin = QString("%1").arg(minute(), 2, 10, QChar('0'));
                QString strSec = QString("%1").arg(nSec, 2, 10, QChar('0'));
                return QString("%1:%2:%3秒").arg(strHour).arg(strMin).arg(strSec);
            } else if (type == TimeLine::TimeLineUnit_Msecs) {
                int nMsec = msecs();
                if (ucs() > 999) {
                    nMsec += 1;
                }

                QString strHour = QString("%1").arg(hour(), 2, 10, QChar('0'));
                QString strMin = QString("%1").arg(minute(), 2, 10, QChar('0'));
                QString strSec = QString("%1").arg(second(), 2, 10, QChar('0'));
                QString strMsec = QString("%1").arg(nMsec, 3, 10, QChar('0'));
                return QString("%1:%2:%3.%4毫秒").arg(strHour).arg(strMin).arg(strSec).arg(strMsec);
            } else {
                return "unknow";
            }
        }

        friend QDebug operator << (QDebug debug, const TimeLineTime &time) {
            QString info = QString("时: %1  分: %2  秒: %3  毫秒: %4")
                           .arg(time.hour()).arg(time.second())
                           .arg(time.msecs()).arg(time.ucs());
            debug << info;
            return debug;
        }

    public:
        qint64 ds;
    };

    explicit TimeLine(QWidget *parent = 0);
    ~TimeLine();

protected:
    void paintEvent(QPaintEvent *);
    void drawBgColor(QPainter *painter);
    void drawBottomLine(QPainter *painter);
    void drawScaleLine(QPainter *painter);
    void drawScaleLine(QPainter *painter, qreal posx1, qreal posx2);

    void zoomIn(int posx);
    void zoomOut(int posx);
    void adjustTimeForPosx(int posx, TimeLineTime postime);
    void wheelEvent(QWheelEvent *event);

    TimeLineTime getTimeForPosx(qreal posx);
    TimeLineTime getOffsetUcs(int offsetx);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    int scaled;                 //缩放级别
    int lineHeight;             //线条高度

    QColor lineColor;           //线条颜色
    QColor bgColor;             //背景颜色

    bool mousePressed;          //鼠标是否按下
    QPoint pointPressed;        //鼠标按下处的坐标
    TimeLineTime timePressed;   //鼠标按下处的时间

    bool containsPath;          //是否包含在路径中

    TimeLineTime startTime;     //开始时间
    TimeLineTime currentTime;   //当前线条处时间
    TimeLineUnit timeLineUnit;  //时间线单位类型
    QPair<qreal, TimeLineTime> startPair;

    QPixmap timeLinePix;        //时间线背景图
    QPixmap timeLinePosPix;     //时间线垂直线条
    QPainterPath timeLinePosPath;//时间线垂直线条路径

private:
    qreal getPosxForTime(const TimeLineTime &time);
    void getUnitValue();

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置缩放级别
    int getScaled() const;
    int getScaledWidth() const;
    void setScaled(int scaled);

    //获取和设置线条高度
    int getLineHeight() const;
    void setLineHeight(int lineHeight);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置开始位置时间
    TimeLineTime getStartTime() const;
    void setStartTime(const TimeLineTime &time);

    //获取和设置当前按下处时间
    TimeLineTime getCurrentTime() const;
    void setCurrentTime(const TimeLineTime &time);    

Q_SIGNALS:
    //当前线条位置变动信号
    void timeLineChanged(const TimeLineTime &time);
};

#endif // TIMELINE_H
