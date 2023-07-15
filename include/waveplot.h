#ifndef WAVEPLOT_H
#define WAVEPLOT_H

/**
 * 正弦曲线控件 作者:feiyangqingyun(QQ:517216493) 2017-02-10
 * 1. 可设置波浪的速度。
 * 2. 可设置波浪的高度。
 * 3. 可设置波浪的密度，密度越大越浪。
 * 4. 可设置背景颜色。
 * 5. 可设置波浪颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT WavePlot : public QWidget
#else
class WavePlot : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int interval READ getInterval WRITE setInterval)
    Q_PROPERTY(double waterHeight READ getWaterHeight WRITE setWaterHeight)
    Q_PROPERTY(double waterDensity READ getWaterDensity WRITE setWaterDensity)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

public:
    explicit WavePlot(QWidget *parent = 0);
    ~WavePlot();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawLine(QPainter *painter);

private:
    int interval;                   //间隔
    double waterHeight;             //水波高度
    double waterDensity;            //水波密度
    QColor lineColor;               //线条颜色
    QColor bgColor;                 //背景颜色

    double offset;                  //水波偏移量
    QTimer *timer;                  //定时器绘制动画

public:
    int getInterval()               const;
    double getWaterHeight()         const;
    double getWaterDensity()        const;
    QColor getLineColor()           const;
    QColor getBgColor()             const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //启动波动
    void start();
    //停止波动
    void stop();

    //设置波动间隔
    void setInterval(int interval);
    //设置水波高度
    void setWaterHeight(double waterHeight);
    //设置水波密度
    void setWaterDensity(double waterDensity);

    //设置线条颜色
    void setLineColor(const QColor &lineColor);
    //设置背景颜色
    void setBgColor(const QColor &bgColor);
};

#endif // WAVEPLOT_H
