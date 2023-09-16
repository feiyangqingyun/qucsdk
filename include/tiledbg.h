#ifndef TILEDBG_H
#define TILEDBG_H

/**
 * 平铺背景控件 作者:feiyangqingyun(QQ:517216493) 2018-08-25
 * 1. 可设置交替背景颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT TiledBg : public QWidget
#else
class TiledBg : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor color1 READ getColor1 WRITE setColor1)
    Q_PROPERTY(QColor color2 READ getColor2 WRITE setColor2)
    Q_PROPERTY(QPixmap bgPix READ getBgPix WRITE setBgPix)

public:
    explicit TiledBg(QWidget *parent = 0);

protected:
    void drawBg();
    void paintEvent(QPaintEvent *);

private:
    QColor color1;      //颜色1
    QColor color2;      //颜色2
    QPixmap bgPix;      //背景图片

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置颜色1
    QColor getColor1() const;
    void setColor1(const QColor &color1);

    //获取和设置颜色2
    QColor getColor2() const;
    void setColor2(const QColor &color2);

    //获取和设置背景图片
    QPixmap getBgPix() const;
    void setBgPix(const QPixmap &bgPix);
};

#endif // TILEDBG_H
