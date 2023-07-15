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
    int getNumber()                 const;
    int getSpace()                  const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;

    QColor getNumberColorStart()    const;
    QColor getNumberColorEnd()      const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置值
    void setNumber(int number);
    //设置间距
    void setSpace(int space);

    //设置背景颜色
    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);

    //设置数字颜色
    void setNumberColorStart(const QColor &numberColorStart);
    void setNumberColorEnd(const QColor &numberColorEnd);
};

#endif // LCDNUMBER_H
