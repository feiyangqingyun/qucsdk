#ifndef COLORPANELHSB_H
#define COLORPANELHSB_H

/**
 * 颜色选取面板 作者:feiyangqingyun(QQ:517216493) 2017-11-17
 * 1. 可设置当前百分比，用于控制指针大小。
 * 2. 可设置边框宽度。
 * 3. 可设置边框颜色。
 * 4. 可设置指针颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ColorPanelHSB : public QWidget
#else
class ColorPanelHSB : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int percent READ getPercent WRITE setPercent)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor cursorColor READ getCursorColor WRITE setCursorColor)

    Q_PROPERTY(QColor color READ getColor)
    Q_PROPERTY(double hue READ getHue)
    Q_PROPERTY(double sat READ getSat)

public:
    explicit ColorPanelHSB(QWidget *parent = 0);

protected:
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawCursor(QPainter *painter);
    void drawBorder(QPainter *painter);

private:
    int percent;                //当前百分比
    int borderWidth;            //边框宽度
    QColor borderColor;         //边框颜色
    QColor cursorColor;         //鼠标按下处的文字形状颜色

    QColor color;               //鼠标按下处的颜色
    double hue;                 //hue值
    double sat;                 //sat值

    QPoint lastPos;             //最后鼠标按下去的坐标
    QPixmap bgPix;              //背景颜色图片

public:
    int getPercent()            const;
    QColor getBorderColor()     const;
    QColor getCursorColor()     const;

    QColor getColor()           const;
    double getHue()             const;
    double getSat()             const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置百分比
    void setPercent(int percent);

    //设置边框颜色
    void setBorderColor(const QColor &borderColor);

    //设置文字形状颜色
    void setCursorColor(const QColor &cursorColor);

Q_SIGNALS:
    void colorChanged(const QColor &color, double hue, double sat);

};

#endif // COLORPANELHSB_H
