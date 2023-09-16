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
    double minValue;    //最小值
    double maxValue;    //最大值
    double value;       //目标值

    bool percent;       //百分比显示
    int padding;        //边距
    int radius;         //圆角角度

    QBrush valueBrush;  //进度画刷
    QColor valueColor;  //进度颜色
    QColor bgColor;     //背景颜色
    QColor tipColor;    //提示背景颜色
    QColor textColor;   //文字颜色

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

    //获取和设置百分比显示
    bool getPercent() const;
    void setPercent(bool percent);

    //获取和设置边距
    int getPadding() const;
    void setPadding(int padding);

    //获取和设置圆角角度
    int getRadius() const;
    void setRadius(int radius);

    //获取和设置进度画刷
    QBrush getValueBrush() const;
    void setValueBrush(const QBrush &valueBrush);

    //获取和设置进度颜色
    QColor getValueColor() const;
    void setValueColor(const QColor &valueColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置提示背景
    QColor getTipColor() const;
    void setTipColor(const QColor &tipColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // PROGRESSPLAY_H
