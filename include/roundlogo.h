#ifndef ROUNDLOGO_H
#define ROUNDLOGO_H

/**
 * 旋转logo控件 作者:东门吹雪(QQ:709102202) 整理:飞扬青云(QQ:517216493) 2019-04-23
 * 1. 可设置旋转速度。
 * 2. 可设置背景颜色。
 * 3. 可设置logo的子颜色。
 * 4. 可设置花瓣个数。
 * 5. 可设置圆形间距。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RoundLogo : public QWidget
#else
class RoundLogo : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

public:
    explicit RoundLogo(QWidget *parent = 0);
    ~RoundLogo();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawLogo(QPainter *painter);
    double TwoPtDistance(const QPointF &pt1, const QPointF &pt2);

private slots:
    void updateValue();

private:
    int speed;                  //旋转速度
    QColor bgColor;             //背景颜色
    QList<QColor> colors;       //颜色集合

    int value;                  //当前值
    QTimer *timer;              //定时器绘制

public:
    int getSpeed()              const;
    QColor getBgColor()         const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置速度
    void setSpeed(int speed);

    //设置颜色
    void setBgColor(const QColor &bgColor);
    void setColors(const QList<QColor> &colors);

    //启动+停止旋转
    void start();
    void stop();
};

#endif // GAUGEPOWER_H
