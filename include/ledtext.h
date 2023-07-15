#ifndef LEDTEXT_H
#define LEDTEXT_H

/**
 * 字模提取控件 作者:feiyangqingyun(QQ:517216493) 2016-11-17
 * 1. 可设置字模文字。
 * 2. 可设置字体名称及字号。
 * 3. 可设置步长间隔。
 * 4. 可设置前景色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT LedText : public QWidget
#else
class LedText : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QString text READ getText WRITE setText)
    Q_PROPERTY(int step READ getStep WRITE setStep)

    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)

public:
    explicit LedText(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    QString text;                   //文字
    int step;                       //步长

    QColor foreground;              //前景色
    QColor background;              //背景色

public:
    QString getText()               const;
    int getStep()                   const;

    QColor getForeground()          const;
    QColor getBackground()          const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置字模信息
    void setText(const QString &text);
    void setStep(int step);

    //设置前景色
    void setForeground(const QColor &foreground);
    //设置背景色
    void setBackground(const QColor &background);
};

#endif // LEDTEXT_H
