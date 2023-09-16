#ifndef GAUGEPLANE_H
#define GAUGEPLANE_H

/**
 * 飞机姿势仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2017-12-21
 * 1. 可设置外边框渐变颜色。
 * 2. 可设置里边框渐变颜色。
 * 3. 可设置主背景颜色、遮罩层颜色、刻度尺颜色。
 * 4. 可设置线条颜色、文字颜色、指针颜色、遥感句柄颜色。
 * 5. 可设置旋转角度。
 * 6. 可设置滚动值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugePlane : public QWidget
#else
class GaugePlane : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor borderOutColorStart READ getBorderOutColorStart WRITE setBorderOutColorStart)
    Q_PROPERTY(QColor borderOutColorEnd READ getBorderOutColorEnd WRITE setBorderOutColorEnd)
    Q_PROPERTY(QColor borderInColorStart READ getBorderInColorStart WRITE setBorderInColorStart)
    Q_PROPERTY(QColor borderInColorEnd READ getBorderInColorEnd WRITE setBorderInColorEnd)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor planeColor READ getPlaneColor WRITE setPlaneColor)
    Q_PROPERTY(QColor glassColor READ getGlassColor WRITE setGlassColor)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor handleColor READ getHandleColor WRITE setHandleColor)

    Q_PROPERTY(int degValue READ getDegValue WRITE setDegValue)
    Q_PROPERTY(int rollValue READ getRollValue WRITE setRollValue)

public:
    explicit GaugePlane(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBorderOut(QPainter *painter);
    void drawBorderIn(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawPlane(QPainter *painter);
    void drawGlass(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawHandle(QPainter *painter);

private:
    QColor borderOutColorStart; //外边框渐变开始颜色
    QColor borderOutColorEnd;   //外边框渐变结束颜色
    QColor borderInColorStart;  //里边框渐变开始颜色
    QColor borderInColorEnd;    //里边框渐变结束颜色

    QColor bgColor;             //背景颜色
    QColor planeColor;          //姿态仪背景
    QColor glassColor;          //遮罩层颜色
    QColor scaleColor;          //刻度尺颜色
    QColor lineColor;           //线条颜色
    QColor textColor;           //文字颜色
    QColor pointerColor;        //指针颜色
    QColor handleColor;         //手柄颜色

    int degValue;               //旋转角度
    int rollValue;              //滚动值

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置外边框渐变开始颜色
    QColor getBorderOutColorStart() const;
    void setBorderOutColorStart(const QColor &borderOutColorStart);

    //获取和设置外边框渐变结束颜色
    QColor getBorderOutColorEnd() const;
    void setBorderOutColorEnd(const QColor &borderOutColorEnd);

    //获取和设置里边框渐变开始颜色
    QColor getBorderInColorStart() const;
    void setBorderInColorStart(const QColor &borderInColorStart);

    //获取和设置里边框渐变结束颜色
    QColor getBorderInColorEnd() const;
    void setBorderInColorEnd(const QColor &borderInColorEnd);

    //获取和设置背景色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置姿态仪背景
    QColor getPlaneColor() const;
    void setPlaneColor(const QColor &planeColor);

    //获取和设置遮罩层颜色
    QColor getGlassColor() const;
    void setGlassColor(const QColor &glassColor);

    //获取和设置刻度尺颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

    //获取和设置手柄颜色
    QColor getHandleColor() const;
    void setHandleColor(const QColor &handleColor);

    //获取和设置旋转角度值
    int getDegValue() const;
    void setDegValue(int degValue);

    //获取和设置前进旋转值
    int getRollValue() const;
    void setRollValue(int rollValue);

Q_SIGNALS:
    void degChanged(int degValue);
    void rollChanged(int rollValue);
};

#endif // GAUGEPLANE_H
