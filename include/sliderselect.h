#ifndef SLIDERSELECT_H
#define SLIDERSELECT_H

/**
 * 滑动选择条控件 作者:逆风微光(QQ:787701109) 整理:飞扬青云(QQ:517216493) 2017-08-30
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置当前范围值。
 * 3. 可设置范围值颜色、范围值外颜色、文字颜色。
 * 4. 自适应窗体拉伸，刻度尺和文字自动缩放。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT SliderSelect : public QWidget
#else
class SliderSelect : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int leftValue READ getLeftValue WRITE setLeftValue)
    Q_PROPERTY(int rightValue READ getRightValue WRITE setRightValue)

    Q_PROPERTY(int rangeValue READ getRangeValue WRITE setRangeValue)
    Q_PROPERTY(int step READ getStep WRITE setStep)

    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(bool horizontal READ getHorizontal WRITE setHorizontal)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor rangeTextColor READ getRangeTextColor WRITE setRangeTextColor)
    Q_PROPERTY(QColor sliderColor READ getSliderColor WRITE setSliderColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor btnNormalColor READ getBtnNormalColor WRITE setBtnNormalColor)
    Q_PROPERTY(QColor btnPressColor READ getBtnPressColor WRITE setBtnPressColor)

public:
    explicit SliderSelect(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawBtn(QPainter *painter);
    void drawSlider(QPainter *painter);
    void updateUI();

private:
    int maxValue;                   //最小值
    int minValue;                   //最大值
    int leftValue;                  //范围值左边
    int rightValue;                 //范围值右边

    int rangeValue;                 //当前范围值 最大值-最小值
    int step;                       //单步步长

    int borderWidth;                //滑块边框宽度
    bool horizontal;                //是否横向

    QColor usedColor;               //范围值颜色
    QColor freeColor;               //范围值外颜色
    QColor textColor;               //文字颜色
    QColor rangeTextColor;          //范围文字颜色
    QColor sliderColor;             //滑块颜色
    QColor borderColor;             //滑块边框颜色
    QColor btnNormalColor;          //按钮正常颜色
    QColor btnPressColor;           //按钮按下颜色

    int btnWidth;                   //左右步进按钮宽度
    int sliderHeight;               //控制滑块高度

    QPoint posPress;                //鼠标按下时的坐标
    QPoint posMove;                 //鼠标拖动后的坐标

    bool sliderPress;               //主滑块按下
    bool leftPress;                 //左控制滑块按下
    bool rightPress;                //右控制滑块按下
    bool leftBtnPress;              //左单步按钮按下
    bool rightBtnPress;             //右单步按钮按下

    QRect sliderRect;               //主滑块rect
    QRect leftRect;                 //左控制滑块rect
    QRect rightRect;                //右控制滑块rect
    QRect leftBtnRect;              //左单步按钮rect
    QRect rightBtnRect;             //右单步按钮rect

    QRect sliderRectTemp;           //主滑块初始rect
    QRect leftRectTemp;             //左控制滑块初始rect
    QRect rightRectTemp;            //右控制滑块初始rect

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getLeftValue()              const;
    int getRightValue()             const;

    int getRangeValue()             const;
    int getStep()                   const;

    int getBorderWidth()            const;
    bool getHorizontal()            const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;
    QColor getTextColor()           const;
    QColor getRangeTextColor()      const;
    QColor getSliderColor()         const;
    QColor getBorderColor()         const;
    QColor getBtnNormalColor()      const;
    QColor getBtnPressColor()       const;

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

    //设置范围宽度
    void setRangeValue(int rangeValue);

    //设置单步步长
    void setStep(int step);

    //设置滑块边框宽度
    void setBorderWidth(int borderWidth);

    //设置方向
    void setHorizontal(bool horizontal);

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
    //设置边框颜色
    void setBorderColor(const QColor &borderColor);

    //设置按钮正常颜色
    void setBtnNormalColor(const QColor &btnNormalColor);
    //设置按钮按下颜色
    void setBtnPressColor(const QColor &btnPressColor);

Q_SIGNALS:
    void valueChanged(int leftValue, int rightValue);
    void rangeChanged(int rangeValue);
};

#endif // SLIDERSELECT_H
