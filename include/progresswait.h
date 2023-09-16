#ifndef PROGRESSWAIT_H
#define PROGRESSWAIT_H

/**
 * 等待进度条控件 作者:feiyangqingyun(QQ:517216493) 2016-10-28
 * 1. 支持多种等待样式风格 圆弧状风格、旋转圆风格、三角圆弧、线条风格、圆环风格。
 * 2. 可设置范围值和当前值。
 * 3. 可设置前景色背景色。
 * 4. 可设置顺时针逆时针旋转。
 * 5. 支持任意大小缩放。
 * 6. 支持设置旋转速度间隔。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressWait : public QWidget
#else
class ProgressWait : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(BarStyle)

    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)
    Q_PROPERTY(bool showPercent READ getShowPercent WRITE setShowPercent)

    Q_PROPERTY(int currentValue READ getCurrentValue WRITE setCurrentValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int interval READ getInterval WRITE setInterval)

    Q_PROPERTY(BarStyle barStyle READ getBarStyle WRITE setBarStyle)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    enum BarStyle {
        BarStyle_Arc = 0,           //圆弧状风格
        BarStyle_RoundCircle = 1,   //旋转圆风格
        BarStyle_Pie = 2,           //三角圆弧风格
        BarStyle_Line = 3,          //线条风格
        BarStyle_Ring = 4,          //圆环风格
        BarStyle_SingleCircle = 5,  //一个圆闪烁
        BarStyle_DoubleCircle = 6   //两个圆闪烁
    };

    explicit ProgressWait(QWidget *parent = 0);
    ~ProgressWait();

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void drawArc(QPainter *painter);
    void drawRoundCircle(QPainter *painter);
    void drawPie(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawRing(QPainter *painter);
    void drawSingleCircle(QPainter *painter);
    void drawDoubleCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    bool clockWise;         //顺时针逆时针
    bool showPercent;       //显示当前百分比
    int currentValue;       //当前值
    int maxValue;           //最大值
    int interval;           //旋转间隔

    BarStyle barStyle;      //样式
    QColor background;      //背景色
    QColor foreground;      //前景色
    QColor textColor;       //文字颜色

    int minRadius;          //最小半径
    int maxRadius;          //最大半径
    int offsetRadius;       //半径偏移量

    int leftRadius;         //左边圆半径
    int rightRadius;        //右边圆半径
    bool leftIncrease;      //左边递增
    bool rightIncrease;     //右边递增

    QTimer *timer;          //定时器绘制
    double degreesToRadians(double value);

private slots:
    void updateValue();     //更新值

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置顺时针逆时针旋转
    bool getClockWise() const;
    void setClockWise(bool clockWise);

    //获取和设置是否显示百分比
    bool getShowPercent() const;
    void setShowPercent(bool showPercent);

    //获取和设置当前值
    int getCurrentValue() const;
    void setCurrentValue(int currentValue);

    //获取和设置最大值
    int getMaxValue() const;
    void setMaxValue(int maxValue);

    //获取和设置旋转速度间隔
    int getInterval() const;
    void setInterval(int interval);

    //获取和设置样式
    BarStyle getBarStyle() const;
    void setBarStyle(const BarStyle &barStyle);

    //获取和设置前景色
    QColor getBackground() const;
    void setBackground(const QColor &background);

    //获取和设置前景色
    QColor getForeground() const;
    void setForeground(const QColor &foreground);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);
};

#endif // PROGRESSWAIT_H
