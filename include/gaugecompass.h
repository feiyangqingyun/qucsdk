#ifndef GAUGECOMPASS_H
#define GAUGECOMPASS_H

/**
 * 指南针仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-11-12
 * 1. 可设置当前度数。
 * 2. 可设置精确度。
 * 3. 可设置是否启用动画及步长。
 * 4. 可设置边框渐变颜色。
 * 5. 可设置背景渐变颜色。
 * 6. 可设置加深和明亮颜色。
 * 7. 可设置指南指北指针颜色。
 * 8. 可设置中心点渐变颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeCompass : public QWidget
#else
class GaugeCompass : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor crownColorStart READ getCrownColorStart WRITE setCrownColorStart)
    Q_PROPERTY(QColor crownColorEnd READ getCrownColorEnd WRITE setCrownColorEnd)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)
    Q_PROPERTY(QColor lightColor READ getLightColor WRITE setLightColor)

    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(QColor northPointerColor READ getNorthPointerColor WRITE setNorthPointerColor)
    Q_PROPERTY(QColor southPointerColor READ getSouthPointerColor WRITE setSouthPointerColor)

    Q_PROPERTY(QColor centerColorStart READ getCenterColorStart WRITE setCenterColorStart)
    Q_PROPERTY(QColor centerColorEnd READ getCenterColorEnd WRITE setCenterColorEnd)

public:
    explicit GaugeCompass(QWidget *parent = 0);
    ~GaugeCompass();

protected:
    void paintEvent(QPaintEvent *);
    void drawCrownCircle(QPainter *painter);
    void drawBgCircle(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawCoverOuterCircle(QPainter *painter);
    void drawCoverInnerCircle(QPainter *painter);
    void drawCoverCenterCircle(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double value;               //目标值
    int precision;              //精确度(小数点后几位)

    bool animation;             //是否启用动画显示
    double animationStep;       //动画显示时步长

    QColor crownColorStart;     //外边框渐变开始颜色
    QColor crownColorEnd;       //外边框渐变结束颜色

    QColor bgColorStart;        //背景渐变开始颜色
    QColor bgColorEnd;          //背景渐变结束颜色

    QColor darkColor;           //加深颜色
    QColor lightColor;          //明亮颜色

    QColor foreground;          //前景色
    QColor textColor;           //文字颜色

    QColor northPointerColor;   //北方指针颜色
    QColor southPointerColor;   //南方指针颜色

    QColor centerColorStart;    //中心圆渐变开始颜色
    QColor centerColorEnd;      //中心圆渐变结束颜色

    bool reverse;               //是否倒退
    double currentValue;        //当前值
    QTimer *timer;              //定时器绘制动画

private slots:
    void updateValue();

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置目标值
    double getValue() const;
    void setValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置外边框渐变开始颜色
    QColor getCrownColorStart() const;
    void setCrownColorStart(const QColor &crownColorStart);

    //获取和设置外边框渐变结束颜色
    QColor getCrownColorEnd() const;
    void setCrownColorEnd(const QColor &crownColorEnd);

    //获取和设置背景渐变开始颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    //获取和设置背景渐变结束颜色
    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置加深颜色
    QColor getDarkColor() const;
    void setDarkColor(const QColor &darkColor);

    //获取和设置明亮颜色
    QColor getLightColor() const;
    void setLightColor(const QColor &lightColor);

    //获取和设置前景色
    QColor getForeground() const;
    void setForeground(const QColor &foreground);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置北指针颜色
    QColor getNorthPointerColor() const;
    void setNorthPointerColor(const QColor &northPointerColor);

    //获取和设置南指针颜色
    QColor getSouthPointerColor() const;
    void setSouthPointerColor(const QColor &southPointerColor);

    //获取和设置中心圆渐变开始颜色
    QColor getCenterColorStart() const;
    void setCenterColorStart(const QColor &centerColorStart);

    //获取和设置中心圆渐变结束颜色
    QColor getCenterColorEnd() const;
    void setCenterColorEnd(const QColor &centerColorEnd);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(int value);
};

#endif // GAUGECOMPASS_H
