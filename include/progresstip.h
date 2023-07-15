#ifndef PROGRESSTIP_H
#define PROGRESSTIP_H

/**
 * 提示进度条控件 作者:feiyangqingyun(QQ:517216493) 2019-10-05
 * 1. 可设置最小值、最大值、范围值、当前值。
 * 2. 可设置是否百分比显示。
 * 3. 可设置边距，流出空隙防止提示信息跑到外面。
 * 4. 可设置进度的颜色，可以是渐变画刷。
 * 5. 可设置背景颜色、文字颜色、提示背景。
 * 6. 可设置圆角角度。
 * 7. 如果设置了进度画刷则提示背景也采用该画刷。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressTip : public QWidget
#else
class ProgressTip : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)

    Q_PROPERTY(bool percent READ getPercent WRITE setPercent)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding)
    Q_PROPERTY(int radius READ getRadius WRITE setRadius)

    Q_PROPERTY(QBrush valueBrush READ getValueBrush WRITE setValueBrush)
    Q_PROPERTY(QColor valueColor READ getValueColor WRITE setValueColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor tipColor READ getTipColor WRITE setTipColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit ProgressTip(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawTip(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值

    bool percent;               //百分比显示
    int padding;                //边距
    int radius;                 //圆角角度

    QBrush valueBrush;          //进度画刷
    QColor valueColor;          //进度颜色
    QColor bgColor;             //背景颜色
    QColor tipColor;            //提示背景颜色
    QColor textColor;           //文字颜色

public:
    double getMinValue()        const;
    double getMaxValue()        const;
    double getValue()           const;

    bool getPercent()           const;
    int getPadding()            const;
    int getRadius()             const;

    QBrush getValueBrush()      const;
    QColor getValueColor()      const;
    QColor getBgColor()         const;
    QColor getTipColor()        const;
    QColor getTextColor()       const;

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

    //设置百分比显示
    void setPercent(bool percent);
    //设置边距
    void setPadding(int padding);
    //设置圆角角度
    void setRadius(int radius);

    //设置进度画刷+进度颜色+背景颜色+提示背景+文字颜色
    void setValueBrush(const QBrush &valueBrush);
    void setValueColor(const QColor &valueColor);
    void setBgColor(const QColor &bgColor);
    void setTipColor(const QColor &tipColor);
    void setTextColor(const QColor &textColor);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // PROGRESSPLAY_H
