#ifndef GAUGERANGE_H
#define GAUGERANGE_H

/**
 * 范围仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-12-20
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置当前范围值。
 * 3. 可设置开始旋转角度、结束旋转角度。
 * 4. 可设置范围值颜色、范围值外颜色、文字颜色。
 * 5. 自适应窗体拉伸，刻度尺、文字自动缩放。
 * 6. 可设置多种范围样式。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeRange : public QWidget
#else
class GaugeRange : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(RangeStyle)

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)
    Q_PROPERTY(int leftValue READ getLeftValue WRITE setLeftValue)
    Q_PROPERTY(int rightValue READ getRightValue WRITE setRightValue)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor rangeTextColor READ getRangeTextColor WRITE setRangeTextColor)

    Q_PROPERTY(RangeStyle rangeStyle READ getRangeStyle WRITE setRangeStyle)

public:
    enum RangeStyle {
        RangeStyle_Line = 0,    //线条状风格
        RangeStyle_Circle = 1   //圆形状风格
    };

    explicit GaugeRange(QWidget *parent = 0);
    ~GaugeRange();

protected:
    void paintEvent(QPaintEvent *);
    void drawRangeLine(QPainter *painter);
    void drawRangeCircle(QPainter *painter);
    void drawRangeText(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    int minValue;                   //最大值
    int maxValue;                   //最小值
    int value;                      //当前值
    int leftValue;                  //范围值左边
    int rightValue;                 //范围值右边

    int scaleMajor;                 //刻度数量
    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度
    QString unit;                   //单位

    QColor usedColor;               //范围值颜色
    QColor freeColor;               //范围值外颜色
    QColor textColor;               //文字颜色
    QColor rangeTextColor;          //范围文字颜色

    RangeStyle rangeStyle;          //范围值风格

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getValue()                  const;
    int getLeftValue()              const;
    int getRightValue()             const;

    int getScaleMajor()             const;
    int getStartAngle()             const;
    int getEndAngle()               const;
    QString getUnit()               const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;
    QColor getTextColor()           const;
    QColor getRangeTextColor()      const;

    RangeStyle getRangeStyle()      const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置最大最小值
    void setMinValue(int minValue);
    void setMaxValue(int maxValue);
    void setRange(int minValue, int maxValue);

    //设置当前值
    void setValue(int value);

    //设置当前左右范围值
    void setLeftValue(int leftValue);
    void setRightValue(int rightValue);
    void setLeftRightRange(int leftValue, int rightValue);

    //设置刻度数量
    void setScaleMajor(int scaleMajor);
    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);
    //设置单位
    void setUnit(const QString &unit);

    //设置刻度值颜色
    void setUsedColor(const QColor &usedColor);
    //设置指针颜色
    void setFreeColor(const QColor &freeColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);
    //设置文本颜色
    void setRangeTextColor(const QColor &rangeTextColor);

    //设置范围值风格
    void setRangeStyle(const RangeStyle &rangeStyle);

Q_SIGNALS:
    void valueChanged(int leftValue, int rightValue);
};

#endif // GAUGERANGE_H
