#ifndef RULERBAR_H
#define RULERBAR_H

/**
 * 柱状标尺控件 作者:feiyangqingyun(QQ:517216493) 2016-10-28
 * 本控件来源于网络(原作者:kimtaikee(http://www.qtcn.org/bbs/read-htm-tid-33693-ds-1.html#tpc))
 * 1. 可设置精确度(小数点后几位)和间距。
 * 2. 可设置背景色、柱状颜色、线条颜色。
 * 3. 可设置长线条步长及短线条步长。
 * 4. 可启用动画及设置动画步长。
 * 5. 可设置范围值。
 * 6. 支持负数刻度值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerBar : public QWidget
#else
class RulerBar : public QWidget
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
    Q_PROPERTY(QColor barBgColor READ getBarBgColor WRITE setBarBgColor)
    Q_PROPERTY(QColor barColor READ getBarColor WRITE setBarColor)

public:
    explicit RulerBar(QWidget *parent = 0);
    ~RulerBar();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawRuler(QPainter *painter);
    void drawBarBg(QPainter *painter);
    void drawBar(QPainter *painter);

private:
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值
    int precision;          //精确度

    int longStep;           //长线条等分步长
    int shortStep;          //短线条等分步长
    int space;              //间距

    bool animation;         //是否启用动画显示
    double animationStep;   //动画显示时步长

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色
    QColor lineColor;       //线条颜色
    QColor barBgColor;      //柱状背景色
    QColor barColor;        //柱状颜色

    bool reverse;           //是否倒退
    double currentValue;    //当前值
    QTimer *timer;          //定时器绘制动画
    QRectF barRect;         //柱状图区域

private slots:
    void updateValue();     //更新值

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置最大最小值-范围值
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

    //获取和设置线条等分步长
    int getLongStep() const;
    void setLongStep(int longStep);

    int getShortStep() const;
    void setShortStep(int shortStep);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置背景颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置柱状背景颜色
    QColor getBarBgColor() const;
    void setBarBgColor(const QColor &barBgColor);

    //获取和设置柱状颜色
    QColor getBarColor() const;
    void setBarColor(const QColor &barColor);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // RULERBAR_H
