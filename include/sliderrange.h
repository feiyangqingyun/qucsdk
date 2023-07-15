#ifndef SLIDERRANGE_H
#define SLIDERRANGE_H

/**
 * 范围滑动条控件 作者:feiyangqingyun(QQ:517216493) 2016-12-24
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置当前范围值。
 * 3. 可设置范围值颜色、范围值外颜色、文字颜色。
 * 4. 自适应窗体拉伸，刻度尺和文字自动缩放。
 * 5. 可设置滑块条所占比例及滑块所占比例。
 * 6. 可设置多种滑块样式。
 * 7. 可设置是否显示当前值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT SliderRange : public QWidget
#else
class SliderRange : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(SliderStyle)
    Q_ENUMS(SliderBgPercent)
    Q_ENUMS(SliderPercent)

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int leftValue READ getLeftValue WRITE setLeftValue)
    Q_PROPERTY(int rightValue READ getRightValue WRITE setRightValue)

    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(bool horizontal READ getHorizontal WRITE setHorizontal)
    Q_PROPERTY(bool showText READ getShowText WRITE setShowText)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor rangeTextColor READ getRangeTextColor WRITE setRangeTextColor)
    Q_PROPERTY(QColor sliderColor READ getSliderColor WRITE setSliderColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

    Q_PROPERTY(SliderStyle sliderStyle READ getSliderStyle WRITE setSliderStyle)
    Q_PROPERTY(SliderBgPercent sliderBgPercent READ getSliderBgPercent WRITE setSliderBgPercent)
    Q_PROPERTY(SliderPercent sliderPercent READ getSliderPercent WRITE setSliderPercent)

public:
    enum SliderStyle {
        SliderStyle_Line = 0,       //线条状风格
        SliderStyle_Circle = 1      //圆形状风格
    };

    enum SliderBgPercent {
        SliderBgPercent_0_1 = 1,
        SliderBgPercent_0_2 = 2,
        SliderBgPercent_0_3 = 3,
        SliderBgPercent_0_4 = 4,
        SliderBgPercent_0_5 = 5,
        SliderBgPercent_0_6 = 6,
        SliderBgPercent_0_7 = 7,
        SliderBgPercent_0_8 = 8,
        SliderBgPercent_0_9 = 9,
        SliderBgPercent_1_0 = 10
    };

    enum SliderPercent {
        SliderPercent_0_1 = 1,
        SliderPercent_0_2 = 2,
        SliderPercent_0_3 = 3,
        SliderPercent_0_4 = 4,
        SliderPercent_0_5 = 5
    };

    explicit SliderRange(QWidget *parent = 0);
    ~SliderRange();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawSliderBg(QPainter *painter);
    void drawSliderLine(QPainter *painter);
    void drawSliderCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    int minValue;                   //最小值
    int maxValue;                   //最大值
    int leftValue;                  //范围值左边
    int rightValue;                 //范围值右边

    int borderWidth;                //滑块边框宽度
    bool horizontal;                //是否横向
    bool showText;                  //是否显示值

    QColor usedColor;               //范围值颜色
    QColor freeColor;               //范围值外颜色
    QColor textColor;               //文字颜色
    QColor rangeTextColor;          //范围文字颜色
    QColor sliderColor;             //滑块颜色
    QColor borderColor;             //滑块边框颜色

    SliderStyle sliderStyle;        //滑块风格
    SliderBgPercent sliderBgPercent;//滑块背景所占比例
    SliderPercent sliderPercent;    //滑块所占比例

    bool leftPressed;               //左边指示器是否按下
    bool rightPressed;              //右边指示器是否按下

    int sliderLen;                  //指示器长度
    QRect leftSliderRect;           //左边值指示器区域
    QRect rightSliderRect;          //右边值指示器区域

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getLeftValue()              const;
    int getRightValue()             const;

    int getBorderWidth()            const;
    bool getHorizontal()            const;
    bool getShowText()              const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;
    QColor getTextColor()           const;
    QColor getRangeTextColor()      const;
    QColor getSliderColor()         const;
    QColor getBorderColor()         const;

    SliderStyle getSliderStyle()    const;
    SliderBgPercent getSliderBgPercent()const;
    SliderPercent getSliderPercent()const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(int minValue);
    void setMaxValue(int maxValue);

    //设置当前范围值
    void setCurrentRange(int leftValue, int rightValue);
    void setLeftValue(int leftValue);
    void setRightValue(int rightValue);

    //设置滑块边框宽度
    void setBorderWidth(int borderWidth);

    //设置方向
    void setHorizontal(bool horizontal);

    //设置是否显示值
    void setShowText(bool showText);

    //设置刻度值颜色
    void setUsedColor(const QColor &usedColor);
    //设置指针颜色
    void setFreeColor(const QColor &freeColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);
    //设置文本颜色
    void setRangeTextColor(const QColor &rangeTextColor);
    //设置滑块颜色
    void setSliderColor(const QColor &sliderColor);
    //设置滑块边框颜色
    void setBorderColor(const QColor &borderColor);

    //设置滑块风格
    void setSliderStyle(const SliderStyle &sliderStyle);
    //设置滑块背景所占比例
    void setSliderBgPercent(const SliderBgPercent &sliderBgPercent);
    //设置滑块所占比例
    void setSliderPercent(const SliderPercent &sliderPercent);

Q_SIGNALS:
    void valueChanged(int leftValue, int rightValue);
};

#endif // SliderRange_H
