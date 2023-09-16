#ifndef GAUGEROUND_H
#define GAUGEROUND_H

/**
 * 圆环仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-10-14
 * 本控件来源于网络(原作者:不详),本人重写90%的代码
 * 1. 可设置已使用、未使用百分比颜色。
 * 2. 可设置目标值背景色。
 * 3. 可设置外边框背景色。
 * 4. 可设置中央圆环背景色。
 * 5. 可设置旋转角度。
 * 6. 支持任意大小自动缩放。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeRound : public QWidget
#else
class GaugeRound : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int angle READ getAngle WRITE setAngle)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)

    Q_PROPERTY(QColor rangeTextColor READ getRangeTextColor WRITE setRangeTextColor)
    Q_PROPERTY(QColor valueTextColor READ getValueTextColor WRITE setValueTextColor)

    Q_PROPERTY(QColor valueBgColor READ getValueBgColor WRITE setValueBgColor)
    Q_PROPERTY(QColor outBgColor READ getOutBgColor WRITE setOutBgColor)
    Q_PROPERTY(QColor centerBgColorStart READ getCenterBgColorStart WRITE setCenterBgColorStart)
    Q_PROPERTY(QColor centerBgColorEnd READ getCenterBgColorEnd WRITE setCenterBgColorEnd)

public:
    GaugeRound(QWidget *parent = 0);
    ~GaugeRound();

protected:
    void paintEvent(QPaintEvent *);
    void drawDial(QPainter *painter);
    void drawBgOut(QPainter *painter);
    void drawBgRound(QPainter *painter);
    void drawBgCenter(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值
    int precision;              //精确度(小数点几位)

    double angle;               //起始旋转角度
    QString unit;               //单位

    QColor usedColor;           //已使用百分比颜色
    QColor freeColor;           //未使用百分比颜色

    QColor rangeTextColor;      //范围值文字颜色
    QColor valueTextColor;      //目标值文字颜色

    QColor valueBgColor;        //目标值背景色
    QColor outBgColor;          //外边框背景色
    QColor centerBgColorStart;  //中间圆环渐变背景起始颜色
    QColor centerBgColorEnd;    //中间圆环渐变背景结束颜色

    double currentPercent;      //当前已处理的百分比
    double valuePercent;        //目标值百分比
    QTimer *timer;              //绘制定时器

private slots:
    void updateValue();

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

    //获取和设置小数点后几位
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置旋转角度
    double getAngle() const;
    void setAngle(double angle);

    //获取和设置文字后面的单位
    QString getUnit() const;
    void setUnit(const QString &unit);

    //获取和设置已使用百分比颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &usedColor);

    //获取和设置未使用百分比颜色
    QColor getFreeColor() const;
    void setFreeColor(const QColor &freeColor);

    //获取和设置范围值文字颜色
    QColor getRangeTextColor() const;
    void setRangeTextColor(const QColor &rangeTextColor);

    //获取和设置目标值文字颜色
    QColor getValueTextColor() const;
    void setValueTextColor(const QColor &valueTextColor);

    //获取和设置目标值背景色
    QColor getValueBgColor() const;
    void setValueBgColor(const QColor &valueBgColor);

    //获取和设置外边框背景色
    QColor getOutBgColor() const;
    void setOutBgColor(const QColor &outBgColor);

    //获取和设置中间圆环背景开始颜色
    QColor getCenterBgColorStart() const;
    void setCenterBgColorStart(const QColor &centerBgColorStart);

    //获取和设置中间圆环背景结束颜色
    QColor getCenterBgColorEnd() const;
    void setCenterBgColorEnd(const QColor &centerBgColorEnd);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(int value);
};

#endif // GAUGEROUND_H
