#ifndef PROGRESSCOLOR_H
#define PROGRESSCOLOR_H

/**
 * 多彩进度条控件 作者:feiyangqingyun(QQ:517216493) 2016-10-28
 * 1. 可设置精确度、步长、圆角角度。
 * 2. 可设置范围值和当前值。
 * 3. 可设置前景色背景色等各种颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressColor : public QWidget
#else
class ProgressColor : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(double step READ getStep WRITE setStep)
    Q_PROPERTY(double space READ getSpace WRITE setSpace)
    Q_PROPERTY(double radius READ getRadius WRITE setRadius)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(QColor barBgColor READ getBarBgColor WRITE setBarBgColor)
    Q_PROPERTY(QColor barColor READ getBarColor WRITE setBarColor)

public:
    explicit ProgressColor(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBar(QPainter *painter);

private:
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值
    int precision;          //精确度(小数点后几位)

    int step;               //步长
    int space;              //间距
    int radius;             //圆角角度

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色

    QColor lineColor;       //线条颜色
    QColor textColor;       //文本颜色

    QColor barBgColor;      //进度背景颜色
    QColor barColor;        //进度颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    //获取和设置最小值
    double getMinValue() const;
    void setMinValue(double minValue);

    //获取和设置最大值
    double getMaxValue() const;
    void setMaxValue(double maxValue);

    //获取和设置目标值
    double getValue() const;
    void setValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置步长
    int getStep() const;
    void setStep(int step);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置圆角角度
    int getRadius() const;
    void setRadius(int radius);

    //获取和设置背景颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置进度颜色
    QColor getBarBgColor() const;
    void setBarBgColor(const QColor &barBgColor);

    QColor getBarColor() const;
    void setBarColor(const QColor &barColor);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // PROGRESSCOLOR_H
