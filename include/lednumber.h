#ifndef LEDNUMBER_H
#define LEDNUMBER_H

/**
 * LED数字控件 作者:feiyangqingyun(QQ:517216493) 2016-10-31
 * 1. 可设置当前数字。
 * 2. 可设置各种颜色。
 */

#include <QWidget>

class NumberObj : public QObject
{
    Q_OBJECT
public:
    NumberObj() {}

    bool hasThisPair(int hCoor, int vCoor) {
        int count = vec.count();

        for (int i = 0; i < count ; i++) {
            if (vec.at(i).first == hCoor &&
                vec.at(i).second == vCoor) {
                return true;
            }
        }

        return false;
    }

    void addPair(int i, int j) {
        vec.append(qMakePair(i, j));
    }

private:
    QVector<QPair<int, int> > vec;
};


#ifdef quc
class Q_DECL_EXPORT LedNumber : public QWidget
#else
class LedNumber : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int number READ getNumber WRITE setNumber)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding)
    Q_PROPERTY(int radius READ getRadius WRITE setRadius)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor numberBgColorStart READ getNumberBgColorStart WRITE setNumberBgColorStart)
    Q_PROPERTY(QColor numberBgColorEnd READ getNumberBgColorEnd WRITE setNumberBgColorEnd)

    Q_PROPERTY(QColor numberColorStart READ getNumberColorStart WRITE setNumberColorStart)
    Q_PROPERTY(QColor numberColorEnd READ getNumberColorEnd WRITE setNumberColorEnd)

public:
    explicit LedNumber(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawNumberBg(QPainter *painter);
    void drawNumber(QPainter *painter);

private:
    int number;                     //目标值
    int space;                      //间距
    int padding;                    //数字的间隔
    int radius;                     //圆角角度

    QColor bgColorStart;            //背景渐变开始颜色
    QColor bgColorEnd;              //背景渐变结束颜色

    QColor numberBgColorStart;      //无数字背景渐变开始颜色
    QColor numberBgColorEnd;        //无数字背景渐变结束颜色

    QColor numberColorStart;        //数字渐变开始颜色
    QColor numberColorEnd;          //数字渐变结束颜色

    NumberObj *zero, *one, *two, *three, *four, *five, *six, *seven, *eight, *nine;

private:
    void addNum(NumberObj *numberObj, int i, int j);
    void drawNum(NumberObj *numberObj, int i, int j, QPainter *painter);

public:
    int getNumber()                 const;
    int getSpace()                  const;
    int getPadding()                const;
    int getRadius()                 const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;

    QColor getNumberBgColorStart()  const;
    QColor getNumberBgColorEnd()    const;

    QColor getNumberColorStart()    const;
    QColor getNumberColorEnd()      const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置值
    void setNumber(int number);
    //设置间距
    void setSpace(int space);
    //设置数字间的间隔
    void setPadding(int padding);
    //设置圆角角度
    void setRadius(int radius);

    //设置背景颜色
    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);

    //设置无数字颜色
    void setNumberBgColorStart(const QColor &numberBgColorStart);
    void setNumberBgColorEnd(const QColor &numberBgColorEnd);

    //设置数字颜色
    void setNumberColorStart(const QColor &numberColorStart);
    void setNumberColorEnd(const QColor &numberColorEnd);

};

#endif // LEDNUMBER_H
