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
        PercentStyle_Arc = 0,           //圆弧风格
        PercentStyle_Polo = 1,          //水池风格
        PercentStyle_Wave = 2,          //波纹风格
        PercentStyle_Arc_Polo = 3,      //圆弧水池风格
        PercentStyle_Arc_Wave = 4       //圆弧波纹风格
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
    int maxValue;                   //最小值
    int minValue;                   //最大值
    int value;                      //目标值

    int nullPosition;               //起始角度
    int borderWidth;                //边框宽度

    double waterHeight;             //水波高度
    double waterDensity;            //水波密度

    bool showPercent;               //是否显示百分比
    bool showFree;                  //是否显示未使用进度
    bool showSmallCircle;           //是否显示小圆
    bool clockWise;                 //顺时针
    bool borderOut;                 //外边框

    QColor usedColor;               //已使用百分比颜色
    QColor freeColor;               //未使用百分比颜色
    QColor circleColor;             //圆颜色
    QColor textColor;               //文字颜色

    PercentStyle percentStyle;      //进度样式风格

    double offset;                  //水波偏移量
    QTimer *timer;                  //定时器绘制动画

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getValue()                  const;

    int getNullPosition()           const;
    int getBorderWidth()            const;

    double getWaterHeight()         const;
    double getWaterDensity()        const;

    bool getShowPercent()           const;
    bool getShowFree()              const;
    bool getShowSmallCircle()       const;
    bool getClockWise()             const;
    bool getBorderOut()             const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;
    QColor getCircleColor()         const;
    QColor getTextColor()           const;

    PercentStyle getPercentStyle()  const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(int minValue);
    void setMaxValue(int maxValue);

    //设置目标值
    void setValue(int value);

    //设置最小值位置
    void setNullPosition(int nullPosition);
    //设置边框宽度
    void setBorderWidth(int borderWidth);

    //设置水波高度
    void setWaterHeight(double waterHeight);
    //设置水波密度
    void setWaterDensity(double waterDensity);

    //设置是否显示百分比
    void setShowPercent(bool showPercent);
    //设置是否显示剩余进度
    void setShowFree(bool showFree);
    //设置是否显示小圆
    void setShowSmallCircle(bool showSmallCircle);
    //设置进度旋转方向 顺时针或者逆时针
    void setClockWise(bool clockWise);
    //设置边框是否突出
    void setBorderOut(bool borderOut);

    //设置已使用百分比颜色
    void setUsedColor(const QColor &usedColor);
    //设置未使用百分比颜色
    void setFreeColor(const QColor &freeColor);
    //设置圆颜色
    void setCircleColor(const QColor &circleColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);

    //设置进度样式风格
    void setPercentStyle(const PercentStyle &percentStyle);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif //PROGRESSPERCENT_H
