#ifndef RULERLINE_H
#define RULERLINE_H

/**
 * 进度标尺控件 作者:feiyangqingyun(QQ:517216493) 2019-04-11
 * 1. 可设置精确度(小数点后几位)和间距。
 * 2. 可设置背景色、线条颜色。
 * 3. 可设置长线条步长及短线条步长。
 * 4. 可启用动画及设置动画步长。
 * 5. 可设置范围值。
 * 6. 可设置进度颜色。
 * 7. 支持负数刻度值。
 * 8. 可设置标尺在上面还是下面。
 * 9. 支持直接按下定位进度。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerProgress : public QWidget
#else
class RulerProgress : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
    Q_PROPERTY(bool rulerTop READ getRulerTop WRITE setRulerTop)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor progressColor READ getProgressColor WRITE setProgressColor)

public:
    explicit RulerProgress(QWidget *parent = 0);
    ~RulerProgress();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void setPressedValue(QPoint pressedPoint);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawRulerTop(QPainter *painter);
    void drawRulerBottom(QPainter *painter);

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    int longStep;                   //长线条等分步长
    int shortStep;                  //短线条等分步长
    bool rulerTop;                  //刻度线在上面

    bool animation;                 //是否启用动画显示
    double animationStep;           //动画显示时步长

    QColor bgColor;                 //背景颜色
    QColor lineColor;               //线条颜色
    QColor progressColor;           //进度颜色

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
    bool getRulerTop()              const;

    bool getAnimation()             const;
    double getAnimationStep()       const;

    QColor getBgColor()             const;
    QColor getLineColor()           const;
    QColor getProgressColor()       const;

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
    //设置刻度尺在上面
    void setRulerTop(bool rulerTop);

    //设置是否启用动画显示
    void setAnimation(bool animation);
    //设置动画显示的步长
    void setAnimationStep(double animationStep);

    //设置背景颜色
    void setBgColor(const QColor &bgColor);
    //设置线条颜色
    void setLineColor(const QColor &lineColor);
    //设置进度颜色
    void setProgressColor(const QColor &progressColor);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // RULERLINE_H
