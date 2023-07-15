#ifndef GAUGEPROGRESS_H
#define GAUGEPROGRESS_H

/**
 * 进度条仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-12-03
 * 1. 支持指示器样式选择 圆形指示器、指针指示器、圆角指针指示器、三角形指示器。
 * 2. 支持鼠标按下旋转改变值。
 * 3. 支持负数范围值。
 * 4. 支持设置当前值、范围值。
 * 5. 支持设置起始旋转角度、结束旋转角度。
 * 6. 支持设置背景色、进度颜色、中间圆渐变颜色。
 * 7. 随窗体拉伸自动变化。
 * 8. 支持鼠标进入和离开动画效果。
 * 9. 可设置是否显示当前值。
 * 10. 可设置是否显示指示器。
 */

#include <QWidget>
#include <QVariant>

class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT GaugeProgress : public QWidget
#else
class GaugeProgress : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PointerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor progressColor READ getProgressColor WRITE setProgressColor)
    Q_PROPERTY(QColor progressBgColor READ getProgressBgColor WRITE setProgressBgColor)
    Q_PROPERTY(QColor circleColorStart READ getCircleColorStart WRITE setCircleColorStart)
    Q_PROPERTY(QColor circleColorEnd READ getCircleColorEnd WRITE setCircleColorEnd)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(bool showPointer READ getShowPointer WRITE setShowPointer)
    Q_PROPERTY(bool showValue READ getShowValue WRITE setShowValue)
    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PointerStyle {
        PointerStyle_Circle = 0,        //圆形指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeProgress(QWidget *parent = 0);
    ~GaugeProgress();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawColorPie(QPainter *painter);
    void drawCoverCircle(QPainter *painter);
    void drawCircle(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度

    QColor bgColor;                 //背景色
    QColor progressColor;           //当前进度颜色
    QColor progressBgColor;         //进度背景颜色
    QColor circleColorStart;        //中间圆渐变开始颜色
    QColor circleColorEnd;          //中间圆渐变结束颜色
    QColor textColor;               //文字颜色

    bool showPointer;               //是否显示指示器
    bool showValue;                 //是否显示当前值
    PointerStyle pointerStyle;      //指针样式

    bool hover;                     //是否鼠标悬停
    int radiusCoverCircle;          //覆盖圆半径
    int radiusCircle;               //中间圆半径
    QPropertyAnimation *animation;  //动画对象

private slots:
    void setEasingCurve();
    void updateRadius(QVariant radius);

private:
    //鼠标是否按下
    bool pressed;
    //根据鼠标按下的坐标设置当前按下坐标处的值
    void setPressedValue(QPointF pressedPoint);

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;

    int getStartAngle()             const;
    int getEndAngle()               const;

    QColor getBgColor()             const;
    QColor getProgressColor()       const;
    QColor getProgressBgColor()     const;
    QColor getCircleColorStart()    const;
    QColor getCircleColorEnd()      const;
    QColor getTextColor()           const;

    bool getShowPointer()           const;
    bool getShowValue()             const;
    PointerStyle getPointerStyle()  const;

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

    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置背景色
    void setBgColor(const QColor &bgColor);

    //设置进度颜色
    void setProgressColor(const QColor &progressColor);
    void setProgressBgColor(const QColor &progressBgColor);

    //设置中间圆颜色
    void setCircleColorStart(const QColor &circleColorStart);
    void setCircleColorEnd(const QColor &circleColorEnd);

    //设置文本颜色
    void setTextColor(const QColor &textColor);

    //设置是否显示指示器
    void setShowPointer(bool showPointer);
    //设置是否显示当前值
    void setShowValue(bool showValue);
    //设置指针样式
    void setPointerStyle(const PointerStyle &pointerStyle);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // GAUGEPROGRESS_H
