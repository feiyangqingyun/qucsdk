#ifndef TUMBLERTIME_H
#define TUMBLERTIME_H

/**
 * 时间滑动选择器 作者:feiyangqingyun(QQ:517216493) 2017-08-11
 * 1. 可设置时分秒。
 * 2. 可鼠标或者手指滑动选择时分秒。
 * 3. 支持自定义数值范围。
 * 4. 支持鼠标滚轮选择。
 */

#include <QWidget>
#include <QDateTime>

class Tumbler;
class TumblerTime;

#ifdef quc
class Q_DECL_EXPORT TumblerTime : public QWidget
#else
class TumblerTime : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TumblerTime(QWidget *parent = 0);

private:
    int hour;               //时钟
    int min;                //分钟
    int sec;                //秒钟

    Tumbler *tumblerHour;   //时钟选择器
    Tumbler *tumblerMin;    //分钟选择器
    Tumbler *tumblerSec;    //秒钟选择器

private slots:
    void initForm();

public:
    //获取时钟
    int getHour()           const;
    //获取分钟
    int getMin()            const;
    //获取秒钟
    int getSec()            const;

    //获取时间
    QTime getTime()         const;

public Q_SLOTS:
    //设置时钟
    void setHour(int hour);

    //设置分钟
    void setMin(int min);

    //设置秒钟
    void setSec(int sec);

    //设置年月日
    void setTime(int hour, int min, int sec);

};

#endif // TUMBLERTIME_H
