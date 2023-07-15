#ifndef GAUGECAR_H
#define GAUGECAR_H

/**
 * 汽车仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-11-20
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置精确度，最大支持小数点后3位。
 * 3. 可设置大刻度数量、小刻度数量。
 * 4. 可设置开始旋转角度、结束旋转角度。
 * 5. 可设置外圆背景、内圆背景、饼圆三种颜色、刻度尺颜色、文字颜色。
 * 6. 自适应窗体拉伸，刻度尺、文字自动缩放。
 * 7. 可自由拓展各种渐变色，各圆的半径。
 * 8. 三色圆环按照比例设置范围角度，用户可以自由设置三色占用比例。
 * 9. 圆环样式可选择三色圆环、当前圆环。
 * 10. 指示器样式可选择圆形指示器、指针指示器、圆角指针指示器、三角形指示器。
 * 11. 可设置中间圆的宽度，以便使用更大数值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeCar : public QWidget
#else
class GaugeCar : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PieStyle)
    Q_ENUMS(PointerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(QColor outerCircleColor READ getOuterCircleColor WRITE setOuterCircleColor)
    Q_PROPERTY(QColor innerCircleColor READ getInnerCircleColor WRITE setInnerCircleColor)

    Q_PROPERTY(QColor pieColorStart READ getPieColorStart WRITE setPieColorStart)
    Q_PROPERTY(QColor pieColorMid READ getPieColorMid WRITE setPieColorMid)
    Q_PROPERTY(QColor pieColorEnd READ getPieColorEnd WRITE setPieColorEnd)

    Q_PROPERTY(QColor coverCircleColor READ getCoverCircleColor WRITE setCoverCircleColor)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor centerCircleColor READ getCenterCircleColor WRITE setCenterCircleColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(bool showOverlay READ getShowOverlay WRITE setShowOverlay)
    Q_PROPERTY(QColor overlayColor READ getOverlayColor WRITE setOverlayColor)

    Q_PROPERTY(int circleWidth READ getCircleWidth WRITE setCircleWidth)
    Q_PROPERTY(PieStyle pieStyle READ getPieStyle WRITE setPieStyle)
    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PieStyle {
        PieStyle_Three = 0,         	//三色圆环
        PieStyle_Current = 1        	//当前圆环
    };

    enum PointerStyle {
        PointerStyle_Circle = 0,        //圆形指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeCar(QWidget *parent = 0);
    ~GaugeCar();

protected:
    void paintEvent(QPaintEvent *);
    void drawOuterCircle(QPainter *painter);
    void drawInnerCircle(QPainter *painter);
    void drawColorPie(QPainter *painter);
    void drawCoverCircle(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawRoundCircle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawOverlay(QPainter *painter);

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值
    int precision;              //精确度,小数点后几位

    int scaleMajor;             //大刻度数量
    int scaleMinor;             //小刻度数量
    int startAngle;             //开始旋转角度
    int endAngle;               //结束旋转角度

    QColor outerCircleColor;    //外圆背景颜色
    QColor innerCircleColor;    //内圆背景颜色

    QColor pieColorStart;       //饼圆开始颜色
    QColor pieColorMid;         //饼圆中间颜色
    QColor pieColorEnd;         //饼圆结束颜色

    QColor coverCircleColor;    //覆盖圆背景颜色
    QColor scaleColor;          //刻度尺颜色
    QColor pointerColor;        //指针颜色
    QColor centerCircleColor;   //中心圆颜色
    QColor textColor;           //文字颜色

    bool showOverlay;           //显示遮罩层
    QColor overlayColor;        //遮罩层颜色

    int circleWidth;            //中间圆宽度
    PieStyle pieStyle;          //饼图样式
    PointerStyle pointerStyle;  //指针样式

public:
    double getMinValue()        const;
    double getMaxValue()        const;
    double getValue()           const;
    int getPrecision()          const;

    int getScaleMajor()         const;
    int getScaleMinor()         const;
    int getStartAngle()         const;
    int getEndAngle()           const;

    QColor getOuterCircleColor()const;
    QColor getInnerCircleColor()const;

    QColor getPieColorStart()   const;
    QColor getPieColorMid()     const;
    QColor getPieColorEnd()     const;

    QColor getCoverCircleColor()const;
    QColor getScaleColor()      const;
    QColor getPointerColor()    const;
    QColor getCenterCircleColor()const;
    QColor getTextColor()       const;

    bool getShowOverlay()       const;
    QColor getOverlayColor()    const;

    int getCircleWidth()        const;
    PieStyle getPieStyle()      const;
    PointerStyle getPointerStyle()const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

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

    //设置主刻度数量
    void setScaleMajor(int scaleMajor);
    //设置小刻度数量
    void setScaleMinor(int scaleMinor);
    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置外圆背景颜色
    void setOuterCircleColor(const QColor &outerCircleColor);
    //设置内圆背景颜色
    void setInnerCircleColor(const QColor &innerCircleColor);

    //设置饼圆三种颜色
    void setPieColorStart(const QColor &pieColorStart);
    void setPieColorMid(const QColor &pieColorMid);
    void setPieColorEnd(const QColor &pieColorEnd);

    //设置覆盖圆背景颜色
    void setCoverCircleColor(const QColor &coverCircleColor);
    //设置刻度尺颜色
    void setScaleColor(const QColor &scaleColor);
    //设置指针颜色
    void setPointerColor(const QColor &pointerColor);
    //设置中心圆颜色
    void setCenterCircleColor(const QColor &centerCircleColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);

    //设置是否显示遮罩层
    void setShowOverlay(bool showOverlay);
    //设置遮罩层颜色
    void setOverlayColor(const QColor &overlayColor);

    //设置中间圆宽度
    void setCircleWidth(int circleWidth);
    //设置饼图样式
    void setPieStyle(const PieStyle &pieStyle);
    //设置指针样式
    void setPointerStyle(const PointerStyle &pointerStyle);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // GAUGECAR_H
