#ifndef GAUGEPANEL_H
#define GAUGEPANEL_H

/**
 * 面板仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2019-07-03
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置精确度、刻度尺精确度，最大支持小数点后3位。
 * 3. 可设置大刻度数量、小刻度数量。
 * 4. 可设置开始旋转角度、结束旋转角度。
 * 5. 可设置是否启用动画效果以及动画效果每次移动的步长。
 * 6. 可设置刻度颜色、文字颜色、圆环的宽度和颜色。
 * 7. 自适应窗体拉伸，刻度尺、文字自动缩放。
 * 8. 可设置单位以及仪表盘名称。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugePanel : public QWidget
#else
class GaugePanel : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)
    Q_PROPERTY(int scalePrecision READ getScalePrecision WRITE setScalePrecision)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(int ringWidth READ getRingWidth WRITE setRingWidth)
    Q_PROPERTY(QColor ringColor READ getRingColor WRITE setRingColor)

    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)
    Q_PROPERTY(QString text READ getText WRITE setText)

public:
    explicit GaugePanel(QWidget *parent = 0);
    ~GaugePanel();

protected:
    void paintEvent(QPaintEvent *);
    void drawRing(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawValue(QPainter *painter);

private slots:
    void updateValue();

private:
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值
    int precision;          //精确度(小数点后几位)
    int scalePrecision;     //刻度尺精确度(小数点后几位)

    int scaleMajor;         //大刻度数量
    int scaleMinor;         //小刻度数量
    int startAngle;         //开始旋转角度
    int endAngle;           //结束旋转角度

    bool animation;         //是否启用动画显示
    double animationStep;   //动画显示时步长

    int ringWidth;          //圆环宽度
    QColor ringColor;       //圆环颜色

    QColor scaleColor;      //刻度颜色
    QColor pointerColor;    //指针颜色
    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色
    QString unit;           //单位
    QString text;           //描述文字

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

    //获取和设置刻度尺精确度
    int getScalePrecision() const;
    void setScalePrecision(int scalePrecision);

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

    //获取和设置圆环宽度
    int getRingWidth() const;
    void setRingWidth(int ringWidth);

    //获取和设置圆环颜色
    QColor getRingColor() const;
    void setRingColor(const QColor &ringColor);

    //获取和设置刻度颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

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

#endif // GAUGEPANEL_H
