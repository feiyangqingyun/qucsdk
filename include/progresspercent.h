#ifndef PROGRESSPERCENT_H
#define PROGRESSPERCENT_H

/**
 * 百分比进度条控件 作者:feiyangqingyun(QQ:517216493) 2017-08-22
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置起始点度数。
 * 3. 可设置顺时针逆时针。
 * 4. 可设置进度条或者线条宽度。
 * 5. 可设置是否显示百分比。
 * 6. 可设置是否同时显示剩余进度条。
 * 7. 可设置是否显示进度前面的小圆。
 * 8. 可设置边框是否突出。
 * 9. 可设置当前进度颜色、剩余进度颜色、文字颜色、中间圆颜色。
 * 10. 提供五种样式风格选择圆弧风格、水池风格、波纹风格、圆弧水池风格、圆弧波纹风格。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressPercent : public QWidget
#else
class ProgressPercent : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PercentStyle)

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

    Q_PROPERTY(int nullPosition READ getNullPosition WRITE setNullPosition)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)

    Q_PROPERTY(double waterHeight READ getWaterHeight WRITE setWaterHeight)
    Q_PROPERTY(double waterDensity READ getWaterDensity WRITE setWaterDensity)

    Q_PROPERTY(bool showPercent READ getShowPercent WRITE setShowPercent)
    Q_PROPERTY(bool showFree READ getShowFree WRITE setShowFree)
    Q_PROPERTY(bool showSmallCircle READ getShowSmallCircle WRITE setShowSmallCircle)
    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)
    Q_PROPERTY(bool borderOut READ getBorderOut WRITE setBorderOut)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)
    Q_PROPERTY(QColor circleColor READ getCircleColor WRITE setCircleColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(PercentStyle percentStyle READ getPercentStyle WRITE setPercentStyle)

public:
    enum PercentStyle {
        PercentStyle_Arc = 0,       //圆弧风格
        PercentStyle_Polo = 1,      //水池风格
        PercentStyle_Wave = 2,      //波纹风格
        PercentStyle_Arc_Polo = 3,  //圆弧水池风格
        PercentStyle_Arc_Wave = 4   //圆弧波纹风格
    };

    explicit ProgressPercent(QWidget *parent = 0);
    ~ProgressPercent();

protected:
    void paintEvent(QPaintEvent *);
    void drawCircle(QPainter *painter, int radius);
    void drawArc(QPainter *painter, int radius);
    void drawPolo(QPainter *painter, int radius);
    void drawWave(QPainter *painter, int radius);
    void drawValue(QPainter *painter, int radius);

private:
    int maxValue;           //最小值
    int minValue;           //最大值
    int value;              //目标值

    int nullPosition;       //起始角度
    int borderWidth;        //边框宽度

    double waterHeight;     //水波高度
    double waterDensity;    //水波密度

    bool showPercent;       //是否显示百分比
    bool showFree;          //是否显示未使用进度
    bool showSmallCircle;   //是否显示小圆
    bool clockWise;         //顺时针
    bool borderOut;         //外边框

    QColor usedColor;       //已使用百分比颜色
    QColor freeColor;       //未使用百分比颜色
    QColor circleColor;     //圆颜色
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

    //获取和设置最小值位置
    int getNullPosition() const;    

    //获取和设置边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置水波高度
    double getWaterHeight() const;
    void setWaterHeight(double waterHeight);

    //获取和设置水波密度
    double getWaterDensity() const;
    void setWaterDensity(double waterDensity);

    //获取和设置是否显示百分比
    bool getShowPercent() const;
    void setShowPercent(bool showPercent);

    //获取和设置是否显示剩余进度
    bool getShowFree() const;
    void setShowFree(bool showFree);

    //获取和设置是否显示小圆
    bool getShowSmallCircle() const;
    void setShowSmallCircle(bool showSmallCircle);

    //获取和设置进度旋转方向 顺时针或者逆时针
    bool getClockWise() const;
    void setClockWise(bool clockWise);

    //获取和设置边框是否突出
    bool getBorderOut() const;
    void setBorderOut(bool borderOut);

    //获取和设置已使用百分比颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &usedColor);

    //获取和设置未使用百分比颜色
    QColor getFreeColor() const;
    void setFreeColor(const QColor &freeColor);

    //获取和设置圆颜色
    QColor getCircleColor() const;
    void setCircleColor(const QColor &circleColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置进度样式风格
    PercentStyle getPercentStyle() const;
    void setPercentStyle(const PercentStyle &percentStyle);

public Q_SLOTS:
    void setValue(int value);
    void setNullPosition(int nullPosition);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif //PROGRESSPERCENT_H
