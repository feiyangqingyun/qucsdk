#ifndef LCDNUMBER_H
#define LCDNUMBER_H

/**
 * LCD数字控件 作者:feiyangqingyun(QQ:517216493) 2016-10-31
 * 1. 可设置目标值和间隔。
 * 2. 可设置背景颜色和数字颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT LcdNumber : public QWidget
#else
class LcdNumber : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int number READ getNumber WRITE setNumber)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor numberColorStart READ getNumberColorStart WRITE setNumberColorStart)
    Q_PROPERTY(QColor numberColorEnd READ getNumberColorEnd WRITE setNumberColorEnd)

public:
    explicit LcdNumber(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawNumber(QPainter *painter);

private:
    int number;             //目标值
    int space;              //间距

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色

    QColor numberColorStart;//数字渐变开始颜色
    QColor numberColorEnd;  //数字渐变结束颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置值
    int getNumber() const;
    void setNumber(int number);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置背景开始颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    //获取和设置背景结束颜色
    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置数字开始颜色
    QColor getNumberColorStart() const;
    void setNumberColorStart(const QColor &numberColorStart);

    //获取和设置数字结束颜色
    QColor getNumberColorEnd() const;
    void setNumberColorEnd(const QColor &numberColorEnd);
};

#endif // LCDNUMBER_H
