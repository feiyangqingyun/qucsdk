#ifndef PROGRESSRING_H
#define PROGRESSRING_H

/**
 * 环形进度条控件 作者:feiyangqingyun(QQ:517216493) 2019-05-01
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置精确度，最大支持小数点后3位。
 * 3. 可设置起始角度。
 * 4. 可设置三种值、三种颜色，启用自动检测值后绘制不同的颜色。
 * 5. 可设置是否启用动画效果以及动画效果每次移动的步长。
 * 6. 可设置背景颜色、文字颜色、进度颜色、中间圆颜色。
 * 7. 可设置值警戒报警比较模式 0-不比较、1-最大值报警、2-最小值报警。
 * 8. 可设置显示的值是百分比。
 * 9. 可设置圆环与背景之间的距离即间距。
 * 10. 可设置圆环的宽度。
 * 11. 可设置圆环背景颜色，形成两种颜色差。
 * 12. 可设置顺时针逆时针转。
 * 13. 可设置中间圆是否扣掉透明。
 * 14. 可设置直接显示的文字优先显示。
 * 15. 自适应窗体拉伸，刻度尺和文字自动缩放。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressRing : public QWidget
#else
class ProgressRing : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)
    Q_PROPERTY(QString text READ getText WRITE setText)

    Q_PROPERTY(bool clipCenter READ getClipCenter WRITE setClipCenter)
    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)
    Q_PROPERTY(bool showPercent READ getShowPercent WRITE setShowPercent)

    Q_PROPERTY(int alarmMode READ getAlarmMode WRITE setAlarmMode)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int ringPadding READ getRingPadding WRITE setRingPadding)
    Q_PROPERTY(int ringWidth READ getRingWidth WRITE setRingWidth)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor ringColor READ getRingColor WRITE setRingColor)
    Q_PROPERTY(QColor ringBgColor READ getRingBgColor WRITE setRingBgColor)
    Q_PROPERTY(QColor circleColor READ getCircleColor WRITE setCircleColor)

    Q_PROPERTY(int ringValue1 READ getRingValue1 WRITE setRingValue1)
    Q_PROPERTY(int ringValue2 READ getRingValue2 WRITE setRingValue2)
    Q_PROPERTY(int ringValue3 READ getRingValue3 WRITE setRingValue3)

    Q_PROPERTY(QColor ringColor1 READ getRingColor1 WRITE setRingColor1)
    Q_PROPERTY(QColor ringColor2 READ getRingColor2 WRITE setRingColor2)
    Q_PROPERTY(QColor ringColor3 READ getRingColor3 WRITE setRingColor3)

public:
    explicit ProgressRing(QWidget *parent = 0);
    ~ProgressRing();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawRing(QPainter *painter);
    void drawPadding(QPainter *painter);
    void drawCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private slots:
    void updateValue();

private:
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值
    int precision;          //精确度(小数点后几位)
    QString text;           //用于直接显示文字

    bool clipCenter;        //中间部分是否扣掉成透明
    bool clockWise;         //顺时针逆时针
    bool showPercent;       //显示百分比

    int alarmMode;          //警戒报警模式,进度为不同的颜色
    int startAngle;         //起始角度
    int ringPadding;        //圆环间距
    int ringWidth;          //圆环宽度

    bool animation;         //是否启用动画显示
    double animationStep;   //动画显示时步长

    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色
    QColor ringColor;       //圆环颜色
    QColor ringBgColor;     //圆环进度背景
    QColor circleColor;     //中心圆颜色

    int ringValue1;         //环形值1
    int ringValue2;         //环形值2
    int ringValue3;         //环形值3

    QColor ringColor1;      //环形颜色1
    QColor ringColor2;      //环形颜色2
    QColor ringColor3;      //环形颜色3

    bool reverse;           //是否往回走
    double currentValue;    //当前值
    QTimer *timer;          //定时器绘制动画

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

    //获取和设置显示的文字
    QString getText() const;
    void setText(const QString &text);

    //获取和设置中间部分是否扣掉成透明
    bool getClipCenter() const;
    void setClipCenter(bool clipCenter);

    //获取和设置顺时针逆时针转
    bool getClockWise() const;
    void setClockWise(bool clockWise);

    //获取和设置显示百分比
    bool getShowPercent() const;
    void setShowPercent(bool showPercent);

    //获取和设置启动自动检验
    int getAlarmMode() const;
    void setAlarmMode(int alarmMode);

    //获取和设置起始角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);

    //获取和设置圆环间距
    int getRingPadding() const;
    void setRingPadding(int ringPadding);

    //获取和设置圆环宽度
    int getRingWidth() const;
    void setRingWidth(int ringWidth);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置圆环进度颜色
    QColor getRingColor() const;
    void setRingColor(const QColor &ringColor);

    //获取和设置圆环背景颜色
    QColor getRingBgColor() const;
    void setRingBgColor(const QColor &ringBgColor);

    //获取和设置中心圆颜色
    QColor getCircleColor() const;
    void setCircleColor(const QColor &circleColor);

    //获取和设置三种值
    int getRingValue1() const;
    void setRingValue1(int ringValue1);

    int getRingValue2() const;
    void setRingValue2(int ringValue2);

    int getRingValue3() const;
    void setRingValue3(int ringValue3);

    //获取和设置三种颜色
    QColor getRingColor1() const;
    void setRingColor1(const QColor &ringColor1);

    QColor getRingColor2() const;
    void setRingColor2(const QColor &ringColor2);

    QColor getRingColor3() const;
    void setRingColor3(const QColor &ringColor3);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // PROGRESSRING_H
