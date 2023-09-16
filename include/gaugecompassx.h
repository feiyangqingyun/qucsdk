#ifndef GAUGECOMPASSX_H
#define GAUGECOMPASSX_H

/**
 * 简易指南针控件 作者:feiyangqingyun(QQ:517216493) 2022-02-11
 * 1. 可设置大刻度小刻度数量。
 * 2. 可设置刻度尺颜色。
 * 3. 可设置指针颜色。
 * 4. 可设置中间园渐变颜色。
 * 5. 可设置文字颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeCompassx : public QWidget
#else
class GaugeCompassx : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)

    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor circleColor1 READ getCircleColor1 WRITE setCircleColor1)
    Q_PROPERTY(QColor circleColor2 READ getCircleColor2 WRITE setCircleColor2)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit GaugeCompassx(QWidget *parent = 0);
    ~GaugeCompassx();

protected:
    void paintEvent(QPaintEvent *);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawCircle(QPainter *painter);
    void drawText(QPainter *painter);
    void drawPointer(QPainter *painter);

private:
    double value;           //目标值
    int scaleMajor;         //大刻度数量
    int scaleMinor;         //小刻度数量

    QColor scaleColor;      //刻度尺颜色
    QColor pointerColor;    //指针颜色
    QColor circleColor1;    //中心圆颜色1
    QColor circleColor2;    //中心圆颜色2
    QColor textColor;       //文字颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置目标值
    double getValue() const;
    void setValue(double value);    

    //获取和设置主刻度数量
    int getScaleMajor() const;
    void setScaleMajor(int scaleMajor);

    //获取和设置小刻度数量
    int getScaleMinor() const;
    void setScaleMinor(int scaleMinor);

    //获取和设置刻度尺颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

    //获取和设置中心圆颜色1
    QColor getCircleColor1() const;
    void setCircleColor1(const QColor &circleColor1);

    //获取和设置中心圆颜色2
    QColor getCircleColor2() const;
    void setCircleColor2(const QColor &circleColor2);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(int value);
};

#endif // GAUGECOMPASSX_H
