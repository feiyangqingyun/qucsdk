#ifndef PROGRESSWATER_H
#define PROGRESSWATER_H

/**
 * 水波进度条控件 作者:feiyangqingyun(QQ:517216493) 2017-08-23
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置水波密度，密度越大浪越多。
 * 3. 可设置水波高度，高度越大越浪。
 * 4. 可设置边框宽度和边框边距。
 * 5. 可设置是否显示进度值。
 * 6. 可设置进度值是否为百分比格式。
 * 7. 可设置背景颜色、边框颜色、当前进度颜色、文字颜色。
 * 8. 可设置两条波浪是否反着走，类似迅雷进度球风格。
 * 9. 提供槽函数启动和停止浪。
 * 10. 提供四种样式风格选择 矩形风格、圆形风格、椭圆风格、圆柱风格。
 */

#include <QWidget>

class QTimer;

#ifdef quc
class Q_DECL_EXPORT ProgressWater : public QWidget
#else
class ProgressWater : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PercentStyle)

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

    Q_PROPERTY(double borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(double borderPadding READ getBorderPadding WRITE setBorderPadding)
    Q_PROPERTY(double waterHeight READ getWaterHeight WRITE setWaterHeight)
    Q_PROPERTY(double waterDensity READ getWaterDensity WRITE setWaterDensity)

    Q_PROPERTY(bool showValue READ getShowValue WRITE setShowValue)
    Q_PROPERTY(bool showPercent READ getShowPercent WRITE setShowPercent)
    Q_PROPERTY(bool reverse READ getReverse WRITE setReverse)

    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(PercentStyle percentStyle READ getPercentStyle WRITE setPercentStyle)

public:
    enum PercentStyle {
        PercentStyle_Rect = 0,      //矩形风格
        PercentStyle_Circle = 1,    //圆形风格
        PercentStyle_Ellipse = 2,   //椭圆风格
        PercentStyle_Cylinder = 3   //圆柱风格
    };

    explicit ProgressWater(QWidget *parent = 0);
    ~ProgressWater();

protected:
    void paintEvent(QPaintEvent *);
    void drawBorder(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    int maxValue;           //最小值
    int minValue;           //最大值
    int value;              //目标值

    double borderWidth;     //边框宽度
    double borderPadding;   //边框间距
    double waterHeight;     //水波高度
    double waterDensity;    //水波密度

    bool showValue;         //是否显示值
    bool showPercent;       //是否显示百分比
    bool reverse;           //反向

    QColor borderColor;     //边框颜色
    QColor bgColor;         //背景颜色
    QColor usedColor;       //进度颜色
    QColor textColor;       //文字颜色

    PercentStyle percentStyle;//进度样式风格

    double offset;          //水波偏移量
    QTimer *timer;          //定时器绘制动画

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

    //获取和设置目标值
    int getValue() const;

    //获取和设置边框宽度
    double getBorderWidth() const;
    void setBorderWidth(double borderWidth);

    //获取和设置边框间距
    double getBorderPadding() const;
    void setBorderPadding(double borderPadding);

    //获取和设置水波高度
    double getWaterHeight() const;
    void setWaterHeight(double waterHeight);

    //获取和设置水波密度
    double getWaterDensity() const;
    void setWaterDensity(double waterDensity);

    //获取和设置是否显示值
    bool getShowPercent() const;
    void setShowValue(bool showValue);

    //获取和设置是否显示百分比
    bool getShowValue() const;
    void setShowPercent(bool showPercent);

    //获取和设置波浪是否反向走
    bool getReverse() const;
    void setReverse(bool reverse);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置进度颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &usedColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置进度样式风格
     PercentStyle getPercentStyle() const;
    void setPercentStyle(const PercentStyle &percentStyle);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);
    //启动和停止波浪
    void start();
    void stop();

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // PROGRESSWATER_H
