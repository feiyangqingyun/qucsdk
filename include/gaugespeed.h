#ifndef GAUGESPEED_H
#define GAUGESPEED_H

/**
 * 速度仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-12-31
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置精确度，最大支持小数点后3位。
 * 3. 可设置大刻度数量、小刻度数量。
 * 4. 可设置开始旋转角度、结束旋转角度。
 * 5. 可设置是否启用动画效果以及动画效果时长和类型。
 * 6. 可设置三色圆环占比例。
 * 7. 自适应窗体拉伸，刻度尺、文字自动缩放。
 * 8. 可设置单位以及描述文字。
 * 9. 可设置数码管的长度。
 */

#include <QWidget>
#include <QEasingCurve>

class QPropertyAnimation;
class QLCDNumber;

#ifdef quc
class Q_DECL_EXPORT GaugeSpeed : public QWidget
#else
class GaugeSpeed : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(double animationValue READ getAnimationValue WRITE setAnimationValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)
    Q_PROPERTY(int digitCount READ getDigitCount WRITE setDigitCount)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(int animationDuration READ getAnimationDuration WRITE setAnimationDuration)
    Q_PROPERTY(QEasingCurve animationType READ getAnimationType WRITE setAnimationType)

    Q_PROPERTY(int ringWidth READ getRingWidth WRITE setRingWidth)
    Q_PROPERTY(int ringPercentStart READ getRingPercentStart WRITE setRingPercentStart)
    Q_PROPERTY(int ringPercentMid READ getRingPercentMid WRITE setRingPercentMid)
    Q_PROPERTY(int ringPercentEnd READ getRingPercentEnd WRITE setRingPercentEnd)

    Q_PROPERTY(QColor ringColorStart READ getRingColorStart WRITE setRingColorStart)
    Q_PROPERTY(QColor ringColorMid READ getRingColorMid WRITE setRingColorMid)
    Q_PROPERTY(QColor ringColorEnd READ getRingColorEnd WRITE setRingColorEnd)

    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)
    Q_PROPERTY(QString text READ getText WRITE setText)

public:
    explicit GaugeSpeed(QWidget *parent = 0);
    ~GaugeSpeed();

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void drawRing(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawValue(QPainter *painter);

private slots:
    void checkPercent();

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值
    int precision;              //精确度,小数点后几位
    int digitCount;             //数码管长度

    int scaleMajor;             //大刻度数量
    int scaleMinor;             //小刻度数量
    int startAngle;             //开始旋转角度
    int endAngle;               //结束旋转角度

    bool animation;             //是否启用动画显示
    int animationDuration;      //动画显示时长
    QEasingCurve animationType; //动画类型

    int ringWidth;              //圆环宽度
    int ringPercentStart;       //第一圆环比例
    int ringPercentMid;         //第二圆环比例
    int ringPercentEnd;         //第三圆环比例

    QColor ringColorStart;      //第一圆环颜色
    QColor ringColorMid;        //第二圆环颜色
    QColor ringColorEnd;        //第三圆环颜色

    QColor pointerColor;        //指针颜色
    QColor bgColor;             //背景颜色
    QColor textColor;           //文字颜色
    QString unit;               //单位
    QString text;               //描述文字

    double currentValue;        //当前动画值
    QPropertyAnimation *animate;//动画机制
    QLCDNumber *lcd;            //数码管

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

    //获取和设置动画值
    double getAnimationValue()  const;
    void setAnimationValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置数码管的长度
    int getDigitCount() const;
    void setDigitCount(int digitCount);

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

    //获取和设置启用动画
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画时长
    int getAnimationDuration() const;
    void setAnimationDuration(int animationDuration);

    //获取和设置动画类型
    QEasingCurve getAnimationType() const;
    void setAnimationType(const QEasingCurve &animationType);

    //获取和设置饼圆宽度
    int getRingWidth() const;
    void setRingWidth(int ringWidth);

    //获取和设置开始圆环占比
    int getRingPercentStart() const;
    void setRingPercentStart(int ringPercentStart);

    //获取和设置中间圆环占比
    int getRingPercentMid() const;
    void setRingPercentMid(int ringPercentMid);

    //获取和设置结束圆环占比
    int getRingPercentEnd() const;
    void setRingPercentEnd(int ringPercentEnd);

    //获取和设置开始圆环颜色
    QColor getRingColorStart() const;
    void setRingColorStart(const QColor &ringColorStart);

    //获取和设置中间圆环颜色
    QColor getRingColorMid() const;
    void setRingColorMid(const QColor &ringColorMid);

    //获取和设置结束圆环颜色
    QColor getRingColorEnd() const;
    void setRingColorEnd(const QColor &ringColorEnd);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置单位
    QString getUnit() const;
    void setUnit(const QString &unit);

    //获取和设置中间描述文字
    QString getText() const;
    void setText(const QString &text);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(int value);
};

#endif // GAUGESPEED_H
