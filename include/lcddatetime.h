#ifndef LCDDATETIME_H
#define LCDDATETIME_H

/**
 * 当前时间LCD控件 作者:feiyangqingyun(QQ:517216493) 2016-11-25
 * 1. 可设置时间字符串格式。
 * 2. 可设置中间点分隔符是否闪烁。
 * 3. 可实时显示当前时间。
 */

#include <QLCDNumber>

#ifdef quc
class Q_DECL_EXPORT LcdDateTime : public QLCDNumber
#else
class LcdDateTime : public QLCDNumber
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool dotHide READ getDotHide WRITE setDotHide)
    Q_PROPERTY(QString format READ getFormat WRITE setFormat)

public:
    explicit LcdDateTime(QWidget *parent = 0);
    ~LcdDateTime();

private:
    bool dotHide;       //点隐藏
    QString format;     //时间格式
    int digitCount;     //数字长度

    bool isHide;        //隐藏
    QTimer *timer;      //定时器切换隐藏

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置点是否隐藏
    bool getDotHide() const;
    void setDotHide(bool dotHide);

    //获取和设置时间格式
    QString getFormat() const;
    void setFormat(const QString &format);

public Q_SLOTS:
    //启动服务
    void start(int interval = 1000);
    //设置当前时间
    void setDateTime();
};

#endif // LCDDATETIME_H
