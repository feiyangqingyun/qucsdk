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
    int interval;           //间隔
    double waterHeight;     //水波高度
    double waterDensity;    //水波密度
    QColor lineColor;       //线条颜色
    QColor bgColor;         //背景颜色

    double offset;          //水波偏移量
    QTimer *timer;          //定时器绘制动画

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置波动间隔
    int getInterval() const;
    void setInterval(int interval);

    //获取和设置水波高度
    double getWaterHeight() const;
    void setWaterHeight(double waterHeight);

    //获取和设置水波密度
    double getWaterDensity() const;
    void setWaterDensity(double waterDensity);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

public Q_SLOTS:
    //启动波动
    void start();
    //停止波动
    void stop();
};

#endif // WAVEPLOT_H
