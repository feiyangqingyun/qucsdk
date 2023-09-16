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
 * 10. 可设置是否允许按下设置进度。
 * 11. 可设置进度样式是进度条还是游标。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerProgress : public QWidget
#else
class RulerProgress : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(RulerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
    Q_PROPERTY(bool rulerTop READ getRulerTop WRITE setRulerTop)
    Q_PROPERTY(bool leftRight READ getLeftRight WRITE setLeftRight)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor progressColor READ getProgressColor WRITE setProgressColor)

    Q_PROPERTY(bool pressMove READ getPressMove WRITE setPressMove)
    Q_PROPERTY(RulerStyle rulerStyle READ getRulerStyle WRITE setRulerStyle)

public:
    enum RulerStyle {
        RulerStyle_Progress = 0,    //进度条风格
        RulerStyle_Slider = 1,      //滑动条风格
        RulerStyle_Line = 2         //直线条风格
    };

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
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值
    int precision;          //精确度

    int longStep;           //长线条等分步长
    int shortStep;          //短线条等分步长
    bool rulerTop;          //刻度线在上面
    bool leftRight;         //左右模式(不显示负数)

    bool animation;         //是否启用动画显示
    double animationStep;   //动画显示时步长

    QColor bgColor;         //背景颜色
    QColor lineColor;       //线条颜色
    QColor borderColor;     //边框颜色
    QColor progressColor;   //进度颜色

    bool pressMove;         //按下移动
    RulerStyle rulerStyle;  //进度样式

    bool reverse;           //是否倒退
    double currentValue;    //当前值
    QTimer *timer;          //定时器绘制动画

private slots:
    void updateValue();     //更新值

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

    //获取和设置线条等分步长
    int getLongStep() const;
    void setLongStep(int longStep);

    int getShortStep() const;
    void setShortStep(int shortStep);

    //获取和设置刻度尺在上面
    bool getRulerTop() const;
    void setRulerTop(bool rulerTop);

    //获取和设置左右模式
    bool getLeftRight() const;
    void setLeftRight(bool leftRight);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置进度颜色
    QColor getProgressColor() const;
    void setProgressColor(const QColor &progressColor);

    //获取和设置允许按下移动
    bool getPressMove() const;
    void setPressMove(bool pressMove);

    //获取和设置进度风格样式
    RulerStyle getRulerStyle() const;
    void setRulerStyle(const RulerStyle &rulerStyle);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // RULERLINE_H
