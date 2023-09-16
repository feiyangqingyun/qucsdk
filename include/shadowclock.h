#ifndef SHADOWCLOCK_H
#define SHADOWCLOCK_H

/**
 * 光晕时钟控件 作者:雨田哥(QQ:3246214072) 整理:feiyangqingyun(QQ:517216493) 2019-10-07
 * 1. 可设置圆弧半径宽度。
 * 2. 可设置光晕宽度。
 * 3. 可设置光晕颜色。
 * 4. 可设置文本颜色。
 * 5. 可分辨设置时钟、分钟、秒钟的颜色。
 * 6. 采用动画机制平滑进度展示时间。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ShadowClock : public QWidget
#else
class ShadowClock : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int radiusWidth READ getRadiusWidth WRITE setRadiusWidth)
    Q_PROPERTY(int shadowWidth READ getShadowWidth WRITE setShadowWidth)

    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor shadowColor READ getShadowColor WRITE setShadowColor)
    Q_PROPERTY(QColor hourColor READ getHourColor WRITE setHourColor)
    Q_PROPERTY(QColor minuteColor READ getMinuteColor WRITE setMinuteColor)
    Q_PROPERTY(QColor secondColor READ getSecondColor WRITE setSecondColor)

public:
    explicit ShadowClock(QWidget *parent = 0);
    ~ShadowClock();

protected:
    void paintEvent(QPaintEvent *);
    void drawArc(QPainter *painter, int radius, qreal angle, const QColor &arcColor);
    void drawText(QPainter *painter);

private:
    int radiusWidth;        //半径宽度
    int shadowWidth;        //光晕宽度

    QColor textColor;       //文本颜色
    QColor shadowColor;     //光晕颜色
    QColor hourColor;       //时钟颜色
    QColor minuteColor;     //分钟颜色
    QColor secondColor;     //秒钟颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置半径宽度
    int getRadiusWidth() const;
    void setRadiusWidth(int radiusWidth);

    //获取和设置光晕宽度
    int getShadowWidth() const;
    void setShadowWidth(int shadowWidth);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置光晕颜色
    QColor getShadowColor() const;
    void setShadowColor(const QColor &shadowColor);

    //获取和设置时钟颜色
    QColor getHourColor() const;
    void setHourColor(const QColor &hourColor);

    //获取和设置分钟颜色
    QColor getMinuteColor() const;
    void setMinuteColor(const QColor &minuteColor);

    //获取和设置秒钟颜色
    QColor getSecondColor() const;
    void setSecondColor(const QColor &secondColor);
};

#endif // SHADOWCLOCK_H
