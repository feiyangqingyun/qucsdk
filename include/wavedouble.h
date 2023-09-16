#ifndef WAVEDOUBLE_H
#define WAVEDOUBLE_H

/**
 * 直方对称图控件 作者:feiyangqingyun(QQ:517216493) 2016-11-06
 * 1. 可设置最大值、最小值、当前值。
 * 2. 可设置每次过渡的步长。
 * 3. 可设置item之间的间隔。
 * 4. 可设置渐变的背景颜色。
 * 5. 可设置柱状条的颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT WaveDouble : public QWidget
#else
class WaveDouble : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

    Q_PROPERTY(double step READ getStep WRITE setStep)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
    Q_PROPERTY(QColor barColor READ getBarColor WRITE setBarColor)

public:
    explicit WaveDouble(QWidget *parent = 0);
    ~WaveDouble();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBar(QPainter *painter);

private:
    int minValue;           //最小值
    int maxValue;           //最大值
    int value;              //目标值

    int step;               //步长
    int space;              //间距

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色
    QColor barColor;        //柱状条颜色

    double currentValue;    //当前值
    bool reverse;           //是否倒退
    QTimer *timer;          //绘制定时器

private slots:
    void updateValue();
    void stop();

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(int minValue, int maxValue);

    //获取和设置最小值
    int getMinValue() const;
    void setMinValue(int minValue);

    //获取和设置最大值
    int getMaxValue() const;
    void setMaxValue(int maxValue);

    //获取和设置目标值
    int getValue() const;
    void setValue(int value);

    //获取和设置步长
    int getStep() const;
    void setStep(int step);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置背景颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置柱状条颜色
    QColor getBarColor() const;
    void setBarColor(const QColor &barColor);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // WAVEDOUBLE_H
