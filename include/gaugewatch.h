#ifndef GAUGEWATCH_H
#define GAUGEWATCH_H

/**
 * 时速仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-10-17
 * 1. 可设置各种颜色。
 * 2. 可启用动画效果显示。
 * 3. 可设置起始旋转角度、结束旋转角度。
 * 4. 可设置单位和标题。
 * 5. 可设置大刻度数量、小刻度数量。
 * 6. 增加一些完整性校验及改进部分算法。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeWatch : public QWidget
#else
class GaugeWatch : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor crownColorStart READ getCrownColorStart WRITE setCrownColorStart)
    Q_PROPERTY(QColor crownColorEnd READ getCrownColorEnd WRITE setCrownColorEnd)

    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)

public:
    explicit GaugeWatch(QWidget *parent = 0);
    ~GaugeWatch();

protected:
    void paintEvent(QPaintEvent *);
    void drawCrown(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawIndicator(QPainter *painter);

private slots:
    void updateValue();

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    QString unit;                   //单位
    QString title;                  //标题

    int scaleMajor;                 //大刻度数量
    int scaleMinor;                 //小刻度数量
    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度

    bool animation;                 //是否启用动画显示
    double animationStep;           //动画显示时步长

    QColor crownColorStart;         //外边框渐变开始颜色
    QColor crownColorEnd;           //外边框渐变结束颜色

    QColor foreground;              //前景色
    QColor background;              //背景色
    QColor pointerColor;            //指针颜色

    bool reverse;                   //是否倒退
    double currentValue;            //当前值
    QTimer *timer;                  //定时器绘制动画

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;

    QString getUnit()               const;
    QString getTitle()              const;

    int getScaleMajor()             const;
    int getScaleMinor()             const;
    int getStartAngle()             const;
    int getEndAngle()               const;

    bool getAnimation()             const;
    double getAnimationStep()       const;

    QColor getCrownColorStart()     const;
    QColor getCrownColorEnd()       const;

    QColor getForeground()          const;
    QColor getBackground()          const;
    QColor getPointerColor()        const;

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
    //设置单位
    void setUnit(const QString &unit);
    //设置标题
    void setTitle(const QString &title);

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

    //设置外边框渐变颜色
    void setCrownColorStart(const QColor &crownColorStart);
    void setCrownColorEnd(const QColor &crownColorEnd);

    //设置前景色
    void setForeground(const QColor &foreground);
    //设备背景色
    void setBackground(const QColor &background);
    //设置指针颜色
    void setPointerColor(const QColor &pointerColor);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // GAUGEWATCH_H
