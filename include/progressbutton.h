#ifndef PROGRESSBUTTON_H
#define PROGRESSBUTTON_H

/**
 * 按钮进度条控件 作者:倪大侠(QQ:393320854) 2019-04-17
 * 1. 可设置进度线条宽度、颜色。
 * 2. 可设置边框宽度、颜色。
 * 3. 可设置圆角角度、背景颜色。
 * 4. 可设置文字颜色
 */

#include <QWidget>

class QTimer;

#ifdef quc
class Q_DECL_EXPORT ProgressButton : public QWidget
#else
class ProgressButton : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit ProgressButton(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawProgress(QPainter *painter);

private:
    int lineWidth;          //线条宽度
    QColor lineColor;       //线条颜色

    int borderRadius;       //圆角角度
    int borderWidth;        //边框宽度
    QColor borderColor;     //边框颜色

    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色

    double value;           //当前值
    int status;             //状态
    int tempWidth;          //动态改变宽度
    QTimer *timer;          //定时器改变进度

private slots:
    void progress();        //执行进度

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置线条宽度
    int getLineWidth() const;
    void setLineWidth(int lineWidth);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置边框圆角
    int getBorderRadius() const;
    void setBorderRadius(int borderRadius);

    //获取和设置边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif // PROGRESSBUTTON_H
