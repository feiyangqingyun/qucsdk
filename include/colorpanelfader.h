#ifndef COLORPANELFADER_H
#define COLORPANELFADER_H

/**
 * 颜色滑块面板 作者:feiyangqingyun(QQ:517216493) 2017-11-17
 * 1. 可设置滑块条之间的间隔。
 * 2. 可设置滑块组之间的间隔。
 * 3. 可设置背景颜色。
 */

#include <QWidget>

class QHBoxLayout;
class QSpacerItem;
class ColorPanelBar;

#ifdef quc
class Q_DECL_EXPORT ColorPanelFader : public QWidget
#else
class ColorPanelFader : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int barSpace READ getBarSpace WRITE setBarSpace)
    Q_PROPERTY(int groupSpace READ getGroupSpace WRITE setGroupSpace)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

public:
    explicit ColorPanelFader(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void paintEvent(QPaintEvent *);

private:
    QHBoxLayout *layout;
    QSpacerItem *spacer1;
    QSpacerItem *spacer2;
    QList<ColorPanelBar *> items;

    int barSpace;               //柱状条间隔
    int groupSpace;             //分组间隔
    QColor bgColor;             //背景颜色

private slots:
    void colorChanged(const QColor &color, double value, double percent);

public:
    int getBarSpace()           const;
    int getGroupSpace()         const;
    QColor getBgColor()         const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public:
    //设置柱状条间隔
    void setBarSpace(int barSpace);
    //设置分组间隔
    void setGroupSpace(int groupSpace);
    //设置背景颜色
    void setBgColor(const QColor &bgColor);

Q_SIGNALS:
    void colorChanged(const QColor &color, double hue, double sat, double bright);
};

#endif // COLORPANELFADER_H
