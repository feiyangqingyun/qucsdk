#ifndef PROGRESSARC_H
#define PROGRESSARC_H

/**
 * 百分比仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2018-08-30
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置精确度，最大支持小数点后3位。
 * 3. 可设置圆弧宽度。
 * 4. 可设置开始旋转角度、结束旋转角度。
 * 5. 可设置仪表盘的标题。
 * 6. 可设置背景颜色、进度颜色、值颜色、文字颜色。
 * 7. 自适应窗体拉伸，文字自动缩放。
 * 8. 可自由拓展各种渐变色。
 * 9. 可设置百分比模式，自动计算值换算成百分比。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressArc : public QWidget
#else
class ProgressArc : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(QColor arcColor READ getArcColor WRITE setArcColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor titleColor READ getTitleColor WRITE setTitleColor)
    Q_PROPERTY(QColor baseColor READ getBaseColor WRITE setBaseColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

    Q_PROPERTY(bool percent READ getPercent WRITE setPercent)
    Q_PROPERTY(int arcWidth READ getArcWidth WRITE setArcWidth)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)

public:
    explicit ProgressArc(QWidget *parent = 0);
    ~ProgressArc();

protected:
    void paintEvent(QPaintEvent *);
    void drawArc(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawTitle(QPainter *painter);

private:
    double minValue;    //最小值
    double maxValue;    //最大值
    double value;       //目标值
    int precision;      //精确度(小数点后几位)

    int startAngle;     //开始旋转角度
    int endAngle;       //结束旋转角度

    QColor arcColor;    //圆弧颜色
    QColor textColor;   //文字颜色
    QColor titleColor;  //标题颜色
    QColor baseColor;   //基准颜色
    QColor bgColor;     //背景颜色

    bool percent;       //百分比模式
    int arcWidth;       //圆弧宽度
    QString title;      //标题

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

    //获取和设置开始旋转角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);

    //获取和设置结束旋转角度
    int getEndAngle() const;
    void setEndAngle(int endAngle);

    //获取和设置圆弧颜色
    QColor getArcColor() const;
    void setArcColor(const QColor &arcColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置标题颜色
    QColor getTitleColor() const;
    void setTitleColor(const QColor &titleColor);

    //获取和设置基准颜色
    QColor getBaseColor() const;
    void setBaseColor(const QColor &baseColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置百分比模式
    bool getPercent() const;
    void setPercent(bool percent);

    //获取和设置圆弧宽度
    int getArcWidth() const;
    void setArcWidth(int arcWidth);

    //获取和设置标题
    QString getTitle() const;
    void setTitle(const QString &title);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // PROGRESSARC_H
