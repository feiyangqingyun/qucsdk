#ifndef TUMBLERDATETIME_H
#define TUMBLERDATETIME_H

/**
 * 日期时间滑动选择器 作者:feiyangqingyun(QQ:517216493) 2017-08-11
 * 1. 可设置年月日时分秒。
 * 2. 可鼠标或者手指滑动选择年月日时分秒。
 * 3. 支持自定义数值范围。
 * 4. 支持鼠标滚轮选择。
 * 5. 年月日自动联动计算。
 */

#include <QWidget>
#include <QDateTime>

class Tumbler;
class TumblerDateTime;

#ifdef quc
class Q_DECL_EXPORT TumblerDateTime : public QWidget
#else
class TumblerDateTime : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TumblerDateTime(QWidget *parent = 0);

private:
    int year;               //年份
    int month;              //月份
    int day;                //日期
    int hour;               //时钟
    int min;                //分钟
    int sec;                //秒钟

    Tumbler *tumblerYear;   //年份选择器
    Tumbler *tumblerMonth;  //月份选择器
    Tumbler *tumblerDay;    //日期选择器
    Tumbler *tumblerHour;   //时钟选择器
    Tumbler *tumblerMin;    //分钟选择器
    Tumbler *tumblerSec;    //秒钟选择器

private slots:
    void initForm();
    void currentValueChanged(const QString &);

public:
    //获取年份
    int getYear()           const;
    //获取月份
    int getMonth()          const;
    //获取日期
    int getDay()            const;

    //获取时钟
    int getHour()           const;
    //获取分钟
    int getMin()            const;
    //获取秒钟
    int getSec()            const;

public Q_SLOTS:
    //设置年份
    void setYear(int year);

    //设置月份
    void setMonth(int month);

    //设置日期
    void setDay(int day);

    //设置时钟
    void setHour(int hour);

    //设置分钟
    void setMin(int min);

    //设置秒钟
    void setSec(int sec);

    //设置年月日
    void setDateTime(int year, int month, int day, int hour, int min, int sec);
};

#endif // TUMBLERDATETIME_H
