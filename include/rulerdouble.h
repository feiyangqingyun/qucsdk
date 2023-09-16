#ifndef RULERDOUBLE_H
#define RULERDOUBLE_H

/**
 * 柱状双向刻度尺控件 作者:feiyangqingyun(QQ:517216493) 2016-11-29
 * 1. 可设置目标值范围值。
 * 2. 可设置两种样式 单向标尺/双向标尺。
 * 3. 可设置刻度尺颜色、文字颜色、告警颜色。
 * 4. 可设置长线条步长及短线条步长。
 * 5. 同时支持左右不同刻度尺。
 * 6. 支持负数刻度值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerDouble : public QWidget
#else
class RulerDouble : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(ScaleStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(double alarmValue READ getAlarmValue WRITE setAlarmValue)

    Q_PROPERTY(double minValueRight READ getMinValueRight WRITE setMinValueRight)
    Q_PROPERTY(double maxValueRight READ getMaxValueRight WRITE setMaxValueRight)
    Q_PROPERTY(double valueRight READ getValueRight WRITE setValueRight)
    Q_PROPERTY(double alarmValueRight READ getAlarmValueRight WRITE setAlarmValueRight)

    Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
    Q_PROPERTY(int longStepRight READ getLongStepRight WRITE setLongStepRight)
    Q_PROPERTY(int shortStepRight READ getShortStepRight WRITE setShortStepRight)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor alarmScaleColor READ getAlarmScaleColor WRITE setAlarmScaleColor)

    Q_PROPERTY(int space READ getSpace WRITE setSpace)
    Q_PROPERTY(ScaleStyle scaleStyle READ getScaleStyle WRITE setScaleStyle)

public:
    enum ScaleStyle {
        ScaleStyle_Single = 0,    //单向标尺
        ScaleStyle_Double = 1     //双向标尺
    };

    explicit RulerDouble(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawLeftScale(QPainter *painter);
    void drawRightScale(QPainter *painter);
    void drawLeftText(QPainter *painter);
    void drawRightText(QPainter *painter);
    void drawLeftPointer(QPainter *painter);
    void drawRightPointer(QPainter *painter);

private:
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值
    double alarmValue;      //告警值

    double maxValueRight;   //右边最小值
    double minValueRight;   //右边最大值
    double valueRight;      //右边目标值
    double alarmValueRight; //右边告警值

    int longStep;           //长线条等分步长
    int shortStep;          //短线条等分步长
    int longStepRight;      //右边长线条等分步长
    int shortStepRight;     //右边短线条等分步长

    QColor bgColor;         //背景色
    QColor scaleColor;      //刻度颜色
    QColor textColor;       //文字颜色
    QColor alarmScaleColor; //告警刻度颜色

    int space;              //间距
    ScaleStyle scaleStyle;  //刻度标尺样式

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);
    void setRangeRight(double minValueRight, double maxValueRight);
    void setRangeRight(int minValueRight, int maxValueRight);

    //获取和设置最大最小值
    double getMinValue() const;
    void setMinValue(double minValue);

    double getMaxValue() const;
    void setMaxValue(double maxValue);

    double getMinValueRight() const;
    void setMinValueRight(double minValue);

    double getMaxValueRight() const;
    void setMaxValueRight(double maxValue);

    //获取和设置目标值
    double getValue() const;
    void setValue(double value);

    double getValueRight() const;
    void setValueRight(double valueRight);

    //获取和设置警戒值
    double getAlarmValue() const;
    void setAlarmValue(double alarmValue);

    double getAlarmValueRight() const;
    void setAlarmValueRight(double alarmValueRight);

    //获取和设置线条等分步长
    int getLongStep() const;
    void setLongStep(int longStep);

    int getShortStep() const;
    void setShortStep(int shortStep);

    int getLongStepRight() const;
    void setLongStepRight(int longStepRight);

    int getShortStepRight() const;
    void setShortStepRight(int shortStepRight);

    //获取和设置背景色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置刻度颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置告警刻度颜色
    QColor getAlarmScaleColor() const;
    void setAlarmScaleColor(const QColor &alarmScaleColor);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置刻度样式
    ScaleStyle getScaleStyle() const;
    void setScaleStyle(const ScaleStyle &scaleStyle);

public Q_SLOTS:
    void setValue(int value);
    void setValueRight(int valueRight);
};

#endif // BARSCALE_H
