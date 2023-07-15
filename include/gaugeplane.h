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
    QColor borderOutColorStart;     //外边框渐变开始颜色
    QColor borderOutColorEnd;       //外边框渐变结束颜色
    QColor borderInColorStart;      //里边框渐变开始颜色
    QColor borderInColorEnd;        //里边框渐变结束颜色

    QColor bgColor;                 //背景颜色
    QColor planeColor;              //姿态仪背景
    QColor glassColor;              //遮罩层颜色
    QColor scaleColor;              //刻度尺颜色
    QColor lineColor;               //线条颜色
    QColor textColor;               //文字颜色
    QColor pointerColor;            //指针颜色
    QColor handleColor;             //手柄颜色

    int degValue;                   //旋转角度
    int rollValue;                  //滚动值

public:
    QColor getBorderOutColorStart() const;
    QColor getBorderOutColorEnd()   const;
    QColor getBorderInColorStart()  const;
    QColor getBorderInColorEnd()    const;

    QColor getBgColor()             const;
    QColor getPlaneColor()          const;
    QColor getGlassColor()          const;
    QColor getScaleColor()          const;
    QColor getLineColor()           const;
    QColor getTextColor()           const;
    QColor getPointerColor()        const;
    QColor getHandleColor()         const;

    int getDegValue()               const;
    int getRollValue()              const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置外边框渐变颜色
    void setBorderOutColorStart(const QColor &borderOutColorStart);
    void setBorderOutColorEnd(const QColor &borderOutColorEnd);

    //设置里边框渐变颜色
    void setBorderInColorStart(const QColor &borderInColorStart);
    void setBorderInColorEnd(const QColor &borderInColorEnd);

    //设置背景色
    void setBgColor(const QColor &bgColor);

    //设置姿态仪背景
    void setPlaneColor(const QColor &planeColor);

    //设置遮罩层颜色
    void setGlassColor(const QColor &glassColor);

    //设置刻度尺颜色
    void setScaleColor(const QColor &scaleColor);

    //设置线条颜色
    void setLineColor(const QColor &lineColor);

    //设置文字颜色
    void setTextColor(const QColor &textColor);

    //设置指针颜色
    void setPointerColor(const QColor &pointerColor);

    //设置手柄颜色
    void setHandleColor(const QColor &handleColor);

    //设置旋转角度值
    void setDegValue(int degValue);
    //设置前进旋转值
    void setRollValue(int rollValue);

Q_SIGNALS:
    void degChanged(int degValue);
    void rollChanged(int rollValue);
};

#endif // GAUGEPLANE_H
