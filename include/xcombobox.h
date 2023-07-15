#ifndef XCOMBOBOX_H
#define XCOMBOBOX_H

/**
 * 自定义宽高下拉框控件 作者:feiyangqingyun(QQ:517216493) 2017-04-11
 * 1. 可设置下拉框元素高度。
 * 2. 可设置下拉框元素宽度。
 * 3. 可设置是否自动调整下拉框元素宽度，根据元素宽高自动调整。
 */

#include <QComboBox>

#ifdef quc
class Q_DECL_EXPORT XComboBox : public QComboBox
#else
class XComboBox : public QComboBox
#endif

{
    Q_OBJECT

    Q_PROPERTY(int itemWidth READ getItemWidth WRITE setItemWidth)
    Q_PROPERTY(int itemHeight READ getItemHeight WRITE setItemHeight)
    Q_PROPERTY(bool autoWidth READ getAutoWidth WRITE setAutoWidth)

public:
    explicit XComboBox(QWidget *parent = 0);

protected:
    void showEvent(QShowEvent *);

private:
    int itemWidth;                  //元素宽度
    int itemHeight;                 //元素高度
    bool autoWidth;                 //是否自动调整元素宽度
    int maxItemWidth;               //最大元素宽度

public:
    int getItemWidth()              const;
    int getItemHeight()             const;
    bool getAutoWidth()             const;

public Q_SLOTS:
    void setItemWidth(int itemWidth);
    void setItemHeight(int itemHeight);
    void setAutoWidth(bool autoWidth);
};

#endif // XCOMBOBOX_H
