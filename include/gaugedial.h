#ifndef GAUGEDIAL_H
#define GAUGEDIAL_H

/**
 * 旋转仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-11-11
 * 1. 支持指示器样式选择圆形指示器、指针指示器、圆角指针指示器、三角形指示器。
 * 2. 支持鼠标按下旋转改变值。
 * 3. 支持负数刻度值。
 * 4. 支持设置当前值及范围值。
 * 5. 支持左右旋转角度设置。
 * 6. 支持设置大刻度数量和小刻度数量。
 * 7. 支持设置各种颜色。
 * 8. 字号随窗体拉伸自动变化。
 * 9. 可设置是否显示当前值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeDial : public QWidget
#else
class GaugeDial : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PointerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)
    Q_PROPERTY(QColor lightColor READ getLightColor WRITE setLightColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(bool showValue READ getShowValue WRITE setShowValue)
    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PointerStyle {
        PointerStyle_Circle = 0,        //圆形指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeDial(QWidget *parent = 0);
    ~GaugeDial();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawBorderCircle(QPainter *painter);
    void drawBgCircle(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    int scaleMajor;                 //大刻度数量
    int scaleMinor;                 //小刻度数量
    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度

    QColor darkColor;               //暗黑颜色
    QColor lightColor;              //明亮颜色
    QColor textColor;               //文字颜色

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

    int getScaleMajor()             const;
    int getScaleMinor()             const;
    int getStartAngle()             const;
    int getEndAngle()               const;

    QColor getDarkColor()           const;
    QColor getLightColor()          const;
    QColor getTextColor()           const;

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

    //设置主刻度数量
    void setScaleMajor(int scaleMajor);
    //设置小刻度数量
    void setScaleMinor(int scaleMinor);
    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置颜色
    void setDarkColor(const QColor &darkColor);
    void setLightColor(const QColor &lightColor);

    //设置文本颜色
    void setTextColor(const QColor &textColor);

    //设置是否显示当前值
    void setShowValue(bool showValue);
    //设置指针样式
    void setPointerStyle(const PointerStyle &pointerStyle);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // GAUGEDIAL_H
