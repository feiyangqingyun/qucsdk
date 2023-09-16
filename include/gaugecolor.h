#ifndef GAUGECOLOR_H
#define GAUGECOLOR_H

/**
 * 多彩仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2018-08-25
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置精确度，最大支持小数点后3位。
 * 3. 可设置大刻度数量、小刻度数量。
 * 4. 可设置开始旋转角度、结束旋转角度。
 * 5. 可设置是否启用动画效果以及动画效果每次移动的步长。
 * 6. 可设置外圆背景、内圆背景、进度三种颜色、刻度尺颜色、文字颜色。
 * 7. 自适应窗体拉伸，刻度尺和文字自动缩放。
 * 8. 可自由拓展各种渐变色，各圆的半径。
 * 9. 指示器样式可选择圆形指示器、指针指示器、圆角指针指示器、三角形指示器。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeColor : public QWidget
#else
class GaugeColor : public QWidget
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

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor borderColor1 READ getBorderColor1 WRITE setBorderColor1)
    Q_PROPERTY(QColor borderColor2 READ getBorderColor2 WRITE setBorderColor2)
    Q_PROPERTY(QColor percentColor1 READ getPercentColor1 WRITE setPercentColor1)
    Q_PROPERTY(QColor percentColor2 READ getPercentColor2 WRITE setPercentColor2)
    Q_PROPERTY(QColor percentColor3 READ getPercentColor3 WRITE setPercentColor3)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor scaleNumColor READ getScaleNumColor WRITE setScaleNumColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PointerStyle {
        PointerStyle_Circle = 0,        //圆形指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeColor(QWidget *parent = 0);
    ~GaugeColor();

protected:
    void paintEvent(QPaintEvent *);
    void drawCircle(QPainter *painter, int radius, const QColor &color1, const QColor &color2);
    void drawPercent(QPainter *painter, int radius, double opacity);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawRoundCircle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private slots:
    void updateValue();

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值
    int precision;              //精确度(小数点后几位)

    int scaleMajor;             //大刻度数量
    int scaleMinor;             //小刻度数量
    int startAngle;             //开始旋转角度
    int endAngle;               //结束旋转角度

    bool animation;             //是否启用动画显示
    double animationStep;       //动画显示时步长

    QColor borderColor1;        //边框颜色1
    QColor borderColor2;        //边框颜色2
    QColor percentColor1;       //进度颜色1
    QColor percentColor2;       //进度颜色2
    QColor percentColor3;       //进度颜色3

    QColor bgColor;             //背景颜色
    QColor scaleColor;          //刻度尺颜色
    QColor scaleNumColor;       //刻度值颜色
    QColor pointerColor;        //指针颜色
    QColor textColor;           //文字颜色

    PointerStyle pointerStyle;  //指针样式

    bool reverse;               //是否往回走
    double currentValue;        //当前值
    QTimer *timer;              //定时器绘制动画

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

    //获取和设置当前值
    double getValue() const;
    void setValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置主刻度数量
    int getScaleMajor() const;
    void setScaleMajor(int scaleMajor);

    //获取和设置小刻度数量
    int getScaleMinor() const;
    void setScaleMinor(int scaleMinor);

    //获取和设置开始旋转角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);

    //获取和设置结束旋转角度
    int getEndAngle() const;
    void setEndAngle(int endAngle);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置边框颜色1
    QColor getBorderColor1() const;
    void setBorderColor1(const QColor &borderColor1);

    //获取和设置边框颜色2
    QColor getBorderColor2() const;
    void setBorderColor2(const QColor &borderColor2);

    //获取和设置进度颜色1
    QColor getPercentColor1() const;
    void setPercentColor1(const QColor &percentColor1);

    //获取和设置进度颜色2
    QColor getPercentColor2() const;
    void setPercentColor2(const QColor &percentColor2);

    //获取和设置进度颜色3
    QColor getPercentColor3() const;
    void setPercentColor3(const QColor &percentColor3);

    //获取和设置圆弧颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置刻度尺颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    //获取和设置刻度值颜色
    QColor getScaleNumColor() const;
    void setScaleNumColor(const QColor &scaleNumColor);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置指针样式
    PointerStyle getPointerStyle() const;
    void setPointerStyle(const PointerStyle &pointerStyle);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(int value);
};

#endif // GAUGECOLOR_H
