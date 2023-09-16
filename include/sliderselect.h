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
    int maxValue;           //最小值
    int minValue;           //最大值
    int leftValue;          //范围值左边
    int rightValue;         //范围值右边

    int rangeValue;         //当前范围值 最大值-最小值
    int step;               //单步步长

    int borderWidth;        //滑块边框宽度
    bool horizontal;        //是否横向

    QColor usedColor;       //范围值颜色
    QColor freeColor;       //范围值外颜色
    QColor textColor;       //文字颜色
    QColor rangeTextColor;  //范围文字颜色
    QColor sliderColor;     //滑块颜色
    QColor borderColor;     //滑块边框颜色
    QColor btnNormalColor;  //按钮正常颜色
    QColor btnPressColor;   //按钮按下颜色

    int btnWidth;           //左右步进按钮宽度
    int sliderHeight;       //控制滑块高度

    QPoint posPress;        //鼠标按下时的坐标
    QPoint posMove;         //鼠标拖动后的坐标

    bool sliderPress;       //主滑块按下
    bool leftPress;         //左控制滑块按下
    bool rightPress;        //右控制滑块按下
    bool leftBtnPress;      //左单步按钮按下
    bool rightBtnPress;     //右单步按钮按下

    QRect sliderRect;       //主滑块rect
    QRect leftRect;         //左控制滑块rect
    QRect rightRect;        //右控制滑块rect
    QRect leftBtnRect;      //左单步按钮rect
    QRect rightBtnRect;     //右单步按钮rect

    QRect sliderRectTemp;   //主滑块初始rect
    QRect leftRectTemp;     //左控制滑块初始rect
    QRect rightRectTemp;    //右控制滑块初始rect

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(int minValue, int maxValue);

    //获取和设置最小值
    int getMinValue() const;
    void setMinValue(int minValue);

    //获取和设置最大值
    int getMaxValue() const;
    void setMaxValue(int maxValue);

    //设置当前范围值
    void setCurrentRange(int leftValue, int rightValue);

    //设置左侧值/右侧值/范围值
    int getLeftValue() const;
    int getRightValue() const;
    int getRangeValue() const;

    //获取和设置单步步长
    int getStep() const;
    void setStep(int step);

    //获取和设置滑块边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置方向
    bool getHorizontal() const;
    void setHorizontal(bool horizontal);

    //获取和设置刻度值颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &usedColor);

    //获取和设置指针颜色
    QColor getFreeColor() const;
    void setFreeColor(const QColor &freeColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置文本颜色
    QColor getRangeTextColor() const;
    void setRangeTextColor(const QColor &rangeTextColor);

    //获取和设置滑块颜色
    QColor getSliderColor() const;
    void setSliderColor(const QColor &sliderColor);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置按钮正常颜色
    QColor getBtnNormalColor() const;
    void setBtnNormalColor(const QColor &btnNormalColor);

    //获取和设置按钮按下颜色
    QColor getBtnPressColor() const;
    void setBtnPressColor(const QColor &btnPressColor);

public Q_SLOTS:
    void setLeftValue(int leftValue);
    void setRightValue(int rightValue);
    void setRangeValue(int rangeValue);

Q_SIGNALS:
    void valueChanged(int leftValue, int rightValue);
    void rangeChanged(int rangeValue);
};

#endif // SLIDERSELECT_H
