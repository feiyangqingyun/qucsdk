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
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位
    int scalePrecision;             //刻度尺精确度,小数点后几位

    int scaleMajor;                 //大刻度数量
    int scaleMinor;                 //小刻度数量
    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度

    bool animation;                 //是否启用动画显示
    double animationStep;           //动画显示时步长

    int ringWidth;                  //圆环宽度
    QColor ringColor;               //圆环颜色

    QColor scaleColor;              //刻度颜色
    QColor pointerColor;            //指针颜色
    QColor bgColor;                 //背景颜色
    QColor textColor;               //文字颜色
    QString unit;                   //单位
    QString text;                   //描述文字

    bool reverse;                   //是否往回走
    double currentValue;            //当前值
    QTimer *timer;                  //定时器绘制动画

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;
    int getScalePrecision()         const;

    int getScaleMajor()             const;
    int getScaleMinor()             const;
    int getStartAngle()             const;
    int getEndAngle()               const;

    bool getAnimation()             const;
    double getAnimationStep()       const;

    int getRingWidth()              const;
    QColor getRingColor()           const;

    QColor getScaleColor()          const;
    QColor getPointerColor()        const;
    QColor getBgColor()             const;
    QColor getTextColor()           const;
    QString getUnit()               const;
    QString getText()               const;

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
    //设置刻度尺精确度
    void setScalePrecision(int scalePrecision);

    //设置主刻度数量
    void setScaleMajor(int scaleMajor);
    //设置小刻度数量
    void setScaleMinor(int scaleMinor);
    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置是否启用动画显示
    void setAnimation(bool animation);
    //设置动画显示的步长
    void setAnimationStep(double animationStep);

    //设置圆环宽度+颜色
    void setRingWidth(int ringWidth);
    void setRingColor(const QColor &ringColor);

    //设置刻度颜色
    void setScaleColor(const QColor &scaleColor);
    //设置指针颜色
    void setPointerColor(const QColor &pointerColor);
    //设置背景颜色
    void setBgColor(const QColor &bgColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);
    //设置单位
    void setUnit(const QString &unit);
    //设置中间描述文字
    void setText(const QString &text);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // GAUGEPANEL_H
