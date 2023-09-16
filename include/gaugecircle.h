#ifndef GAUGECIRCLE_H
#define GAUGECIRCLE_H

/**
 * 半圆仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2017-08-20
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置大刻度数量、小刻度数量。
 * 3. 可设置开始旋转角度、结束旋转角度。
 * 4. 可设置是否启用动画效果以及动画效果每次移动的步长。
 * 5. 自适应窗体拉伸，刻度尺和文字自动缩放。
 * 6. 可自由拓展各种渐变色，各圆的半径。
 * 7. 指示器样式可选择圆形指示器、指针指示器、圆角指针指示器、三角形指示器。
 * 8. 可设置当前值进度颜色和剩余值进度颜色。
 * 9. 背景透明，可自由设置背景图片。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeCircle : public QWidget
#else
class GaugeCircle : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PointerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)

    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor titleColor READ getTitleColor WRITE setTitleColor)

    Q_PROPERTY(bool showOverlay READ getShowOverlay WRITE setShowOverlay)
    Q_PROPERTY(QColor overlayColor READ getOverlayColor WRITE setOverlayColor)

    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PointerStyle {
        PointerStyle_Circle = 0,        //圆形指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeCircle(QWidget *parent = 0);
    ~GaugeCircle();

protected:
    void paintEvent(QPaintEvent *);
    void drawArc(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawRoundCircle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawOverlay(QPainter *painter);

private slots:
    void updateValue();

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值

    int scaleMajor;             //大刻度数量
    int scaleMinor;             //小刻度数量
    int startAngle;             //开始旋转角度
    int endAngle;               //结束旋转角度

    bool animation;             //是否启用动画显示
    double animationStep;       //动画显示时步长

    QColor usedColor;           //当前值颜色
    QColor freeColor;           //剩余值颜色

    QColor scaleColor;          //刻度尺颜色
    QColor pointerColor;        //指针颜色
    QColor textColor;           //文字颜色
    QColor titleColor;          //标题颜色

    bool showOverlay;           //显示遮罩层
    QColor overlayColor;        //遮罩层颜色

    PointerStyle pointerStyle;  //指针样式

    bool reverse;               //是否往回走
    double currentValue;        //当前值
    QTimer *timer;              //定时器绘制动画

    int offsetY;                //半圆仪效果Y坐标偏移量
    int radiusY;                //半圆仪效果中心点Y坐标偏移量

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(double minValue, double maxValue);

    //获取和设置最小值
    double getMinValue() const;
    void setMinValue(double minValue);

    //获取和设置最大值
    double getMaxValue() const;
    void setMaxValue(double maxValue);

    //获取和设置当前值
    double getValue() const;
    void setValue(double value);

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

    //获取和设置当前值颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &usedColor);

    //获取和设置剩余值颜色
    QColor getFreeColor() const;
    void setFreeColor(const QColor &freeColor);

    //获取和设置刻度尺颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置标题颜色
    QColor getTitleColor() const;
    void setTitleColor(const QColor &titleColor);

    //获取和设置是否显示遮罩层
    bool getShowOverlay() const;
    void setShowOverlay(bool showOverlay);

    //获取和设置遮罩层颜色
    QColor getOverlayColor() const;
    void setOverlayColor(const QColor &overlayColor);

    //获取和设置指针样式
    PointerStyle getPointerStyle() const;
    void setPointerStyle(const PointerStyle &pointerStyle);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(double value);
};

#endif // GAUGECIRCLE_H
