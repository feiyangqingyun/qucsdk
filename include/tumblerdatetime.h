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
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置年份
    int getYear() const;
    void setYear(int year);

    //获取和设置月份
    int getMonth() const;
    void setMonth(int month);

    //获取和设置日期
    int getDay() const;
    void setDay(int day);

    //获取和设置时钟
    int getHour() const;
    void setHour(int hour);

    //获取和设置分钟
    int getMin() const;
    void setMin(int min);

    //获取和设置秒钟
    int getSec() const;
    void setSec(int sec);

    //获取和设置日期时间
    QDateTime getDateTime() const;
    void setDateTime(int year, int month, int day, int hour, int min, int sec);
};

#endif // TUMBLERDATETIME_H
