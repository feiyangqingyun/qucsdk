#ifndef COLORSTYLE_H
#define COLORSTYLE_H

/**
 * 颜色样式选择控件 作者:feiyangqingyun(QQ:517216493) 2017-09-10
 * 1. 可设置背景颜色。
 * 2. 可设置角标颜色。
 * 3. 可设置角标大小。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ColorStyle : public QWidget
#else
class ColorStyle : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor signColor READ getSignColor WRITE setSignColor)
    Q_PROPERTY(int signSize READ getSignSize WRITE setSignSize)
    Q_PROPERTY(bool checked READ getChecked WRITE setChecked)
    Q_PROPERTY(bool hovered READ getHovered WRITE setHovered)

public:
    explicit ColorStyle(QWidget *parent = 0);

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawSign(QPainter *painter);

private:
    QColor bgColor;             //背景颜色
    QColor signColor;           //选中符号颜色
    int signSize;               //选中符号大小
    bool checked;               //是否选中
    bool hovered;               //是否永久悬停

    QFont iconFont;             //图形字体
    bool hover;                 //当前是否悬停

public:
    QColor getBgColor()         const;
    QColor getSignColor()       const;
    int getSignSize()           const;
    bool getChecked()           const;
    bool getHovered()           const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置背景颜色
    void setBgColor(const QColor &bgColor);

    //设置角标颜色
    void setSignColor(const QColor &signColor);

    //设置角标大小
    void setSignSize(int signSize);

    //设置是否选中
    void setChecked(bool checked);

    //设置是否永久悬停
    void setHovered(bool hovered);

Q_SIGNALS:
    //当前选中发送颜色值
    void selected(const QColor &bgColor);

};

#endif // COLORSTYLE_H
