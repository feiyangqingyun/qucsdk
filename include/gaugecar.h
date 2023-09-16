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

    Q_PROPERTY(double piePercentStart READ getPiePercentStart WRITE setPiePercentStart)
    Q_PROPERTY(double piePercentMid READ getPiePercentMid WRITE setPiePercentMid)
    Q_PROPERTY(double piePercentEnd READ getPiePercentEnd WRITE setPiePercentEnd)

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
    int precision;              //精确度(小数点后几位)

    int scaleMajor;             //大刻度数量
    int scaleMinor;             //小刻度数量
    int startAngle;             //开始旋转角度
    int endAngle;               //结束旋转角度

    double piePercentStart;     //饼圆开始占比
    double piePercentMid;       //饼圆中间占比
    double piePercentEnd;       //饼圆结束占比

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

    //获取和设置当前值
    double getValue() const;
    void setValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置主刻度数量
    int getScaleMajor() const;
    void setScaleMajor(int scaleMajor);

    //获取和设置小刻度数量
    int getScaleMinor() const;
    void setScaleMinor(int scaleMinor);

    //获取和设置开始旋转角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);

    //获取和设置结束旋转角度
    int getEndAngle() const;
    void setEndAngle(int endAngle);

    //获取和设置开始饼圆占比
    double getPiePercentStart() const;
    void setPiePercentStart(double piePercentStart);

    //获取和设置中间饼圆占比
    double getPiePercentMid() const;
    void setPiePercentMid(double piePercentMid);

    //获取和设置结束饼圆占比
    double getPiePercentEnd() const;
    void setPiePercentEnd(double piePercentEnd);

    //获取和设置外圆背景颜色
    QColor getOuterCircleColor() const;
    void setOuterCircleColor(const QColor &outerCircleColor);

    //获取和设置内圆背景颜色
    QColor getInnerCircleColor() const;
    void setInnerCircleColor(const QColor &innerCircleColor);

    //获取和设置开始饼圆颜色
    QColor getPieColorStart() const;
    void setPieColorStart(const QColor &pieColorStart);

    //获取和设置中间饼圆颜色
    QColor getPieColorMid() const;
    void setPieColorMid(const QColor &pieColorMid);

    //获取和设置结束饼圆颜色
    QColor getPieColorEnd() const;
    void setPieColorEnd(const QColor &pieColorEnd);

    //获取和设置覆盖圆背景颜色
    QColor getCoverCircleColor() const;
    void setCoverCircleColor(const QColor &coverCircleColor);

    //获取和设置刻度尺颜色
    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

    //获取和设置中心圆颜色
    QColor getCenterCircleColor() const;
    void setCenterCircleColor(const QColor &centerCircleColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置是否显示遮罩层
    bool getShowOverlay() const;
    void setShowOverlay(bool showOverlay);

    //获取和设置遮罩层颜色
    QColor getOverlayColor() const;
    void setOverlayColor(const QColor &overlayColor);

    //获取和设置中间圆宽度
    int getCircleWidth() const;
    void setCircleWidth(int circleWidth);

    //获取和设置饼图样式
    PieStyle getPieStyle() const;
    void setPieStyle(const PieStyle &pieStyle);

    //获取和设置指针样式
    PointerStyle getPointerStyle() const;
    void setPointerStyle(const PointerStyle &pointerStyle);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(int value);
};

#endif // GAUGECAR_H
