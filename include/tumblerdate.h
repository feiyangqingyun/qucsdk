#ifndef TUMBLERDATE_H
#define TUMBLERDATE_H

/**
 * 日期滑动选择器 作者:feiyangqingyun(QQ:517216493) 2017-08-11
 * 1. 可设置年月日。
 * 2. 可鼠标或者手指滑动选择年月日。
 * 3. 支持自定义数值范围。
 * 4. 支持鼠标滚轮选择。
 * 5. 年月日自动联动计算。
 */

#include <QWidget>
#include <QDateTime>

class Tumbler;
class TumblerDate;

#ifdef quc
class Q_DECL_EXPORT TumblerDate : public QWidget
#else
class TumblerDate : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TumblerDate(QWidget *parent = 0);

private:
    int year;               //年份
    int month;              //月份
    int day;                //日期

    Tumbler *tumblerYear;   //年份选择器
    Tumbler *tumblerMonth;  //月份选择器
    Tumbler *tumblerDay;    //日期选择器

private slots:
    void initForm();
    void currentValueChanged(const QString &);

public:
    //获取和设置年份
    int getYear() const;
    void setYear(int year);

    //获取和设置月份
    int getMonth() const;
    void setMonth(int month);

    //获取和设置日期
    int getDay() const;
    void setDay(int day);

    //获取和设置日期
    QDate getDate() const;
    void setDate(int year, int month, int day);
};

#endif // TUMBLERDATE_H
