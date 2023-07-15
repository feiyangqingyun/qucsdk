#ifndef WAVEBAR_H
#define WAVEBAR_H

/**
 * 直方动态图控件 作者:feiyangqingyun(QQ:517216493) 2016-11-06
 * 1. 可设置范围值、当前值、步长、圆角角度。
 * 2. 可设置顶部滑块高度。
 * 3. 可设置背景颜色和柱状条颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT WaveBar : public QWidget
#else
class WaveBar : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

    Q_PROPERTY(double step READ getStep WRITE setStep)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)
    Q_PROPERTY(int headHeight READ getHeadHeight WRITE setHeadHeight)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
    Q_PROPERTY(QColor barColor READ getBarColor WRITE setBarColor)

public:
    explicit WaveBar(QWidget *parent = 0);
    ~WaveBar();

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBar(QPainter *painter);
    void drawHead(QPainter *painter);

private:
    int minValue;                   //最小值
    int maxValue;                   //最大值
    int value;                      //目标值

    double step;                    //步长
    int space;                      //间距
    int headHeight;                 //顶部条块高度

    QColor bgColorStart;            //背景渐变开始颜色
    QColor bgColorEnd;              //背景渐变结束颜色
    QColor barColor;                //柱状条颜色

    int currentValue;               //当前值
    double headY;                   //顶部条块Y轴坐标
    double barY;                    //柱状条块Y轴坐标
    QTimer *barTimer;               //柱状条块下降定时器
    QTimer *headTimer;              //顶部条块下坠定时器

private slots:
    void updateBar();
    void updateHead();

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getValue()                  const;

    double getStep()                const;
    int getSpace()                  const;
    int getHeadHeight()             const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;
    QColor getBarColor()            const;

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

    //设置步长
    void setStep(double step);
    //设置间距
    void setSpace(int space);
    //设置顶部条块高度
    void setHeadHeight(int headHeight);

    //设置背景颜色
    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);

    //设置柱状条颜色
    void setBarColor(const QColor &barColor);
};

#endif // WAVEBAR_H
