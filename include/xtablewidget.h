#ifndef XTABLEWIDGET_H
#define XTABLEWIDGET_H

/**
 * 整行选中表格控件 作者:feiyangqingyun(QQ:517216493) 2018-5-10
 * 1. 鼠标滑过自动选中整行。
 * 2. 可设置鼠标滑过背景颜色。
 * 3. 可设置鼠标滑过文字颜色。
 */

#include <QTableWidget>

#ifdef quc
class Q_DECL_EXPORT XTableWidget : public QTableWidget
#else
class XTableWidget : public QTableWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor hoverBgColor READ getHoverBgColor WRITE setHoverBgColor)
    Q_PROPERTY(QColor hoverTextColor READ getHoverTextColor WRITE setHoverTextColor)

public:
    explicit XTableWidget(QWidget *parent = 0);

protected:
    void leaveEvent(QEvent *);

private slots:
    void cellEntered(int row, int column);
    void setRowColor(int row, const QColor &bgColor, const QColor &textColor);

private:
    int previousRow;        //上一行
    QColor textColor;       //文字颜色
    QColor hoverBgColor;    //鼠标滑过背景颜色
    QColor hoverTextColor;  //鼠标滑过文字颜色

public:
    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &color);

    //获取和设置鼠标滑过背景颜色
    QColor getHoverBgColor() const;
    void setHoverBgColor(const QColor &color);

    //获取和设置鼠标滑过文字颜色
    QColor getHoverTextColor() const;
    void setHoverTextColor(const QColor &color);
};

#endif // XTABLEWIDGET_H
