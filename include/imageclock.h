#ifndef IMAGECLOCK_H
#define IMAGECLOCK_H

/**
 * 图片时钟控件 作者:feiyangqingyun(QQ:517216493) 2016-11-04
 * 1. 支持鼠标右键切换风格。
 * 2. 支持设置四种背景风格样式。
 * 3. 支持四种秒针走动风格样式。
 * 4. 增加设置时间接口。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ImageClock : public QWidget
#else
class ImageClock : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(ClockStyle)
    Q_ENUMS(SecondStyle)

    Q_PROPERTY(ClockStyle clockStyle READ getClockStyle WRITE setClockStyle)
    Q_PROPERTY(SecondStyle secondStyle READ getSecondStyle WRITE setSecondStyle)

public:
    enum ClockStyle {
        ClockStyle_Trad = 0,        //黑色风格
        ClockStyle_System = 1,      //银色风格
        ClockStyle_Modern = 2,      //红色风格
        ClockStyle_Flower = 3       //花瓣风格
    };

    enum SecondStyle {
        SecondStyle_Normal = 0,     //普通效果
        SecondStyle_Spring = 1,     //弹簧效果
        SecondStyle_Continue = 2,   //连续效果
        SecondStyle_Hide = 3        //隐藏效果
    };

    explicit ImageClock(QWidget *parent = 0);
    ~ImageClock();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawHour(QPainter *painter);
    void drawMin(QPainter *painter);
    void drawSec(QPainter *painter);
    void drawDot(QPainter *painter);

private:
    ClockStyle clockStyle;      //背景样式
    SecondStyle secondStyle;    //秒针走动样式

    QImage clockBg;             //主背景
    QImage clockHour;           //时钟背景
    QImage clockMin;            //分钟背景
    QImage clockSec;            //秒钟背景
    QImage clockDot;            //中间点背景
    QImage clockHighlights;     //高亮背景

    QStringList imageNames;     //图片名称集合

    QTimer *timer;              //定时器计算时间
    int hour, min, sec, msec;   //时分秒毫秒

    QTimer *timerSpring;        //定时器显示弹簧效果
    double angleSpring;         //弹簧角度

    QAction *action_secondstyle;//秒针样式右键菜单

private Q_SLOTS:
    void doAction();
    void updateTime();
    void updateSpring();

public:
    ClockStyle getClockStyle()      const;
    SecondStyle getSecondStyle()    const;
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置图片背景时钟样式
    void setClockStyle(const ClockStyle &clockStyle);
    //设置秒针走动样式
    void setSecondStyle(const SecondStyle &secondStyle);
    //设置系统时间
    void setSystemDateTime(const QString &year, const QString &month, const QString &day,
                           const QString &hour, const QString &min, const QString &sec);
};

#endif // IMAGECLOCK_H
