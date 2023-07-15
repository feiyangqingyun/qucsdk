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
    int minValue;                   //最小值
    int maxValue;                   //最大值
    int value;                      //目标值

    int step;                       //步长
    int space;                      //间距

    QColor bgColorStart;            //背景渐变开始颜色
    QColor bgColorEnd;              //背景渐变结束颜色
    QColor barColor;                //柱状条颜色

    double currentValue;            //当前值
    bool reverse;                   //是否倒退
    QTimer *timer;                  //绘制定时器

private slots:
    void updateValue();
    void stop();

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getValue()                  const;

    int getStep()                   const;
    int getSpace()                  const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;
    QColor getBarColor()            const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(int minValue);
    void setMaxValue(int maxValue);

    //设置目标值
    void setValue(int value);

    //设置步长
    void setStep(int step);
    //设置间距
    void setSpace(int space);

    //设置背景颜色
    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);

    //设置柱状条颜色
    void setBarColor(const QColor &barColor);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // WAVEDOUBLE_H
