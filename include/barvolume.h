#ifndef BARVOLUME_H
#define BARVOLUME_H

/**
 * 柱状音量控件 作者:feiyangqingyun(QQ:517216493) 2022-12-19
 * 1. 可设置步长即多少个格子。
 * 2. 可设置边距和间距。
 * 3. 可设置格子圆角角度。
 * 4. 可设置背景渐变颜色。
 * 5. 可设置格子背景颜色。
 * 6. 可设置音量值渐变颜色。
 * 7. 可设置方向垂直还是横向。
 * 8. 可设置进度是否反方向开始绘制。
 * 9. 可设置按下调节，上下或者左右滑动设置值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT BarVolume : public QWidget
#else
class BarVolume : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool vertical READ getVertical WRITE setVertical)
    Q_PROPERTY(bool reverse READ getReverse WRITE setReverse)
    Q_PROPERTY(bool pressAdjust READ getPressAdjust WRITE setPressAdjust)

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
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBarBg(QPainter *painter);
    void drawBar(QPainter *painter);
    double getIncrement();

private:
    bool vertical;          //垂直方向
    bool reverse;           //反向进度
    bool pressAdjust;       //按下调节

    int value;              //进度
    int step;               //步长
    int space;              //间距
    int padding;            //间隔
    int radius;             //圆角角度

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色
    QColor barBgColor;      //进度背景颜色

    QColor barColorStart;   //进度渐变开始颜色
    QColor barColorMid;     //进度渐变中间颜色
    QColor barColorEnd;     //进度渐变结束颜色

    QList<QRectF> rects;    //每个进度对应区域

private:
    //获取渐变颜色范围
    QLinearGradient getLinearGradient();

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置垂直方向
    bool getVertical() const;
    void setVertical(bool vertical);

    //获取和设置反向进度
    bool getReverse() const;
    void setReverse(bool reverse);

    //获取和设置按下调节
    bool getPressAdjust() const;
    void setPressAdjust(bool pressAdjust);

    //获取和设置目标值
    int getValue() const;
    void setValue(qreal value);

    //获取和设置步长
    int getStep() const;
    void setStep(int step);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置间隔
    int getPadding() const;
    void setPadding(int padding);

    //获取和设置圆角角度
    int getRadius() const;
    void setRadius(int radius);

    //获取和设置背景渐变开始颜色
    QColor getBgColorStart() const;
    void setBgColorStart(QColor bgColorStart);

    //获取和设置背景渐变结束颜色
    QColor getBgColorEnd() const;
    void setBgColorEnd(QColor bgColorEnd);

    //获取和设置格子背景颜色
    QColor getBarBgColor() const;
    void setBarBgColor(QColor barBgColor);

    //获取和设置音量值渐变开始颜色
    QColor getBarColorStart() const;
    void setBarColorStart(QColor barColorStart);

    //获取和设置音量值渐变中间颜色
    QColor getBarColorMid() const;
    void setBarColorMid(QColor barColorMid);

    //获取和设置音量值渐变结束颜色
    QColor getBarColorEnd() const;
    void setBarColorEnd(QColor barColorEnd);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);
    //清空复位
    void clear();

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // BARVOLUME_H
