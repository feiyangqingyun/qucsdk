#ifndef COLORPANELBTN_H
#define COLORPANELBTN_H

/**
 * 颜色按钮面板 作者:feiyangqingyun(QQ:517216493) 2017-11-17
 * 1. 可设置颜色集合。
 * 2. 可设置按钮圆角角度。
 * 3. 可设置列数。
 * 4. 可设置按钮边框宽度和边框颜色。
 */

#include <QWidget>

class QGridLayout;
class QPushButton;

#ifdef quc
class Q_DECL_EXPORT ColorPanelBtn : public QWidget
#else
class ColorPanelBtn : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int space READ getSpace WRITE setSpace)
    Q_PROPERTY(int columnCount READ getColumnCount WRITE setColumnCount)
    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

public:
    explicit ColorPanelBtn(QWidget *parent = 0);

private:
    QGridLayout *gridLayout;
    QList<QPushButton *> btns;
    QStringList colors;

    int space;                  //按钮之间的间隔
    int columnCount;            //按钮列数
    int borderRadius;           //边框圆角
    int borderWidth;            //边框宽度
    QColor borderColor;         //边框颜色

private slots:
    void initStyle();
    void initBtn();
    void btnClicked();

public:
    QStringList getColors()     const;

    int getSpace()              const;
    int getColumnCount()        const;
    int getBorderRadius()       const;
    int getBorderWidth()        const;
    QColor getBorderColor()     const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置颜色集合
    void setColors(const QStringList &colors);

    //设置按钮间隔
    void setSpace(int space);

    //设置列数
    void setColumnCount(int columnCount);

    //设置圆角角度
    void setBorderRadius(int borderRadius);

    //设置边框宽度
    void setBorderWidth(int borderWidth);

    //设置边框颜色
    void setBorderColor(const QColor &borderColor);

Q_SIGNALS:
    void colorChanged(const QColor &color);

};

#endif // COLORPANELBTN_H
