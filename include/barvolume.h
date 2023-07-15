#ifndef BARVOLUME_H
#define BARVOLUME_H

/**
 * 柱状音量控件 作者:feiyangqingyun(QQ:517216493) 2016-11-06
 * 1. 可设置范围值、当前值、步长、圆角角度。
 * 2. 可设置背景渐变颜色。
 * 3. 可设置柱状三种渐变颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT BarVolume : public QWidget
#else
class BarVolume : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int value READ getValue WRITE setValue)
    Q_PROPERTY(int step READ getStep WRITE setStep)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding)
    Q_PROPERTY(int radius READ getRadius WRITE setRadius)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor barBgColor READ getBarBgColor WRITE setBarBgColor)
    Q_PROPERTY(QColor barColorStart READ getBarColorStart WRITE setBarColorStart)
    Q_PROPERTY(QColor barColorMid READ getBarColorMid WRITE setBarColorMid)
    Q_PROPERTY(QColor barColorEnd READ getBarColorEnd WRITE setBarColorEnd)

public:
    explicit BarVolume(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBarBg(QPainter *painter);
    void drawBar(QPainter *painter);

private:
    int value;                      //目标值
    int step;                       //步长
    int space;                      //间距
    int padding;                    //间隔
    int radius;                     //圆角角度

    QColor bgColorStart;            //背景渐变开始颜色
    QColor bgColorEnd;              //背景渐变结束颜色

    QColor barBgColor;              //进度背景颜色
    QColor barColorStart;           //进度渐变开始颜色
    QColor barColorMid;             //进度渐变中间颜色
    QColor barColorEnd;             //进度渐变结束颜色

public:
    int getValue()                  const;
    int getStep()                   const;
    int getSpace()                  const;
    int getPadding()                const;
    int getRadius()                 const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;

    QColor getBarBgColor()          const;
    QColor getBarColorStart()       const;
    QColor getBarColorMid()         const;
    QColor getBarColorEnd()         const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置目标值
    void setValue(int value);
    //设置步长
    void setStep(int step);
    //设置间距
    void setSpace(int space);
    //设置间隔
    void setPadding(int padding);
    //设置圆角角度
    void setRadius(int radius);

    //设置背景颜色
    void setBgColorStart(QColor bgColorStart);
    void setBgColorEnd(QColor bgColorEnd);

    //设置柱状颜色
    void setBarBgColor(QColor barBgColor);
    void setBarColorStart(QColor barColorStart);
    void setBarColorMid(QColor barColorMid);
    void setBarColorEnd(QColor barColorEnd);
};

#endif // BARVOLUME_H
