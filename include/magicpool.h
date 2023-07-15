#ifndef MAGICPOOL_H
#define MAGICPOOL_H

/**
 * 魔幻水池控件 作者:feiyangqingyun(QQ:517216493) 2018-07-15
 * 1. 可设置最大半径。
 * 2. 可设置边框大小、边框颜色。
 * 3. 可设置背景颜色。
 */

#include <QWidget>

class MagicFish;

#ifdef quc
class Q_DECL_EXPORT MagicPool : public QWidget
#else
class MagicPool : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int maxRadius READ getMaxRadius WRITE setMaxRadius)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

public:
    explicit MagicPool(QWidget *parent = 0);
    ~MagicPool();

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:
    int maxRadius;              //最大半径
    int borderWidth;            //边框大小
    QColor borderColor;         //边框颜色
    QColor bgColor;             //背景颜色

    bool startDraw;             //开始绘制
    int currentRadius;          //当前半径

    QPoint posPress;            //按下处的坐标
    QTimer *timerUpdate;        //绘制定时器

private slots:
    void updateValue();

public:
    int getMaxRadius()          const;
    int getBorderWidth()        const;
    QColor getBorderColor()     const;
    QColor getBgColor()         const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置最大半径
    void setMaxRadius(int maxRadius);
    //设置边框宽度
    void setBorderWidth(int borderWidth);
    //设置边框颜色
    void setBorderColor(const QColor &borderColor);
    //设置背景颜色
    void setBgColor(const QColor &bgColor);
};

#endif // MAGICPOOL_H
