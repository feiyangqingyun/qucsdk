#ifndef RULERSLIDER_H
#define RULERSLIDER_H

/**
 * 滑动标尺控件 作者:feiyangqingyun(QQ:517216493) 2016-10-28
 * 本控件来源于网络(原作者:kimtaikee(http://www.qtcn.org/bbs/read-htm-tid-33719-ds-1.html#tpc))
 * 1. 可设置精确度(小数点后几位)和间距。
 * 2. 可设置背景色、滑块颜色、提示信息背景前景色。
 * 3. 支持鼠标滚轮。
 * 4. 可设置长线条步长及短线条步长。
 * 5. 移除定时器实现显示和隐藏提示值。
 * 6. 可设置范围值。
 * 7. 支持负数刻度值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerSlider : public QWidget
#else
class RulerSlider : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int longStep READ getLongStep WRITE setLongStep)
    Q_PROPERTY(int shortStep READ getShortStep WRITE setShortStep)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

    Q_PROPERTY(QColor sliderColorTop READ getSliderColorTop WRITE setSliderColorTop)
    Q_PROPERTY(QColor sliderColorBottom READ getSliderColorBottom WRITE setSliderColorBottom)

    Q_PROPERTY(QColor tipBgColor READ getTipBgColor WRITE setTipBgColor)
    Q_PROPERTY(QColor tipTextColor READ getTipTextColor WRITE setTipTextColor)

public:
    explicit RulerSlider(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);
    void wheelEvent(QWheelEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawRule(QPainter *painter);
    void drawSlider(QPainter *painter);
    void drawTip(QPainter *painter);

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值
    int precision;              //精确度

    int longStep;               //长线条等分步长
    int shortStep;              //短线条等分步长
    int space;                  //间距

    QColor bgColorStart;        //背景渐变开始颜色
    QColor bgColorEnd;          //背景渐变结束颜色
    QColor lineColor;           //线条颜色

    QColor sliderColorTop;      //滑块上部颜色
    QColor sliderColorBottom;   //滑块下部颜色

    QColor tipBgColor;          //当前值背景色
    QColor tipTextColor;        //当前值文字颜色

    bool pressed;               //是否鼠标按下
    double currentValue;        //当前值

    double longLineHeight;      //长刻度高度
    double shortLineHeight;     //短刻度高度
    double sliderTopHeight;     //滑块上部高度
    double sliderBottomHeight;  //滑块底部高度

    QPointF sliderLastPot;      //滑块最后的坐标
    QPointF sliderTopPot;       //滑块顶部坐标
    QPointF sliderLeftPot;      //滑块左边坐标
    QPointF sliderRightPot;     //滑块右边坐标

    QRectF sliderRect;          //滑块矩形区域
    QRectF tipRect;             //提示信息矩形区域
    QPointF lineLeftPot;        //主线左边坐标
    QPointF lineRightPot;       //主线右边坐标

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

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置线条等分步长
    int getLongStep() const;
    void setLongStep(int longStep);

    int getShortStep() const;
    void setShortStep(int shortStep);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置背景颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置滑块颜色
    QColor getSliderColorTop() const;
    void setSliderColorTop(const QColor &sliderColorTop);

    QColor getSliderColorBottom() const;
    void setSliderColorBottom(const QColor &sliderColorBottom);

    //获取和设置提示信息背景
    QColor getTipBgColor() const;
    void setTipBgColor(const QColor &tipBgColor);

    QColor getTipTextColor() const;
    void setTipTextColor(const QColor &tipTextColor);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // RULERSLIDER_H
