#ifndef TUMBLER_H
#define TUMBLER_H

/**
 * 滑动选择器控件 作者:feiyangqingyun(QQ:517216493) 2016-11-24
 * 1. 可设置数据队列值。
 * 2. 可设置当前队列索引及当前值。
 * 3. 支持任意窗体大小缩放。
 * 4. 支持背景色前景色文字颜色线条颜色设置。
 * 5. 支持左右滑动和上下滑动两种形式。
 * 6. 支持鼠标滚动切换元素。
 * 7. 中间值自动放大显示且居中。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT Tumbler : public QWidget
#else
class Tumbler : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int currentIndex READ getCurrentIndex WRITE setCurrentIndex)
    Q_PROPERTY(QString currentValue READ getCurrentValue WRITE setCurrentValue)
    Q_PROPERTY(bool horizontal READ getHorizontal WRITE setHorizontal)

    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit Tumbler(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawText(QPainter *painter, int index, int offset);

private:
    QStringList listValue;  //值队列
    int currentIndex;       //当前索引
    QString currentValue;   //当前值
    bool horizontal;        //是否横向显示

    QColor foreground;      //前景色
    QColor background;      //背景色
    QColor lineColor;       //线条颜色
    QColor textColor;       //当前文本颜色

    int percent;            //比例
    int offset;             //偏离值
    bool pressed;           //鼠标是否按下
    int pressedPos;         //按下处坐标
    int currentPos;         //当前值对应起始坐标

private:
    void checkPosition();   //检验位置

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置值队列
    QStringList getListValue() const;
    void setListValue(const QStringList &listValue);

    //获取和设置当前索引
    int getCurrentIndex() const;
    void setCurrentIndex(int currentIndex);

    //获取和设置当前值
    QString getCurrentValue() const;
    void setCurrentValue(const QString &currentValue);

    //获取和设置横向显示(如果为假则纵向显示)
    bool getHorizontal() const;
    void setHorizontal(bool horizontal);

    //获取和设置前景色
    QColor getForeground() const;
    void setForeground(const QColor &foreground);

    //获取和设置背景色
    QColor getBackground() const;
    void setBackground(const QColor &background);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

Q_SIGNALS:
    void currentIndexChanged(int currentIndex);
    void currentValueChanged(QString currentValue);
};

#endif // TUMBLER_H
