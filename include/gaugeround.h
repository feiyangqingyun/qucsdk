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
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点几位

    double angle;                   //起始旋转角度
    QString unit;                   //单位

    QColor usedColor;               //已使用百分比颜色
    QColor freeColor;               //未使用百分比颜色

    QColor rangeTextColor;          //范围值文字颜色
    QColor valueTextColor;          //目标值文字颜色

    QColor valueBgColor;            //目标值背景色
    QColor outBgColor;              //外边框背景色
    QColor centerBgColorStart;      //中间圆环渐变背景起始颜色
    QColor centerBgColorEnd;        //中间圆环渐变背景结束颜色

    double currentPercent;          //当前已处理的百分比
    double valuePercent;            //目标值百分比
    QTimer *timer;                  //绘制定时器

private slots:
    void updateValue();

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    int getPrecision()              const;

    double getAngle()               const;
    QString getUnit()               const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;

    QColor getRangeTextColor()      const;
    QColor getValueTextColor()      const;

    QColor getValueBgColor()        const;
    QColor getOutBgColor()          const;
    QColor getCenterBgColorStart()  const;
    QColor getCenterBgColorEnd()    const;

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

    //设置旋转角度
    void setAngle(double angle);

    //设置小数点后几位
    void setPrecision(int precision);

    //设置文字后面的单位
    void setUnit(const QString &unit);

    //设置已使用百分比颜色
    void setUsedColor(const QColor &usedColor);
    //设置未使用百分比颜色
    void setFreeColor(const QColor &freeColor);

    //设置范围值文字颜色
    void setRangeTextColor(const QColor &rangeTextColor);
    //设置目标值文字颜色
    void setValueTextColor(const QColor &valueTextColor);

    //设置目标值背景色
    void setValueBgColor(const QColor &valueBgColor);
    //设置外边框背景色
    void setOutBgColor(const QColor &outBgColor);

    //设置中央圆环背景色
    void setCenterBgColorStart(const QColor &centerBgColorStart);
    void setCenterBgColorEnd(const QColor &centerBgColorEnd);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // GAUGEROUND_H
