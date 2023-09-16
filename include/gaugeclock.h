#ifndef GAUGECLOCK_H
#define GAUGECLOCK_H

/**
 * 时钟仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-10-23
 * 1. 可设置边框颜色。
 * 2. 可设置前景色背景色。
 * 3. 可设置时钟分钟秒钟指针颜色。
 * 4. 可设置刷新间隔。
 * 5. 鼠标右键可设置四种效果 普通效果、弹簧效果、连续效果、隐藏效果。
 * 6. 增加设置系统时间公共槽函数，支持任意操作系统。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeClock : public QWidget
#else
class GaugeClock : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(SecondStyle)

    Q_PROPERTY(QColor crownColorStart READ getCrownColorStart WRITE setCrownColorStart)
    Q_PROPERTY(QColor crownColorEnd READ getCrownColorEnd WRITE setCrownColorEnd)

    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)

    Q_PROPERTY(QColor pointerHourColor READ getPointerHourColor WRITE setPointerHourColor)
    Q_PROPERTY(QColor pointerMinColor READ getPointerMinColor WRITE setPointerMinColor)
    Q_PROPERTY(QColor pointerSecColor READ getPointerSecColor WRITE setPointerSecColor)

    Q_PROPERTY(SecondStyle secondStyle READ getSecondStyle WRITE setSecondStyle)

public:
    enum SecondStyle {
        SecondStyle_Normal = 0,     //普通效果
        SecondStyle_Spring = 1,     //弹簧效果
        SecondStyle_Continue = 2,   //连续效果
        SecondStyle_Hide = 3        //隐藏效果
    };

    explicit GaugeClock(QWidget *parent = 0);
    ~GaugeClock();

protected:
    void paintEvent(QPaintEvent *);
    void drawCrown(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawHour(QPainter *painter);
    void drawMin(QPainter *painter);
    void drawSec(QPainter *painter);
    void drawDot(QPainter *painter);

private:
    QColor crownColorStart;     //外边框渐变开始颜色
    QColor crownColorEnd;       //外边框渐变结束颜色

    QColor foreground;          //前景色
    QColor background;          //背景色

    QColor pointerHourColor;    //时钟指针颜色
    QColor pointerMinColor;     //分钟指针颜色
    QColor pointerSecColor;     //秒钟指针颜色

    SecondStyle secondStyle;    //秒针走动样式

    QTimer *timer;              //定时器绘制
    int hour, min, sec, msec;   //时分秒毫秒

    double angleSpring;         //弹簧角度
    QTimer *timerSpring;        //定时器显示弹簧效果
    QAction *action;            //秒针样式右键菜单

private slots:
    void doAction();
    void updateTime();
    void updateSpring();

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置系统时间
    void setSystemDateTime(const QString &year, const QString &month, const QString &day,
                           const QString &hour, const QString &min, const QString &sec);

    //获取和设置秒针走动样式
    SecondStyle getSecondStyle() const;
    void setSecondStyle(const SecondStyle &secondStyle);

    //获取和设置外边框渐变开始颜色
    QColor getCrownColorStart() const;
    void setCrownColorStart(const QColor &crownColorStart);

    //获取和设置外边框渐变结束颜色
    QColor getCrownColorEnd() const;
    void setCrownColorEnd(const QColor &crownColorEnd);

    //获取和设置前景色
    QColor getForeground() const;
    void setForeground(const QColor &foreground);

    //获取和设置背景色
    QColor getBackground() const;
    void setBackground(const QColor &background);

    //获取和设置时钟指针颜色
    QColor getPointerHourColor() const;
    void setPointerHourColor(const QColor &pointerHourColor);

    //获取和设置分钟指针颜色
    QColor getPointerMinColor() const;
    void setPointerMinColor(const QColor &pointerMinColor);

    //获取和设置秒钟指针颜色
    QColor getPointerSecColor() const;
    void setPointerSecColor(const QColor &pointerSecColor);
};

#endif // GAUGECLOCK_H
