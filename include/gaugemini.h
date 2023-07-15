#ifndef GAUGEMINI_H
#define GAUGEMINI_H

/**
 * 迷你仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2017-11-26
 * 1. 支持指示器样式选择 线条指示器、指针指示器、圆角指针指示器、三角形指示器。
 * 2. 支持鼠标按下旋转改变值。
 * 3. 支持负数刻度值。
 * 4. 支持设置当前值及范围值。
 * 5. 支持左右旋转角度设置。
 * 6. 支持设置刻度数量。
 * 7. 支持设置边框颜色、背景颜色、文本颜色、进度颜色。
 * 8. 支持设置是否等分显示左右值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeMini : public QWidget
#else
class GaugeMini : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PointerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int step READ getStep WRITE setStep)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor percentColor READ getPercentColor WRITE setPercentColor)

    Q_PROPERTY(bool doublePercent READ getDoublePercent WRITE setDoublePercent)
    Q_PROPERTY(bool showValue READ getShowValue WRITE setShowValue)
    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PointerStyle {
        PointerStyle_Line = 0,          //线条指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeMini(QWidget *parent = 0);
    ~GaugeMini();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawScale(QPainter *painter);
    void drawBgCircle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawPointerLine(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    int step;                       //刻度数量
    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度

    QColor borderColor;             //边框颜色
    QColor bgColor;                 //背景颜色
    QColor textColor;               //文字颜色
    QColor percentColor;            //进度颜色

    bool doublePercent;             //是否对半等分范围值
    bool showValue;                 //是否显示当前值
    PointerStyle pointerStyle;      //指针样式

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

    int getStep()                   const;
    int getStartAngle()             const;
    int getEndAngle()               const;

    QColor getBorderColor()         const;
    QColor getBgColor()             const;
    QColor getTextColor()           const;
    QColor getPercentColor()        const;

    bool getDoublePercent()         const;
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

    //设置刻度数量
    void setStep(int step);
    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置边框颜色
    void setBorderColor(const QColor &borderColor);
    //设置背景颜色
    void setBgColor(const QColor &bgColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);
    //设置进度颜色
    void setPercentColor(const QColor &percentColor);

    //设置是否对半等分范围值
    void setDoublePercent(bool doublePercent);
    //设置是否显示当前值
    void setShowValue(bool showValue);
    //设置指针样式
    void setPointerStyle(const PointerStyle &pointerStyle);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // GAUGEMINI_H
