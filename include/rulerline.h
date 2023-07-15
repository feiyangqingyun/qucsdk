#ifndef RULERLINE_H
#define RULERLINE_H

/**
 * 线状标尺控件 作者:feiyangqingyun(QQ:517216493) 2016-10-31
 * 1. 可设置精确度(小数点后几位)和间距。
 * 2. 可设置背景色、线条颜色。
 * 3. 可设置长线条步长及短线条步长。
 * 4. 可启用动画及设置动画步长。
 * 5. 可设置范围值。
 * 6. 可设置指示器颜色及宽度。
 * 7. 支持负数刻度值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerLine : public QWidget
#else
class RulerLine : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(int pointerWidth READ getPointerWidth WRITE setPointerWidth)

public:
    explicit RulerLine(QWidget *parent = 0);
    ~RulerLine();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawRulerTop(QPainter *painter);
    void drawRulerBottom(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    int longStep;                   //长线条等分步长
    int shortStep;                  //短线条等分步长
    int space;                      //间距

    bool animation;                 //是否启用动画显示
    double animationStep;           //动画显示时步长

    QColor bgColorStart;            //背景渐变开始颜色
    QColor bgColorEnd;              //背景渐变结束颜色
    QColor lineColor;               //线条颜色

    QColor pointerColor;            //指示器颜色
    int pointerWidth;               //指示器宽度

    bool reverse;                   //是否倒退
    double currentValue;            //当前值
    QTimer *timer;                  //定时器绘制动画

private slots:
    void updateValue();

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;

    int getLongStep()               const;
    int getShortStep()              const;
    int getSpace()                  const;

    bool getAnimation()             const;
    double getAnimationStep()       const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;
    QColor getLineColor()           const;

    QColor getPointerColor()        const;
    int getPointerWidth()           const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    //设置目标值
    void setValue(double value);
    void setValue(int value);

    //设置精确度
    void setPrecision(int precision);
    //设置线条等分步长
    void setLongStep(int longStep);
    void setShortStep(int shortStep);
    //设置间距
    void setSpace(int space);

    //设置是否启用动画显示
    void setAnimation(bool animation);
    //设置动画显示的步长
    void setAnimationStep(double animationStep);

    //设置背景颜色
    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);
    //设置线条颜色
    void setLineColor(const QColor &lineColor);

    //设置指示器颜色
    void setPointerColor(const QColor &pointerColor);
    //设置指示器宽度
    void setPointerWidth(int pointerWidth);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // RULERLINE_H
