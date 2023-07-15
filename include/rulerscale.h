#ifndef RULERSCALE_H
#define RULERSCALE_H

/**
 * 半圆标尺控件 作者:feiyangqingyun(QQ:517216493) 2018-08-27
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置刻度尺颜色、刻度值颜色、指针颜色、底部线条颜色、盖子颜色、文本颜色。
 * 3. 可设置大刻度尺间隔。
 * 4. 可设置小刻度尺数量。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RulerScale : public QWidget
#else
class RulerScale : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)

    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor scaleNumColor READ getScaleNumColor WRITE setScaleNumColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor coverColor READ getCoverColor WRITE setCoverColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit RulerScale(QWidget *parent = 0);
    ~RulerScale();

protected:
    void paintEvent(QPaintEvent *);

private:
    int minValue;                   //最小值
    int maxValue;                   //最大值
    int value;                      //目标值

    int borderWidth;                //边框宽度
    int scaleMajor;                 //大刻度数量
    int scaleMinor;                 //小刻度数量

    QColor scaleColor;              //刻度尺颜色
    QColor scaleNumColor;           //刻度值颜色
    QColor pointerColor;            //指针颜色
    QColor borderColor;             //底部边框颜色
    QColor coverColor;              //盖子颜色
    QColor textColor;               //文本颜色

    Qt::Orientations orientation;   //方向

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getValue()                  const;

    int getBorderWidth()            const;
    int getScaleMajor()             const;
    int getScaleMinor()             const;

    QColor getScaleColor()          const;
    QColor getScaleNumColor()       const;
    QColor getPointerColor()        const;
    QColor getBorderColor()         const;
    QColor getCoverColor()          const;
    QColor getTextColor()           const;

    Qt::Orientations getOrientation()const;

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

    //设置边框宽度
    void setBorderWidth(int borderWidth);
    //设置主刻度数量
    void setScaleMajor(int scaleMajor);
    //设置小刻度数量
    void setScaleMinor(int scaleMinor);

    //设置刻度尺颜色
    void setScaleColor(const QColor &scaleColor);
    //设置刻度值颜色
    void setScaleNumColor(const QColor &scaleNumColor);
    //设置指针颜色
    void setPointerColor(const QColor &pointerColor);
    //设置底部边框颜色
    void setBorderColor(const QColor &borderColor);
    //设置盖子颜色
    void setCoverColor(const QColor &coverColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);

    //设置刻度尺方向
    void setOrientation(const Qt::Orientations &orientation);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // RULERSCALE_H
